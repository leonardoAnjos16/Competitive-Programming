#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, L, C;
    while (cin >> N >> L >> C) {
        int chars = -1, lines = 1, ans = 1;
        while (N--) {
            string s; cin >> s;
            int size = s.size();

            if (chars + size + 1 <= C) chars += size + 1;
            else chars = size, lines++;

            if (lines > L) lines = 1, ans++;
        }

        printf("%d\n", ans);
    }
}