#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N; scanf("%d", &N);
        char field[MAX]; scanf("%s", field);

        int ans = 0, idx = 0;
        while (idx < N) {
            if (field[idx] == '#') idx++;
            else ans++, idx += 3;
        }

        printf("Case %d: %d\n", i, ans);
    }
}