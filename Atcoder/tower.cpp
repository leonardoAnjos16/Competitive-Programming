#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;

int N;
vector<tuple<int, int, long>> blocks;
vector<vector<long>> memo;

long value(int i, int allowed) {
    if (allowed < 0) return -INF;
    if (i >= N) return 0LL;

    long &ans = memo[i][allowed];
    if (~ans) return ans;

    int w, s; long v;
    tie(w, s, v) = blocks[i];

    return ans = max(value(i + 1, allowed), v + value(i + 1, min(allowed - w, s)));
}

bool cmp(tuple<int, int, long> &a, tuple<int, int, long> &b) {
    long va, vb;
    int wa, sa, wb, sb;

    tie(wa, sa, va) = a;
    tie(wb, sb, vb) = b;

    return sa - wb > sb - wa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    blocks.resize(N);

    int mx = INT_MIN;
    for (int i = 0; i < N; i++) {
        int w, s; long v;
        cin >> w >> s >> v;

        mx = max(mx, s);
        blocks[i] = make_tuple(w, s, v);
    }

    sort(blocks.begin(), blocks.end(), cmp);
    memo.assign(N + 5, vector<long>(mx + 5, -1LL));

    long ans = 0LL;
    for (int i = 0; i < N; i++) {
        int w, s; long v;
        tie(w, s, v) = blocks[i];
        ans = max(ans, v + value(i + 1, s));
    }

    cout << ans << "\n";
}