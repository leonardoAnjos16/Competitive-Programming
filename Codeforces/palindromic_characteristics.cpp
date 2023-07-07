#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct RabinKarp {
private:
    string s;
    int n, base, mod;
    vector<llong> p, h;

public:
    RabinKarp() {}
    RabinKarp(string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = s.size();

        this->base = base;
        this->mod = mod;

        build();
    }

    int hash(int l, int r) {
        if (!l) return h[r];
        return (h[r] - ((h[l - 1] * p[r - l + 1]) % mod) + mod) % mod;
    }

private:
    void build() {
        p.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = (p[i - 1] * base) % mod;

        h.assign(n, s[0]);
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * base + s[i]) % mod;
    }
};

int n;
RabinKarp hasher, rhasher;
vector<vector<int>> memo;

int degree(int l, int r) {
    if (l == r) return 1;

    int &ans = memo[l][r];
    if (~ans) return ans;

    int half = (r - l + 1) / 2;
    int lhash = hasher.hash(l, l + half - 1);
    int rhash = hasher.hash(r - half + 1, r);

    if (lhash == rhash && degree(l, l + half - 1))
        return ans = degree(l, l + half - 1) + 1;

    if (hasher.hash(l, r) == rhasher.hash(n - r - 1, n - l - 1))
        return ans = 1;

    return ans = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    n = s.size();
    hasher = RabinKarp(s);

    reverse(s.begin(), s.end());
    rhasher = RabinKarp(s);

    vector<int> ans(n + 1, 0);
    memo.assign(n + 5, vector<int>(n + 5, -1));

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            ans[degree(i, j)]++;

    for (int i = n; i > 0; i--)
        ans[i - 1] += ans[i];

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}