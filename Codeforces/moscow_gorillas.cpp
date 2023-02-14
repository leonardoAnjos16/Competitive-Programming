#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong pairs(int size) {
    return size * (size + 1LL) / 2LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> ppos(n);
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        ppos[p - 1] = i;
    }

    vector<int> qpos(n);
    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        qpos[q - 1] = i;
    }

    int pl = ppos[0], pr = ppos[0], ql = qpos[0], qr = qpos[0];
    llong ans = pairs(min(pl, ql));
    ans += pairs(max(pl, ql) - min(pl, ql) - 1);
    ans += pairs(n - max(pl, ql) - 1);

    for (int i = 1; i < n; i++) {
        int il = min(pl, ql);
        int ir = max(pr, qr);

        int l = min(ppos[i], qpos[i]);
        int r = max(ppos[i], qpos[i]);

        pl = min(pl, ppos[i]);
        pr = max(pr, ppos[i]);
        ql = min(ql, qpos[i]);
        qr = max(qr, qpos[i]);

        if (il <= l && l <= ir) continue;
        if (il <= r && r <= ir) continue;

        if (l > ir) r = l, l = -1;
        if (r < il) l = r, r = n;

        int lsize = il - l;
        int rsize = r - ir;
        ans += 1LL * lsize * rsize;
    }

    cout << ++ans << "\n";
}