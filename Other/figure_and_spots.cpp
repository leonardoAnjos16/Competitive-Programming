#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("figure.in", "r", stdin);
    freopen("figure.out", "w", stdout);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        if (t) cout << "\n";

        int H, W, N;
        cin >> H >> W >> N;

        vector<string> ans(H, string(W, '.'));

        int row = 1, col = 1;
        while (N > 0 && row + 1 < H) {
            while (N > 0 && col + 1 < W)
                ans[row][col] = '#', N--, col += 2;

            row++; col = row & 1 ? 1 : 2;
        }

        if (N) cout << "Impossible\n";
        else {
            for (int i = 0; i < H; i++)
                cout << ans[i] << "\n";
        }
    }
}