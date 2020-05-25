#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);

        set<int> jars;
        int A[MAX], cnt[MAX] = {0};

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            jars.insert(A[i]);
            cnt[A[i]]++;
        }

        set<int> quant;
        for (auto it = jars.begin(); it != jars.end(); it++)
            quant.insert(cnt[*it]);

        bool possible = quant.size() == jars.size();
        if (!possible) printf("NO\n");
        else {
            int curr_cnt = 1; possible = true;
            for (int i = 1; i < N && possible; i++) {
                if (A[i] == A[i - 1]) curr_cnt++;
                else if (curr_cnt < cnt[A[i - 1]]) possible = false;
                else curr_cnt = 1;
            }

            printf("%s\n", possible ? "YES" : "NO");
        }
    }
}