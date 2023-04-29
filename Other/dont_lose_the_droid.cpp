#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int T; cin >> T;

    int dx = 0, dy = 0, lx = 0, rx = N - 1, ly = 0, ry = M - 1;
    while (T--) {
        char l; cin >> l;
        if (l == 'C') dx++;
        else if (l == 'D') dy++;
        else if (l == 'B') dx--;
        else dy--;

        lx = max(lx, -dx);
        rx = min(rx, N - dx - 1);
        ly = max(ly, -dy);
        ry = min(ry, M - dy - 1);
    }

    vector<pair<int, int>> ans;
    for (int i = lx; i <= rx; i++)
        for (int j = ly; j <= ry; j++)
            if (i + dx >= 0 && i + dx < N && j + dy >= 0 && j + dy < M)
                ans.emplace_back(i + dx + 1, j + dy + 1);

    int cnt = ans.size();
    cout << cnt << "\n";

    for (auto [x, y]: ans)
        cout << x << " " << y << "\n";
}