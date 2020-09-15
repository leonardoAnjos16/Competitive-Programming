#include <bits/stdc++.h>

using namespace std;

class Union_Find {
    private:
        vector<int> ds, rank;
        int num_sets;

    public:
        Union_Find(int num_vertices) {
            ds.reserve(num_vertices);
            rank.assign(num_vertices, 0);
            for (int i = 0; i < num_vertices; i++) ds[i] = i;
            num_sets = num_vertices;
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
                num_sets--;
            }
        }

        int get_num_sets() {
            return num_sets;
        }
};

int main() {
    int num_students, num_pairs, case_num = 1;
    while (scanf("%d %d", &num_students, &num_pairs), num_students || num_pairs) {
        Union_Find ds(num_students);

        for (int i = 0; i < num_pairs; i++) {
            int student_1, student_2;
            scanf("%d %d", &student_1, &student_2);
            ds.unite(student_1 - 1, student_2 - 1);
        }

        printf("Case %d: %d\n", case_num++, ds.get_num_sets());
    }
}