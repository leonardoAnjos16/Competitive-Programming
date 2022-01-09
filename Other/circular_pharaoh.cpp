#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct RabinKarp {
private:
    string s;
    int n, base, mod;
    vector<long> p, h;

public:
    RabinKarp(string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = s.size();

        this->base = base;
        this->mod = mod;

        build();
    }

    RabinKarp(int n, string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = n;

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

    vector<int> divs;
    for (int i = 1; i * i <= n; i++)
        if (!(n % i)) {
            divs.push_back(i);
            if (i * i < n)
                divs.push_back(n / i);
        }

    int ans = 0;
    RabinKarp hasher(n, s);

    for (auto d: divs) {
        if (d == n) ans++;
        else {
            bool possible = true;
            for (int i = 2 * d - 1; i < n && possible; i += d)
                if (hasher.hash(i - 2 * d + 1, i - d) != hasher.hash(i - d + 1, i))
                    possible = false;

            if (possible) ans += n;
        }
    }

    cout << ans << "\n";
}