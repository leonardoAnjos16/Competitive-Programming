#include <bits/stdc++.h>

using namespace std;

#define pair pair<int, int>
#define B first
#define J second

const int MAX = 1e3 + 5;

bool cmp(pair a, pair b) {
    return a.J > b.J;
}

int main() {
    int N, case_num = 1;
    while (scanf("%d", &N), N) {
        pair soldiers[MAX];
        for (int i = 0; i < N; i++)
            scanf("%d %d", &soldiers[i].B, &soldiers[i].J);

        sort(soldiers, soldiers + N, cmp);

        int rem = 0, ans = 0;
        for (int i = 0; i < N; i++) {
            ans += soldiers[i].B;
            rem = max(rem - soldiers[i].B, soldiers[i].J);
        }

        ans += rem;
        printf("Case %d: %d\n", case_num++, ans);
    }
}