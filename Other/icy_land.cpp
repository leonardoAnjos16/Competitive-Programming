#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> board(R);
    for (int i = 0; i < R; i++)
        cin >> board[i];

    if (R <= 2 && C <= 2) cout << "0\n";
    else if (R <= 2) {
        int ans = 0;
        for (int i = 1; i < C - 1; i++) {
            int cnt = board[0][i] == '#';
            if (R > 1) cnt += board[1][i] == '#';
            ans += !cnt;
        }

        cout << ans << "\n";
    } else if (C <= 2) {
        int ans = 0;
        for (int i = 1; i < R - 1; i++) {
            int cnt = board[i][0] == '#';
            if (C > 1) cnt += board[i][1] == '#';
            ans += !cnt;
        }

        cout << ans << "\n";
    } else {
        int ans = 0;
        for (int i = 1; i < R - 1; i++)
            for (int j = 1; j < C - 1; j++)
                ans += board[i][j] == '.';

        int cnt = 0;
        for (int i = 1; i < C - 1; i++) {
            cnt += board[0][i] == '#';
            cnt += board[R - 1][i] == '#';
        }

        for (int i = 1; i < R - 1; i++) {
            cnt += board[i][0] == '#';
            cnt += board[i][C - 1] == '#';
        }

        ans += !cnt;
        cout << ans << "\n";
    }
}