#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 1e5 + 5;

int n, a[MAX];
long ps[MAX] = {0LL};
set<long> sums;

void get_sums(int l, int r) {
    sums.insert(ps[r + 1] - ps[l]);
    if (a[r] > a[l]) {
        int mid = (a[l] + a[r]) / 2;
        int idx = upper_bound(a, a + n, mid) - a;

        get_sums(l, idx - 1);
        get_sums(idx, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int q; cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i - 1];

        sums.clear();
        get_sums(0, n - 1);

        while (q--) {
            int s; cin >> s;

            string ans = sums.count(s) ? "Yes" : "No";
            cout << ans << "\n";
        }
    }
}