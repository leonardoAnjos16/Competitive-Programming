#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        char edge[10];
        int num_edges = 0;

        bitset<26> has_edge;
        while (scanf("%s", edge), edge[0] != '*') {
            has_edge.set(edge[1] - 'A');
            has_edge.set(edge[3] - 'A');
            num_edges++;
        }

        char vertices[100];
        scanf("%s", vertices);

        int size = strlen(vertices);
        int num_acorns = 0;

        for (int i = 0; i < size; i += 2)
            if (!has_edge.test(vertices[i] - 'A'))
                num_acorns++;

        int num_vertices = (size + 1) / 2;
        int num_trees = num_vertices - num_edges - num_acorns;
        printf("There are %d tree(s) and %d acorn(s).\n", num_trees, num_acorns);
    }
}