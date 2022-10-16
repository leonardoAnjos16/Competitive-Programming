#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 8;

string board[MAX];
bitset<MAX> cols;
bitset<2 * MAX> ldigs, rdigs;

int count(int row = 0) {
    if (row >= MAX) return 1;

    int ans = 0;
    for (int col = 0; col < MAX; col++)
        if (board[row][col] == '.' && !cols[col] && !ldigs[row - col + MAX - 1] && !rdigs[row + col]) {
            cols[col] = true;
            ldigs[row - col + MAX - 1] = true;
            rdigs[row + col] = true;

            ans += count(row + 1);

            cols[col] = false;
            ldigs[row - col + MAX - 1] = false;
            rdigs[row + col] = false;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAX; i++)
        cin >> board[i];

    int ans = count();
    cout << ans << "\n";
}