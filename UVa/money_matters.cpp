#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    private:
        vector<int> ds, rank;
        int num_vertices;

    public:
        UnionFind(int num_vertices) {
            ds.reserve(num_vertices);
            rank.assign(num_vertices, 0);
            for (int i = 0; i < num_vertices; i++) ds[i] = i;
            this->num_vertices = num_vertices;
        }

        int find(int v) {
            if (ds[v] == v) return v;
            else ds[v] = find(ds[v]);
            return ds[v];
        }

        void unite(int v1, int v2) {
            int r1 = find(v1), r2 = find(v2);
            if (r1 != r2) {
                if (rank[r1] > rank[r2]) ds[r2] = r1;
                else ds[r1] = r2;

                if (rank[r1] == rank[r2]) rank[r2]++;
            }
        }

        bool is_possible(vector<int> debts) {
            vector<int> new_debts(num_vertices, 0);
            for (int i = 0; i < num_vertices; i++)
                new_debts[find(i)] += debts[i];

            for (int i = 0; i < num_vertices; i++)
                if (new_debts[i]) return false;

            return true;
        }
};

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_friends, num_friendships;
        scanf("%d %d", &num_friends, &num_friendships);

        vector<int> debts(num_friends);
        for (int i = 0; i < num_friends; i++)
            scanf("%d", &debts[i]);

        UnionFind ds(num_friends);
        for (int i = 0; i < num_friendships; i++) {
            int x, y; scanf("%d %d", &x, &y);
            ds.unite(x, y);
        }

        printf("%s\n", ds.is_possible(debts) ? "POSSIBLE" : "IMPOSSIBLE");
    }
}