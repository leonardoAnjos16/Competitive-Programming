#include <bits/stdc++.h>

using namespace std;

#define MAX 100

typedef pair<int, int> int_pair;
typedef pair<int, int_pair> trio;

// Finds representative of vertex
int find(int vertices[], int vertex) {
    if (vertices[vertex] == vertex) return vertex;
    vertices[vertex] = find(vertices, vertices[vertex]);
    return vertices[vertex];
}

// Joins graph components that contain vertex_1 and vertex_2 
void unite(int vertices[], int vertex_1, int vertex_2) {
    vertices[find(vertices, vertex_2)] = find(vertices, vertex_1);
}

// Finds minimum spanning tree using edges
int kruskal(vector<trio> edges, int used_edges[], int num_vertices) {
    int disjoint_subset[MAX];
    for (int i = 0; i < num_vertices; i++)
        disjoint_subset[i] = i;

    int num_MST = num_vertices, num_edges = edges.size();
    int counter = -1, cost = 0;
    while (num_MST > 1 && ++counter < num_edges) {
        trio edge = edges[counter];
        int vertex_1 = edge.second.first;
        int vertex_2 = edge.second.second;

        if (edge.first != -1 && find(disjoint_subset, vertex_1) != find(disjoint_subset, vertex_2)) {
            unite(disjoint_subset, vertex_1, vertex_2);
            used_edges[num_vertices - num_MST] = counter;
            cost += edge.first;
            num_MST--;
        }
    }

    if (counter >= num_edges) return -1;
    else return cost;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_vertices, num_edges;
        scanf("%d %d", &num_vertices, &num_edges);

        vector<int_pair> graph[MAX];
        vector<trio> edges;

        // Assembling the graph and storing edges
        for (int i = 0; i < num_edges; i++) {
            int vertex_1, vertex_2, cost;
            scanf("%d %d %d", &vertex_1, &vertex_2, &cost);

            graph[vertex_1 - 1].push_back({vertex_2 - 1, cost});
            graph[vertex_2 - 1].push_back({vertex_1 - 1, cost});

            if (vertex_1 < vertex_2)
                edges.push_back({cost, {vertex_1 - 1, vertex_2 - 1}});
            else
                edges.push_back({cost, {vertex_2 - 1, vertex_1 - 1}});
        }

        // Sorting edges
        sort(edges.begin(), edges.end());

        // Finding first minimum spanning tree of graph
        int used_edges[MAX];
        int first_cost = kruskal(edges, used_edges, num_vertices);

        // Finding indices of all edges in the minimum spanning tree
        int indices[MAX];
        for (int i = 0; i < num_vertices - 1; i++)
            indices[i] = used_edges[i];

        // Finding next minimum spanning trees
        int second_cost = -1;
        for (int i = 0; i < num_vertices - 1; i++) {
            int weight = edges[indices[i]].first;
            edges[indices[i]].first = -1;

            int cost = kruskal(edges, used_edges, num_vertices);
            if (cost != -1 && (second_cost == -1 || cost < second_cost)) second_cost = cost;

            edges[indices[i]].first = weight;
        }

        printf("%d %d\n", first_cost, second_cost);
    }
}