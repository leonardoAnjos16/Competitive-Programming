#include <bits/stdc++.h>

using namespace std;

const int B1 = 243;
const int B2 = 359;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

template<int B, int MOD>
struct Solver {
private:
    int n, zeros, hash;
    vector<int> p, c;

public:
    Solver(int n): n(n), zeros(n), hash(0) {
        p.assign(n, 1);
        for (int i = 1; i < n; i++)
            p[i] = (1LL * p[i - 1] * B) % MOD;

        c.assign(n, 0);
    }

    int get_hash() {
        return hash;
    }

    void add(int i) {
        int factor = (1LL * c[i] * p[i]) % MOD;
        hash = (hash - factor + MOD) % MOD;

        if (c[i] == 0) zeros--;

        factor = (1LL * ++c[i] * p[i]) % MOD;
        hash = (hash + factor) % MOD;

        normalize();
    }

private:
    void normalize() {
        if (zeros > 0) return;

        int mn = *min_element(c.begin(), c.end());
        for (int i = 0; i < n; i++) c[i] -= mn;

        hash = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) zeros++;
            else {
                int factor = (1LL * c[i] * p[i]) % MOD;
                hash = (hash + factor) % MOD;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }

    map<pair<int, int>, int> first;
    first[make_pair(0, 0)] = -1;

    Solver<B1, MOD1> s1(K);
    Solver<B2, MOD2> s2(K);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        s1.add(C[i]);
        s2.add(C[i]);

        int h1 = s1.get_hash();
        int h2 = s2.get_hash();
        pair<int, int> hash = make_pair(h1, h2);

        if (!first.count(hash)) first[hash] = i;
        else ans = max(ans, i - first[hash]);
    }

    cout << ans << "\n";
}