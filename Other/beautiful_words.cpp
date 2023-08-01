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

struct Hasher {
private:
    RabinKarp h1, h2;

public:
    Hasher() {}
    Hasher(string &s) {
        h1 = RabinKarp(s);
        h2 = RabinKarp(s, 243, 1e9 + 9);
    }

    int size() {
        return h1.size();
    }

    pair<int, int> hash(int l, int r) {
        return make_pair(h1.hash(l, r), h2.hash(l, r));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string A; cin >> A;

    vector<Hasher> hashers(M);
    for (int i = 0; i < M; i++) {
        string S; cin >> S;
        hashers[i] = Hasher(S);
    }

    string S = A + A;
    Hasher ahasher(S);

    int l = 1, r = N, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        vector<pair<int, int>> hashes;
        for (int i = 0; i < M; i++)
            for (int j = mid - 1; j < hashers[i].size(); j++)
                hashes.push_back(hashers[i].hash(j - mid + 1, j));

        sort(hashes.begin(), hashes.end());
        hashes.erase(unique(hashes.begin(), hashes.end()), hashes.end());

        vector<int> cnt(N);
        for (int i = 0; i < 2 * N - mid + 1; i++)
            if (binary_search(hashes.begin(), hashes.end(), ahasher.hash(i, i + mid - 1))) {
                int l = max(i + mid - N, 0), r = i + 1;
                if (l < N) cnt[l]++;
                if (r < N) cnt[r]--;
            }

        bool all = cnt[0] > 0;
        for (int i = 1; i < N && all; i++) {
            cnt[i] += cnt[i - 1];
            if (!cnt[i]) all = false;
        }

        if (!all) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    cout << ans << "\n";
}