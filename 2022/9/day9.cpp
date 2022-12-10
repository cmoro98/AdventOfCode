#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

#include "../../../competitivelib/competitive.hpp"

using position = sct::point;

position process_head_move(char instruction, position pos) {
	switch (instruction) {
	case 'R':
		pos.x++;
		break;
	case 'L':
		pos.x--;
		break;
	case 'U':
		pos.y++;
		break;
	case 'D':
		pos.y--;
		break;
	default:
		break;
	}
	return pos;
}

position process_tail_move(position head, position tail) {
	if ((head.x - tail.x) == 2) {
		tail.x++;
		tail.y = head.y;
	}
	if ((head.y - tail.y) == 2) {
		tail.y++;
		tail.x = head.x;
	}
	if ((head.x - tail.x) == -2) {
		tail.x--;
		tail.y = head.y;
	}
	if ((head.y - tail.y) == -2) {
		tail.y--;
		tail.x = head.x;
	}

	return tail;
}

// now the ""head"" could also move in diagonal
position new_process_tail_move(position head, position tail) {
	const auto x_distance = head.x - tail.x;
	const auto y_distance = head.y - tail.y;
	// Should we move?
	if ((std::abs(x_distance) <= 1 && std::abs(y_distance) <= 1) == false) {
		tail.x += sct::signum(x_distance);
		tail.y += sct::signum(y_distance);
	}
	return tail;
}
int star_1() {
	std::ifstream infile("input.txt");

	std::vector<std::tuple<char, int>> instructions;

	char i;
	int n;
	while (infile >> i >> n) {
		instructions.push_back({i, n});
	}
	infile.close();

	std::unordered_set<position> visited{{0, 0}};
	position current_position{0, 0};
	position tail_position{0, 0};
	for (const auto& [instruction, positions] : instructions) {
		// std::cout << instruction << " " << positions << std::endl;
		for (size_t i = 0; i < positions; i++) {
			// std::cout << "current_position: " << current_position.y << " " << current_position.x << std::endl;
			current_position = process_head_move(instruction, current_position);
			tail_position = process_tail_move(current_position, tail_position);
			visited.insert(tail_position);
		}
	}
	return visited.size();
}
int star_2(int knots) {
	std::ifstream infile("input.txt");

	std::vector<std::tuple<char, int>> instructions;

	char i;
	int n;
	while (infile >> i >> n) {
		instructions.push_back({i, n});
	}
	infile.close();

	std::unordered_set<position> visited{{0, 0}};
	position current_position{0, 0};

	std::vector<position> snake(knots, {0, 0});
	position tail_position{0, 0};
	for (const auto& [instruction, positions] : instructions) {
		// std::cout << instruction << " " << positions << std::endl;
		for (size_t i = 0; i < positions; i++) {
			// std::cout << "current_position: " << current_position.y << " " << current_position.x << std::endl;
			snake[0] = process_head_move(instruction, snake[0]);
			for (size_t t = 1; t < snake.size(); t++) {
				snake[t] = new_process_tail_move(snake[t - 1], snake[t]);
				/* code */
			}

			visited.insert(snake[snake.size() - 1]);
		}
	}

	return visited.size();
}

int main() {
	std::cout << "Star_1: " << star_1() << std::endl;
	std::cout << "Star_2: " << star_2(10) << std::endl;

	return 0;
}