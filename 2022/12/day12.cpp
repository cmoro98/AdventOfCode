#include <cassert>
#include <climits>
#include <fstream>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../../competitivelib/competitive.hpp"

#define UNVISITED -1
#define VISITED 1

bool valid_step(char i_am, char i_go) {
	if (i_go == 'E') {
		i_go = 'z';
	}
	return (i_am >= i_go) or (int) i_am + 1 == (int)i_go;
}
struct nodo_t : sct::point {
	nodo_t(const int& x, const int& y) : sct::point(x, y){};
	int cost{0};
};

std::vector<int> dr = {1, 0, -1, 0};  // S, E N, O
std::vector<int> dc = {0, 1, 0, -1};

nodo_t bfs(nodo_t& n,const std::vector<std::string>& graph, std::vector<std::vector<int>>& visited) {
	std::queue<nodo_t> q;
	q.push(n);
	while (!q.empty()) {
		nodo_t nodo(q.front());
		char current_value = graph[nodo.x][nodo.y];
		q.pop();
		// loop through neighbors
		for (int i = 0; i < 4; i++) {
			nodo_t new_node = {nodo.x + dr[i], nodo.y + dc[i]};
			if (!(new_node.x < 0 or new_node.x >= graph.size() or new_node.y < 0 or new_node.y >= graph[0].size())) {
				char next_step_value = graph[new_node.x][new_node.y];
				if (valid_step(current_value, next_step_value) && visited[new_node.x][new_node.y] == UNVISITED) {
					visited[new_node.x][new_node.y] = VISITED;
					new_node.cost = nodo.cost + 1;
					if (next_step_value == 'E') {  // FOUNDED
						return new_node;
					}
					q.push(new_node);
				}
			}
		}
	}
	return {-1, -1};
}

int day12() {
	std::ifstream infile("input.txt");
	// assert(valid_step('a','a'));
	// assert(valid_step('b','a'));
	// assert(valid_step('a','b'));
	// assert(valid_step('a','c'));
	// assert(valid_step('y','E'));

	std::string line;

	std::vector<std::string> heightmap;

	while (std::getline(infile, line)) {
		heightmap.push_back(line);
	}
	nodo_t start_node = {0, 0};
	std::vector<nodo_t> star_2_nodes_with_a;

	for (size_t i = 0; i < heightmap.size(); i++) {
		for (size_t j = 0; j < heightmap[i].size(); j++) {
			if (heightmap[i][j] == 'S') {
				start_node = {i, j};
				heightmap[i][j] = 'a';
			}
			if (heightmap[i][j] == 'a') {
				star_2_nodes_with_a.push_back({i, j});
			}
		}
	}

	std::vector<std::vector<int>> visited(heightmap.size(), std::vector<int>(heightmap[0].size(), -1));
	nodo_t ret = bfs(start_node, heightmap, visited);

	std::cout << "Star_1: " << ret.cost << std::endl;

	// Star  2 lets try simple brute force
	int min = ret.cost;
	for (size_t i = 0; i < star_2_nodes_with_a.size(); i++) {
		std::vector<std::vector<int>> visited(heightmap.size(), std::vector<int>(heightmap[0].size(), -1));
		start_node = star_2_nodes_with_a[i];
		nodo_t node = bfs(start_node, heightmap, visited);
		if (node.x == -1) {
			continue;
		}
		min = (node.cost < min) ? node.cost : min;
	}
	std::cout << "Star_2: " << min << std::endl;

	return 0;
}

int main() {
	day12();
	return 0;
}