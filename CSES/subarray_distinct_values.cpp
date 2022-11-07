#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int distinct = 0;
    map<int, int> cnt;
    long long int ans = 0LL;

    int l = 0, r = 0;
    while (r < n) {
        while (r < n && distinct + !cnt[x[r]] <= k) {
            if (cnt[x[r++]]++ == 0)
                distinct++;

            ans += r - l;
        }

        if (r < n) {
            cnt[x[r++]]++, distinct++;
            while (l < r && distinct > k)
                if (--cnt[x[l++]] == 0)
                    distinct--;

            ans += r - l;
        }
    }

    cout << ans << "\n";
}