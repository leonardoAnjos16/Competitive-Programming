#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int N;
    while (scanf("%d", &N), N) {
        int A[MAX]; A[N] = 0;
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        vector<int> ans;
        for (int i = 0; i <= N; i++)
            if (A[i]) ans.push_back(A[i]);

        if ((int) ans.size() == 0) printf("0\n");
        else {
            for (int i = 0; i < (int) ans.size(); i++) {
                if (i) printf(" ");
                printf("%d", ans[i]);
            }

            printf("\n");
        }
    }
}