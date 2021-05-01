#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int B = 257;
const int MAX = 5e5 + 5;
const int MOD = 1e9 + 7;

vector<long> p;

vector<long> build_hash(string &s) {
    vector<long> h(1, s[0]);
    for (int i = 1; i < size(s); i++)
        h.pb((h[i - 1] * B + s[i]) % MOD);

    return h;
}

long get_hash(vector<long> &h, int l, int r) {
    if (!l) return h[r];
    return (h[r] - ((h[l - 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p.assign(1, 1);
    for (int i = 1; i < MAX; i++)
        p.pb((p[i - 1] * B) % MOD);

    int N, M;
    cin >> N >> M;

    string S; cin >> S;
    vector<long> h = build_hash(S);

    reverse(all(S));
    vector<long> rh = build_hash(S);

    bool ans = false;
    for (int i = M - 1; i < N; i++)
        if (get_hash(h, i - M + 1, i) == get_hash(rh, N - i - 1, N - i + M - 2))
            ans = true;

    cout << (ans ? "Accept" : "Reject") << "\n";
}