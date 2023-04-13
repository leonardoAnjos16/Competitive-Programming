#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    llong stairs = 0LL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int down = n - i - 1, right = m - j - 1;
            stairs += 4LL * min(down, right) + (down < right) + (right < down) + 1LL;
        }

    vector<vector<bool>> locked(n, vector<bool>(m, false));
    while (q--) {
        int x, y;
        cin >> x >> y;

        int up = 0, i = x - 2, j = y - 1;
        while (i >= 0 && j >= 0 && !locked[i][j]) {
            if (up++ & 1) i--;
            else j--;
        }

        int down = 0; i = x - 1; j = y;
        while (i < n && j < m && !locked[i][j]) {
            if (down++ & 1) j++;
            else i++;
        }

        if (locked[x - 1][y - 1]) stairs += (up + 1LL) * (down + 1LL);
        else stairs -= (up + 1LL) * (down + 1LL);

        up = 0; i = x - 1; j = y - 2;
        while (i >= 0 && j >= 0 && !locked[i][j]) {
            if (up++ & 1) j--;
            else i--;
        }

        down = 0; i = x; j = y - 1;
        while (i < n && j < m && !locked[i][j]) {
            if (down++ & 1) i++;
            else j++;
        }

        if (locked[x - 1][y - 1]) stairs += (up + 1LL) * (down + 1LL);
        else stairs -= (up + 1LL) * (down + 1LL);

        if (locked[x - 1][y - 1]) stairs -= 1LL;
        else stairs += 1LL;

        locked[x - 1][y - 1] = !locked[x - 1][y - 1];
        cout << stairs << "\n";
    }
}