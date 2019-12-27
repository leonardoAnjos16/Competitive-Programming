#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

typedef pair<int, int> ii;

void dijkstra(vector<ii> graph[], int distances[], int num_vertices, int vertex) {
    bool visited[MAX];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
        distances[i] = -1;
    }

    distances[vertex] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > heap;
    heap.push({0, vertex});

    for (int i = 0; i < num_vertices; i++) {
        do {
            if (heap.empty()) return;
            vertex = heap.top().second;
            heap.pop();
        } while (visited[vertex]);

        visited[vertex] = true;
        int num_edges = graph[vertex].size();

        for (int j = 0; j < num_edges; j++) {
            ii edge = graph[vertex][j];
            int new_distance = distances[vertex] + edge.second;

            if (!visited[edge.first] && (distances[edge.first] == -1 || new_distance < distances[edge.first])) {
                distances[edge.first] = new_distance;
                heap.push({new_distance, edge.first});
            }
        }
    }
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_cities, num_highways, origin, destiny;
        scanf("%d %d %d %d", &num_cities, &num_highways, &origin, &destiny);

        vector<ii> graph[MAX];
        for (int i = 0; i < num_highways; i++) {
            int city_1, city_2, minutes;
            scanf("%d %d %d", &city_1, &city_2, &minutes);

            graph[city_1 - 1].push_back({city_2 - 1, minutes});
            graph[city_2 - 1].push_back({city_1 - 1, minutes});
        }

        int distances[MAX];
        dijkstra(graph, distances, num_cities, origin - 1);

        if (distances[destiny - 1] == -1) printf("NONE\n");
        else printf("%d\n", distances[destiny - 1]);
    }
}