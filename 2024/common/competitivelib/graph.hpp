#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
namespace sct{


/*
This is a series of typical
algorithms that you may need.

WARNING, this is not generic but you should be able to
tranform in your specific solution in short time.
*/

#define UNVISITED -1
#define VISITED 1


/*
@param n -> nodo inicial.
@param adjList -> Lista de adyacencia. 
@param dfs_num-> vector con tantos elementos como nodos. Inicialmente todos los nodos estan
UNVISITED y según vamos pasando por ellos los marcamos como VISITED. Para así no entrar
EN bucles infinitos.
*/
void dfs(int n, 
         std::unordered_map<int, std::vector<int>>& adjList,
         std::vector<int>& dfs_num)
{
    dfs_num[n] = VISITED;
    // loop trough neighbors
    for(int i = 0; i < adjList[n].size();i++){
        
        if(adjList[n][i]==UNVISITED){
            dfs(adjList[n][i],adjList,dfs_num);
        }
    }

}

/*
BFS en la que también vamos a guardar la capa.
*/
void bfs(int n,std::unordered_map<int, std::vector<int>>& adjList )
{
    std::vector<int> d(adjList.size(),INT_MAX);
    d[n]=0;
    std::queue<int> q;
    q.push(n);
    while(q.empty())
    {
        int nodo = q.front();
        q.pop();
        // loop through neighbors
        for(int i = 0; i < adjList[nodo].size();i++){
        
            if(adjList[nodo][i]==INT_MAX){
                d[adjList[nodo][i]]= d[nodo]+1;
                q.push(adjList[nodo][i]);
            }
        }
    }
}



/*
Grafos Bipartitos.
http://wiki.oia.unsam.edu.ar/algoritmos-oia/grafos/grafos-bipartitos
*/
bool bfs_bipartite(int n, std::vector<std::vector<int>>& graph, std::vector<int>& color) {
	int colores[2] = {0, 1};
	int color_capa;
	color[n] = colores[0];
	std::queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int nodo = q.front();

		q.pop();

		// loop through neighbors
		for (int i = 0; i < graph[nodo].size(); i++) {
			int neigbour_node = graph[nodo][i];
			if (color[neigbour_node] == color[nodo]) {
				// std::cout << "conflicto nodo: " << nodo
				//           << "  neighbour nodo: "<< neigbour_node;
				return false;
			}
			if (color[neigbour_node] == INT_MAX) {
				//std::cout << " add: " << neigbour_node << " color: " << color_capa << ";";
				if (color[nodo] == 0) {
					color_capa = 1;
				} else {
					color_capa = 0;
				}
				color[neigbour_node] = color_capa;
				q.push(neigbour_node);
			}
		}
		//std::cout << "\n";
	}
	return true;
}

bool isBipartite(std::vector<std::vector<int>>& graph) {
	std::vector<int> d(graph.size(), INT_MAX);
	bool ISbipartite = true;
	for (int i = 0; i < graph.size(); i++) {
		if (d[i] != INT_MAX) continue;
		if (bfs_bipartite(i, graph, d) == false) return false;
	}
	return true;
}




// MST


// Prim algorithm



}// namespace sct