#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool is_possible(vvi matrix, int num_vertices, int num_edges) {
    vvi edges(num_edges);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_edges; j++) {
            if (matrix[i][j]) edges[j].push_back(i);
            if (edges[j].size() > 2) return false;
        }
    }

    set<ii> actual_edges;
    for (int i = 0; i < num_edges; i++) {
        if (edges[i].size() < 2) return false;
        actual_edges.insert({edges[i][0], edges[i][1]});
    }

    if (actual_edges.size() == num_edges) return true;
    else return false;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_vertices, num_edges;
        scanf("%d %d", &num_vertices, &num_edges);

        vvi matrix; matrix.assign(num_vertices, vi(num_edges));
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_edges; j++) {
                int number; scanf("%d", &number);
                matrix[i][j] = number;
            }
        }

        if (is_possible(matrix, num_vertices, num_edges)) printf("Yes\n");
        else printf("No\n");
    }
}