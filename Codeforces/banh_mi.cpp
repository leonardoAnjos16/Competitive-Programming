#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

int pots[MAX] = {1};

int sum_pots(int l, int r) {
    int ans = pots[r + 1] - 1;
    ans -= pots[l] - 1;
    ans += MOD;
    ans %= MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < MAX; i++) {
        pots[i] = pots[i - 1] << 1;
        pots[i] %= MOD;
    }

    int n, q;
    cin >> n >> q;

    string s; cin >> s;

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cnt[i] = cnt[i - 1] + (s[i - 1] == '1');

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ones = cnt[r] - cnt[l - 1];
        int zeroes = r - l - ones + 1;

        if (!ones) cout << "0\n";
        else {
            int ans = sum_pots(1, ones - 1);
            ans += sum_pots(ones, ones + zeroes - 1);
            ans %= MOD;

            ans -= sum_pots(1, zeroes - 1);
            ans += MOD;
            ans %= MOD;

            cout << ans << "\n";
        }
    }
}