#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 7901;

vector<int> memo;

int fact(int n) {
    if (!n) return 1;

    int &ans = memo[n];
    if (~ans) return ans;

    ans = (n * fact(n - 1)) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    memo.assign(1005, -1);

    while (T--) {
        int n; cin >> n;

        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int A;
            cin >> A;
            cnt[A]++;
        }

        int ans = 1;
        for (auto p: cnt)
            ans = (ans * fact(p.second)) % MOD;

        cout << ans << "\n";
    }
}