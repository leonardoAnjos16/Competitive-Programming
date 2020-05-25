#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, M; scanf("%d %d", &N, &M);

        set<int> nums;
        int cnt[MAX] = {0};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int a; scanf("%d", &a);
                nums.insert(a);
                cnt[a]++;
            }
        }

        int mtx[400][400], row = 0, col = 0, mid = 0;
        bool possible = true;

        for (auto it = nums.begin(); it != nums.end() && possible; it++) {
            while (cnt[*it] > 1 && col < M / 2) {
                mtx[row][col] = mtx[row][M - col - 1] = *it;
                if (++row >= N) row = 0, col++;
                cnt[*it] -= 2;
            }

            if (cnt[*it] > 0) {
                if (!(M & 1) || mid >= N) possible = false;
                else while (cnt[*it]--) mtx[mid++][M / 2] = *it;
            }
        }

        if (!possible) printf("-1\n");
        else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (j) printf(" ");
                    printf("%d", mtx[i][j]);
                }

                printf("\n");
            }
        }
    }
}