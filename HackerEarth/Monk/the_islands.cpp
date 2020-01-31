#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> ii;
 
vi dijkstra(vector<vi> graph, int num_vertices, int origin = 0) {
    vector<bool> visited(num_vertices, false);
    vi distances(num_vertices, INT_MAX);
    
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push({0, origin});
    
    distances[origin] = 0;
    for (int i = 0; i < num_vertices; i++) {
        int vertex;
        do {
            if (pq.empty()) return distances;
            vertex = pq.top().second, pq.pop();
        } while (visited[vertex]);
        
        visited[vertex] = true;
        for (int j = 0; j < graph[vertex].size(); j++) {
            if (distances[vertex] + 1 < distances[graph[vertex][j]]) {
                distances[graph[vertex][j]] = distances[vertex] + 1;
                pq.push({distances[graph[vertex][j]], graph[vertex][j]});
            }
        }
    }
    
    return distances;
}
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_vertices, num_edges;
        scanf("%d %d", &num_vertices, &num_edges);
        
        vector<vi> graph(num_vertices);
        for (int i = 0; i < num_edges; i++) {
            int vertex_1, vertex_2;
            scanf("%d %d", &vertex_1, &vertex_2);
            
            graph[vertex_1 - 1].push_back(vertex_2 - 1);
            graph[vertex_2 - 1].push_back(vertex_1 - 1);
        }
        
        vi distances = dijkstra(graph, num_vertices);
        printf("%d\n", distances[num_vertices - 1]);
    }
}