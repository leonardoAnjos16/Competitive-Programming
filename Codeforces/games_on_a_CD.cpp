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

    int n, k;
    cin >> n >> k;

    string cd; cin >> cd;
    int g; cin >> g;

    map<pair<int, int>, int> id;
    for (int i = 0; i < g; i++) {
        string game; cin >> game;

        int h1 = RabinKarp(game).hash(0, k - 1);
        int h2 = RabinKarp(game, 243, 1e9 + 9).hash(0, k - 1);
        id[make_pair(h1, h2)] = i + 1;
    }

    cd += cd;
    bool done = false;
    RabinKarp hasher(cd), shasher(cd, 243, 1e9 + 9);

    for (int i = 0; i < k && !done; i++) {
        set<int> ids;
        vector<int> ans;
        bool possible = true;

        for (int j = i; j < n * k && possible; j += k) {
            int h1 = hasher.hash(j, j + k - 1);
            int h2 = shasher.hash(j, j + k - 1);
            pair<int, int> hash = make_pair(h1, h2);

            if (!id.count(hash)) possible = false;
            else if (ids.count(id[hash])) possible = false;
            else {
                ids.insert(id[hash]);
                ans.push_back(id[hash]);
            }
        }

        if (possible) {
            done = true;

            cout << "YES\n";
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                cout << ans[j];
            }

            cout << "\n";
        }
    }

    if (!done) cout << "NO\n";
}