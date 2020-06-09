#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);

        int cnt[2] = {0};
        bool possible = true;

        for (int i = 0; i < N; i++) {
            int a; scanf("%d", &a);
            if (!possible) continue;

            if (a == 5) cnt[0]++;
            else if (a == 10) {
                if (cnt[0]) cnt[0]--;
                else possible = false;
                cnt[1]++;
            } else if (a == 15) {
                if (cnt[1]) cnt[1]--;
                else if (cnt[0] > 1) cnt[0] -= 2;
                else possible = false;
            }
        }

        printf("%s\n", possible ? "YES" : "NO");
    }
}