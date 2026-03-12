#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong MAX = 5e9;

int M;
vector<int> factors;

void get_factors(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            factors.push_back(i);
            while (x % i == 0)
                x /= i;
        }

    if (x > 1) factors.push_back(x);
}

llong count(llong x) {
    llong ans = x;
    int nfactors = factors.size();

    for (int i = 1; i < (1 << nfactors); i++) {
        int num = 1;
        for (int j = 0; j < nfactors; j++)
            if (i & (1 << j))
                num *= factors[j];

        llong aux = x / num;
        if (__builtin_popcount(i) & 1) ans -= aux;
        else ans += aux;
    }

    return ans;
}

void solve(vector<llong> &ans, vector<pair<llong, int>> &a, int al, int ar, llong l = 1LL, llong r = MAX) {
    if (al > ar || l > r) return;

    llong mid = (l + r) / 2LL;
    llong c = count(mid);

    int equal_l = lower_bound(a.begin() + al, a.begin() + ar + 1, make_pair(c, 0)) - a.begin();
    int equal_r = upper_bound(a.begin() + al, a.begin() + ar + 1, make_pair(c, INT_MAX)) - a.begin() - 1;

    if (equal_l <= equal_r && gcd(M, mid) == 1LL) {
        for (int i = equal_l; i <= equal_r; i++)
            ans[a[i].second] = mid;

        solve(ans, a, al, equal_l - 1, l, mid - 1);
        solve(ans, a, equal_r + 1, ar, mid + 1, r);
    } else {
        solve(ans, a, al, equal_r, l, mid - 1);
        solve(ans, a, equal_r + 1, ar, mid + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N >> M;

    get_factors(M);

    vector<pair<llong, int>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<llong> ans(N, -1LL);
    solve(ans, a, 0, N - 1);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}