#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> connections[], bool visited[], int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < connections[vertex].size(); i++) {
        if (!visited[connections[vertex][i]])
            bfs(connections, visited, connections[vertex][i]);
    }
}

int search(vector<int> connections[]) {
    bool visited[26];
    for (int i = 0; i < 26; i++) visited[i] = false;

    int num_trees = 0;
    for (int i = 0; i < 26; i++) {
        if (!visited[i] && connections[i].size() > 0) {
            bfs(connections, visited, i);
            num_trees++;
        }
    }

    return num_trees;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 0; i < num_cases; i++) {
        vector<int> connections[26];

        char edge[52];
        scanf("%s", edge);
        while (edge[0] != '*') {
            int vertex_1 = edge[1] - 'A';
            int vertex_2 = edge[3] - 'A';

            connections[vertex_1].push_back(vertex_2);
            connections[vertex_2].push_back(vertex_1);

            scanf("%s", edge);
        }

        char vertices[52];
        scanf("%s", vertices);

        int length = strlen(vertices), num_acorns = 0;
        for (int i = 0; i < length; i += 2) {
            int vertex = vertices[i] - 'A';
            if (connections[vertex].size() == 0) num_acorns++;

            connections[vertex].push_back(vertex);
        }

        int num_trees = search(connections) - num_acorns;
        printf("There are %d tree(s) and %d acorn(s).\n", num_trees, num_acorns);
    }
}