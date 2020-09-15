#include <bits/stdc++.h>

using namespace std;

#define seg pair<int, int>
#define l first
#define r second

int main() {
    int T; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        if (i) printf("\n");
        int M; scanf("%d", &M);

        vector<seg> segs; int L, R;
        while (scanf("%d %d", &L, &R), L | R)
            segs.push_back({L, R});

        int N = segs.size();
        sort(segs.begin(), segs.end());

        int covered = 0, idx = 0, ans = 0;
        vector<seg> chosen;
        bool possible = true;

        while (idx < N && possible) {
            int max_r = idx;
            while (idx < N && segs[idx].l <= covered)
                if (segs[idx++].r > segs[max_r].r) max_r = idx - 1;

            if (max_r == idx) possible = false;
            else {
                chosen.push_back(segs[max_r]);
                covered = segs[max_r].r; ans++;
                if (covered >= M) break;
            }
        }

        if (!possible || covered < M) printf("0\n");
        else {
            printf("%d\n", ans);
            for (int j = 0; j < ans; j++)
                printf("%d %d\n", chosen[j].l, chosen[j].r);
        }
    }
}