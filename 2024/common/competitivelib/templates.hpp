/* Templates or ideas that can be usefull */


// BAacktracking
/*
bool is_valid_state(){
    return false;
}

int search(state,solutions){

    if is_valid_state(state){
        solutions.append(state.copy());
        return if we need only onw solution. 
    }

    for candidate in get_candidates(state){
        state.add(candidate);
        search(state, solutions);
        state.remove(candidate)

    }
}

int solve(){
    solutions = [];
    state = set();
    search(state,solutions);
    return soutions;
}

*/



// DFS
/*
Time complexity O(V+E)

#Global scope
n = number of nodes in the graph
g = adjacency list representing the graph
visited = [false, true ...] # size n
void dfs(at){
    if(visited[at]) return;
    visited[at]=true;
    neighbours = graph[at]
    for next in neighbours{
      dfs(next);  
    }
}

#Start dfs at node zero
start_node = 0;
dfs(start_node)
*/


// BIT manipulation
// in g++
    // __builtin_clz(n) : returns no. of bits at the beginning of bit-representation of n
    // __builtin_ctx(n) : returns no. of bits at the beginning of bit-representation of n
    // __builtin_popcount(n) : returns no. of set bits i.e. 1 in bit-representation of n
    // __builtin_parity(n): returns the parity (odd or even) of the set bits i.e. 1 in the beginning of bit-representation of n
