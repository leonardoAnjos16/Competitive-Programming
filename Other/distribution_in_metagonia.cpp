#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<long> solve(long n) {
    if (!n) return {};

    if (!(n & 1)) {
        vector<long> ans = solve(n >> 1);
        for (auto &a: ans) a *= 2;
        return ans;
    }

    long pot = 1LL;
    while (pot <= n)
        pot *= 3LL;

    pot /= 3LL;

    vector<long> ans = solve(n - pot);
    ans.push_back(pot);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        long n; cin >> n;

        vector<long> ans = solve(n);

        int cnt = ans.size();
        cout << cnt << "\n";

        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}