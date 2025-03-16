#include "dijkstras.h"

void verify_dijstrkas(){
    Graph G;
    file_to_graph("./src/small.txt", G);
    vector<int> previous(G.size());

    vector<int> paths = dijkstra_shortest_path(G, 0, previous);

    int n = G.numVertices;

    for (int i = 0; i < n; ++i) print_path(extract_shortest_path({}, previous, i), paths[i]);
}

int main(){
    verify_dijstrkas();
}
