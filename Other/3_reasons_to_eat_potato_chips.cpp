#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<vector<int>>> memo;

bool win(int a, int b, int c) {
    if (!a && !b && !c) return false;

    int &ans = memo[a][b][c];
    if (~ans) return ans;

    ans = false;
    for (int i = 1; i <= a; i++)
        if (!win(a - i, b, c))
            return ans = true;

    for (int i = 1; i <= b; i++)
        if (!win(a, b - i, c))
            return ans = true;

    for (int i = 1; i <= c; i++)
        if (!win(a, b, c - i))
            return ans = true;

    for (int i = 1; i <= min({ a, b, c }); i++)
        if (!win(a - i, b - i, c - i))
            return ans = true;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    memo.assign(a + 5, vector<vector<int>>(b + 5, vector<int>(c + 5, -1)));

    cout << (win(a, b, c) ? "Yes" : "No") << "\n";
}