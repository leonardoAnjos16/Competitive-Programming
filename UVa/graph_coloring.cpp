#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX = 105;

vector<vi> graph;
int num_vertices;

vector<bool> black;
vector<int> restrictions;
int max_black = INT_MIN;

void get_max_black(vector<bool> curr, int num_black = 0, int index = 0) {
    if (index >= num_vertices && num_black >= max_black) {
        max_black = num_black;
        for (int i = 0; i < num_vertices; i++)
            black[i] = curr[i];
    } else if (index < num_vertices) {
        if (!restrictions[index]) {
            curr[index] = true;
            int num_edges = graph[index].size();

            for (int i = 0; i < num_edges; i++)
                restrictions[graph[index][i]]++;

            get_max_black(curr, num_black + 1, index + 1);

            curr[index] = false;
            for (int i = 0; i < num_edges; i++)
                restrictions[graph[index][i]]--;
        }

        get_max_black(curr, num_black, index + 1);
    }
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_edges;
        scanf("%d %d", &num_vertices, &num_edges);

        graph.assign(num_vertices, vi());
        for (int i = 0; i < num_edges; i++) {
            int u, v; scanf("%d %d", &u, &v);
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        black.assign(num_vertices, false);
        restrictions.assign(num_vertices, 0);

        vector<bool> curr(num_vertices, false);
        get_max_black(curr);

        printf("%d\n", max_black);
        for (int i = 0; i < num_vertices; i++) {
            if (black[i]) {
                printf("%d", i + 1);
                if (--max_black) printf(" ");
            }
        }

        printf("\n");
        max_black = INT_MIN;
    }
}