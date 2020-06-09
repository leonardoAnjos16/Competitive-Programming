#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char S[MAX]; scanf("%s", S);
        int N = strlen(S);

        int ans = 0, idx = 1;
        while (idx < N) {
            if (S[idx] == S[idx - 1]) idx++;
            else ans++, idx += 2;
        }

        printf("%d\n", ans);
    }
}