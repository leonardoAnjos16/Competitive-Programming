#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<int> x;

llong count(int k) {
    llong ans = 0LL;
    unordered_map<int, int> cnt;
    int l = 0, r = 0, distinct = 0;

    while (l < n) {
        while (r < n && distinct <= k)
            if (cnt[x[r++]]++ == 0)
                distinct++;

        ans += distinct > k ? r - l - 1 : r - l;
        if (--cnt[x[l++]] == 0)
            distinct--;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> k;

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    llong ans = count(k) - count(k - 1);
    cout << ans << "\n";
}