#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);

    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({source, 0});

    while(!minHeap.empty()){
        int u = minHeap.top().first;
        minHeap.pop();
        for (const Edge& edge: G[u]){
            visited[u] = true;
            int v = edge.dst;
            int weight = edge.weight;
            if (distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
    // n = G.adjacencyList.size();
    // G.distance.resize(n, INT_MAX);
    // G.previous.resize(n, -1)
    // graph.visited.resize(n, false)

    // priorityQueue pq

    // pq.push(Node(source, 0))

    // graph.distance[source] = 0


    // while !pq.empty():

    //     current = pq.pop_top()


    //     u = current.vertex


    //     if graph.visited[u]:

    //         continue


    //     graph.visited[u] = true


    //     for each neighbor in graph.adjacencyList[u]:

    //         v = neighbor.vertex

    //         weight = neighbor.weight


    //         if !graph.visited[v] and graph.distance[u] + weight < graph.distance[v]:

    //             graph.distance[v] = graph.distance[u] + weight

    //             graph.previous[v] = u

    //             pq.push(Node(v, graph.distance[v]))
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    stack<int> stk;
    while (destination > -1){
        stk.push(destination);
        destination = previous[destination];
    }

    vector<int> res;
    while (!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}
void print_path(const vector<int>& v, int total){
    for (const int& vertex : v) cout << vertex << ' ';
    cout << endl;
    cout << "Total cost is " << total << endl;
}
