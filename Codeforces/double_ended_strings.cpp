#include <bits/stdc++.h>

using namespace std;

#define long long long int

string a, b;
vector<vector<vector<vector<int>>>> memo;

int operations(int al, int ar, int bl, int br) {
    if (al > ar) return br - bl + 1;
    if (bl > br) return ar - al + 1;
    if (a.substr(al, ar - al + 1) == b.substr(bl, br - bl + 1)) return 0;

    int &ans = memo[al][ar][bl][br];
    if (~ans) return ans;

    ans = operations(al + 1, ar, bl, br);
    ans = min(ans, operations(al, ar - 1, bl, br));
    ans = min(ans, operations(al, ar, bl + 1, br));
    ans = min(ans, operations(al, ar, bl, br - 1));

    return ++ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> a >> b;
        int n = a.size();
        int m = b.size();

        memo.assign(n, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m, -1))));

        int ans = operations(0, n - 1, 0, m - 1);
        cout << ans << "\n";
    }
}