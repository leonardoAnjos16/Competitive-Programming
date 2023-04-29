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

    int size() {
        return n;
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

int lcp(RabinKarp &hasher, int i, int j) {
    int m = hasher.size() - i, n = hasher.size() - j;
    int l = 1, r = min(m, n), ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (hasher.hash(i, i + mid - 1) != hasher.hash(j, j + mid - 1)) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string T; int D;
    cin >> T >> D;

    RabinKarp hasher(T);

    int idx = 0, ans = 0;
    while (idx < (int) T.size()) {
        int jump = 0;
        for (int i = 1; i <= D; i++)
            jump = max(jump, i + lcp(hasher, idx, idx + i));

        idx += jump;
        ans++;
    }

    cout << ans << "\n";
}