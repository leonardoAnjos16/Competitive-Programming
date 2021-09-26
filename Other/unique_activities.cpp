#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int B = 243;
const int MOD = 1e6 + 7;

vector<long> p, h;

int get_hash(int l, int r) {
    if (!l) return h[r];
    return (h[r] - ((h[l - 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int N = S.size();

    p.assign(N, 1LL);
    for (int i = 1; i < N; i++)
        p[i] = (p[i - 1] * B) % MOD;

    h.assign(N, S[0]);
    for (int i = 1; i < N; i++)
        h[i] = (h[i - 1] * B + S[i]) % MOD;

    int l = 1, r = N;
    int init = 0, len = N;

    while (l <= r) {
        int mid = (l + r) / 2;

        vector<int> hashes;
        int cnt[MOD] = {0}, pos[MOD] = {0};

        for (int i = mid - 1; i < N; i++) {
            int hash = get_hash(i - mid + 1, i);
            cnt[hash]++; pos[hash] = i - mid + 1;
            hashes.push_back(hash);
        }

        int curr = -1;
        for (auto hash: hashes)
            if (cnt[hash] == 1 && (curr == -1 || pos[hash] < curr))
                curr = pos[hash];

        if (curr == -1) l = mid + 1;
        else r = mid - 1, init = curr, len = mid;
    }

    string ans = S.substr(init, len);
    cout << ans << "\n";
}