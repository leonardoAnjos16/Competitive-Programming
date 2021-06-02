#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

vector<vector<long double>> memo;

long double prob(int q0, int q1) {
    if (q0 == 0 && q1 == 0) return 0.0;
    if (q0 == 0 && q1 == 1) return 1.0;
    if (q0 == 1 && q1 == 0) return 0.0;

    long double &ans = memo[q0][q1];
    if (ans >= 0.0) return ans;

    if (!q0) ans = 1 - prob(1, q1 - 2);
    else {
        long double aux = q1 + 1.0;
        ans = (1 / aux + q1 / aux * (1 - prob(0, q1))) / (1 + 1 / aux);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;
    
    int t; cin >> t;
    memo.assign(2, vector<long double>(MAX, -1.0));

    while (t--) {
        int n; cin >> n;

        string b, c;
        cin >> b >> c;

        int q0 = 0, q1 = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == '0' && c[i] == '1') q0++;
            else if (b[i] == '1') q1++;
        }

        long double ans = 1 - prob(q0, q1);
        cout << ans << "\n";
    }
}