#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    private:
        vector<int> ds, rank, set_size;
        int num_vertices;

    public:
        UnionFind(int num_vertices) {
            ds.reserve(num_vertices);
            rank.assign(num_vertices, 0);
            set_size.assign(num_vertices, 1);
            for (int i = 0; i < num_vertices; i++) ds[i] = i;
            this->num_vertices = num_vertices;
        }

        int find(int v) {
            if (ds[v] == v) return v;
            else ds[v] = find(ds[v]);
            return ds[v];
        }

        void unite(int v1, int v2) {
            int r1 = find(v1);
            int r2 = find(v2);

            if (r1 != r2) {
                if (rank[r1] > rank[r2]) ds[r2] = r1;
                else ds[r1] = r2;

                if (rank[r1] == rank[r2]) rank[r2]++;
                set_size[r1] = set_size[r2] += set_size[r1];
            }
        }

        int get_largest_set_size() {
            int max = INT_MIN;
            for (int i = 0; i < num_vertices; i++)
                if (set_size[i] > max) max = set_size[i];

            return max;
        }
};

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_citizens, num_pairs;
        scanf("%d %d", &num_citizens, &num_pairs);

        UnionFind ds(num_citizens);
        for (int i = 0; i < num_pairs; i++) {
            int c1, c2; scanf("%d %d", &c1, &c2);
            ds.unite(c1 - 1, c2 - 1);
        }

        printf("%d\n", ds.get_largest_set_size());
    }
}