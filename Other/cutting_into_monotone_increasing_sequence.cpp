#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

string x;
vector<vector<int>> memo;

int commas(int n, int digits) {
    if (!n) return -1;
    if (n < digits) return 0;

    int &ans = memo[n][digits];
    if (~ans) return ans;

    ans = INF;
    
    string last = x.substr(n, digits);
    if (x[n - digits] != '0' && x.substr(n - digits, digits) <= last)
        ans = commas(n - digits, digits) + 1;

    for (int i = 1; i < digits; i++)
        if (x[n - i] != '0')
            ans = min(ans, commas(n - i, i) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string b;
    cin >> x >> b;

    if (x[0] == '0') cout << "0\n";
    else {
        int nx = x.size();
        int nb = b.size();
        x += b;

        memo.assign(nx + 5, vector<int>(nb + 5, -1));

        int ans = commas(nx, nb);
        if (ans >= INF) cout << "NO WAY\n";
        else cout << ans << "\n";
    }
}