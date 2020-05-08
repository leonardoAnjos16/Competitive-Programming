#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N), M | N) {
        int m[MAX];
        for (int i = 0; i < M; i++)
            scanf("%d", &m[i]);

        int n[MAX]; priority_queue< pair<int, int> > pq;
        for (int i = 0; i < N; i++) {
            scanf("%d", &n[i]);
            pq.push({n[i], i});
        }

        bool possible = true;
        vector< vector<int> > ans(M, vector<int>());

        for (int i = 0; i < M && possible; i++) {
            if ((int) pq.size() < m[i]) possible = false;
            else {
                vector< pair<int, int> > aux;
                while (m[i]--) {
                    int table = pq.top().second; pq.pop();
                    ans[i].push_back(table);
                    aux.push_back({--n[table], table});
                }

                for (int j = 0; j < (int) aux.size(); j++)
                    if (aux[j].first) pq.push(aux[j]);
            }
        }

        printf("%d\n", possible ? 1 : 0);
        if (possible) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < (int) ans[i].size(); j++) {
                    if (j) printf(" ");
                    printf("%d", ans[i][j] + 1);
                }

                printf("\n");
            }
        }
    }
}