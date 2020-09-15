#include <bits/stdc++.h>

using namespace std;

class Union_Find {
    private:
        vector<int> ds, rank;
        int num_vertices;

    public:
        Union_Find(int num_vertices) {
            ds.reserve(num_vertices);
            rank.assign(num_vertices, 0);
            for (int i = 0; i < num_vertices; i++) ds[i] = i;
            this->num_vertices = num_vertices;
        }

        int find(int vertex) {
            if (ds[vertex] == vertex) return vertex;
            else ds[vertex] = find(ds[vertex]);
            return ds[vertex];
        }

        void unite(int vertex_1, int vertex_2) {
            int root_1 = find(vertex_1);
            int root_2 = find(vertex_2);

            if (root_1 != root_2) {
                if (rank[root_1] > rank[root_2]) ds[root_2] = root_1;
                else ds[root_1] = root_2;

                if (rank[root_1] == rank[root_2]) rank[root_2]++;
            }
        }
};

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_computers;
        scanf("%d\n", &num_computers);

        Union_Find ds(num_computers);
        char op; int computer_1, computer_2;
        int success = 0, no_success = 0;

        string line;
        while (getline(cin, line) && !line.empty()) {
            sscanf(line.c_str(), "%c %d %d", &op, &computer_1, &computer_2);

            if (op == 'c') ds.unite(computer_1 - 1, computer_2 - 1);
            else if (ds.find(computer_1 - 1) == ds.find(computer_2 - 1)) success++;
            else no_success++;
        }

        printf("%d,%d\n", success, no_success);
        if (num_cases) printf("\n");
    }
}