#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string board[8];
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j] == '.') {
                int cnt = 0;
                for (int di = -2; di <= 2; di++)
                    for (int dj = -2; dj <= 2; dj++)
                        if (di && dj && abs(di) != abs(dj)) {
                            int ni = i + di, nj = j + dj;
                            if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8 && board[ni][nj] == '*') cnt++;
                        }

                board[i][j] = '0' + cnt;
            }

    for (int i = 0; i < 8; i++)
        cout << board[i] << "\n";
}