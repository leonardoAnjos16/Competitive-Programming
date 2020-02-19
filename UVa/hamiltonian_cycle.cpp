#include <bits/stdc++.h>

using namespace std;

#define MAX 260

int num_vertices, graph[MAX][MAX];

vector<int> cycle;
bitset<MAX> visited;
bool done = false;

void get_cycle(int last_vertex = 0) {
    if ((int) cycle.size() == num_vertices - 1 && graph[last_vertex][0]) {
        cycle.push_back(1);
        done = true;
    } else if (!done) {
        for (int i = 0; i < num_vertices && !done; i++) {
            if (graph[last_vertex][i] && !visited[i]) {
                cycle.push_back(i + 1);
                visited[i] = true;
                get_cycle(i);
                visited[i] = false;
                cycle.pop_back();
            }
        }
    }
}

int main() {
    while (scanf("%d\n", &num_vertices) != EOF) {
        for (int i = 0; i < num_vertices; i++)
            for (int j = 0; j < num_vertices; j++)
                graph[i][j] = 0;

        char edge[10]; int u, v;
        while (scanf("%[^\n]\n", edge), edge[0] != '%') {
            sscanf(edge, "%d %d", &u, &v);
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        visited[0] = true;
        get_cycle();

        if (!done) printf("N\n");
        else {
            printf("1 ");
            for (int i = 1; i < num_vertices; i++)
                printf("%d ", cycle[i - 1]);

            printf("1\n");
        }

        cycle.clear();
        visited.reset();
        done = false;
    }
}