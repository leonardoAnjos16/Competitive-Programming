#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> field(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> field[i][j];

    char dir = 'R';
    int lr = 0, rr = r - 1, lc = 0, rc = c - 1, rem = r * c, curr = 0, ans = 0;

    while (rem) {
        if (dir == 'R') {
            for (int i = lc; i <= rc; i++) {
                if (!curr) ans += field[lr][i];
                curr = (curr + 1) % k;
                rem--;
            }

            lr++;
            dir = 'B';
        } else if (dir == 'B') {
            for (int i = lr; i <= rr; i++) {
                if (!curr) ans += field[i][rc];
                curr = (curr + 1) % k;
                rem--;
            }

            rc--;
            dir = 'L';
        } else if (dir == 'L') {
            for (int i = rc; i >= lc; i--) {
                if (!curr) ans += field[rr][i];
                curr = (curr + 1) % k;
                rem--;
            }

            rr--;
            dir = 'U';
        } else {
            for (int i = rr; i >= lr; i--) {
                if (!curr) ans += field[i][lc];
                curr = (curr + 1) % k;
                rem--;
            }

            lc++;
            dir = 'R';
        }
    }

    cout << ans << "\n";
}