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

    string G; cin >> G;
    int n = G.size();

    int chosen = 0;
    RabinKarp hasher(G);

    for (int i = 1; i < n - 1; i++) {
        int l = 0, r = chosen + 1, aux = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (hasher.hash(chosen - mid + 1, chosen) != hasher.hash(i - mid + 1, i)) r = mid - 1;
            else l = mid + 1, aux = mid;
        }

        if (chosen >= aux && G[i - aux] > G[chosen - aux]) chosen = i;
        else if (chosen < aux && G[i - aux] > G[n - 1]) chosen = i;
    }

    reverse(G.begin(), G.begin() + chosen + 1);
    reverse(G.begin() + chosen + 1, G.end());

    cout << G << "\n";
}