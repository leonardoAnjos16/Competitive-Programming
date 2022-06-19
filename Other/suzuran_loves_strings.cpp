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

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int n = S.size();

        RabinKarp hasher(S);

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int l = 1, r = n - i + 1, prefix = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (hasher.hash(0, mid - 1) != hasher.hash(i, i + mid - 1)) r = mid - 1;
                else l = mid + 1, prefix = mid;
            }

            ans = max(ans, 2 * (n - prefix) - i);
        }

        cout << ans << "\n";
    }
}