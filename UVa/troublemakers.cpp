#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    int case_num = 1;

    while (N--) {
        int n, m; scanf("%d %d", &n, &m);

        vector<vector<int> > g(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        set<int> rooms[2];
        rooms[0].insert(0);

        int pairs[2] = {0};
        for (int i = 1; i < n; i++) {
            int cnt[2] = {0};
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < (int) g[i].size(); k++)
                    if (rooms[j].count(g[i][k])) cnt[j]++;

            if (cnt[0] + pairs[0] <= cnt[1] + pairs[1]) rooms[0].insert(i), pairs[0] += cnt[0];
            else rooms[1].insert(i), pairs[1] += cnt[1];
        }

        printf("Case #%d: ", case_num++);
        if (pairs[0] > m / 2 || pairs[1] > m / 2) printf("Impossible\n");
        else {
            int size = rooms[0].size();
            printf("%d\n", size);

            int cnt = 0;
            for (auto it = rooms[0].begin(); it != rooms[0].end(); it++, cnt++) {
                if (cnt) printf(" ");
                printf("%d", *it + 1);
            }

            printf("\n");
        }
    }
}