#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int main() {
    int n, case_num = 0;
    while (scanf("%d", &n), n) {
        if (case_num++) printf("\n");

        int A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        sort(A, A + n);
        A[n] = A[n - 1] + 1;

        int k = 1, cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (A[i] == A[i - 1]) cnt++;
            else k = max(k, cnt), cnt = 1;
        }

        vector< vector<int> > ans(k);
        for (int i = 0; i < n; i++)
            ans[i % k].push_back(A[i]);

        printf("%d\n", k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < (int) ans[i].size(); j++) {
                if (j) printf(" ");
                printf("%d", ans[i][j]);
            }

            printf("\n");
        }
    }
}