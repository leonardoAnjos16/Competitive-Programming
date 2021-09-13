#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
string table[2];
vector<int> memo[2][2];

int max_mex(bool zero = false, bool one = false, int i = 0) {
    int last_mex = !zero ? 0 : (!one ? 1 : 2);
    if (i >= n) return last_mex;

    int &ans = memo[zero][one][i];
    if (~ans) return ans;

    bool has_zero = table[0][i] == '0' || table[1][i] == '0';
    bool has_one = table[0][i] == '1' || table[1][i] == '1';
    return ans = max(last_mex + max_mex(has_zero, has_one, i + 1), max_mex(zero || has_zero, one || has_one, i + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        cin >> table[0];
        cin >> table[1];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                memo[i][j].assign(n + 5, -1);

        int ans = max_mex();
        cout << ans << "\n";
    }
}