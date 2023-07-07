#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct RabinKarp {
private:
    string s;
    int n, base, mod;
    vector<llong> p, h;

public:
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int n = s.size();
    RabinKarp hasher(s);

    reverse(s.begin(), s.end());
    RabinKarp rhasher(s);

    llong ans = 1LL;
    vector<int> deg(n, 0);
    deg[0] = 1;

    for (int i = 1; i < n; i++) {
        if (hasher.hash(0, i) != rhasher.hash(n - i - 1, n - 1)) continue;
        deg[i] = deg[(i - 1) / 2] + 1;
        ans += deg[i];
    }

    cout << ans << "\n";
}