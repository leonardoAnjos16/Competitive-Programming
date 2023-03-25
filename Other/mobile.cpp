#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

vector<int> apar, wpar, ldist, rdist;
vector<pair<char, int>> lchild, rchild;

int total_weight(char type, int idx, llong weight) {
    if (type == 'W') return weight;

    int a = ldist[idx], b = rdist[idx];
    // x + y = weight
    // a * x - b * y = 0
    // a * x + b * x = b * weight
    // x * (a + b) = b * weight
    // x = (b * weight) / (a + b)

    if ((b * weight) % (a + b)) return INF;
    llong x = (b * weight) / (a + b);

    auto [tl, nl] = lchild[idx];
    auto [tr, nr] = rchild[idx];

    int ans = total_weight(tl, nl, x);
    if (ans >= INF) return INF;

    ans += total_weight(tr, nr, weight - x);
    if (ans >= INF) return INF;

    return ans;
}

int total_weight(int m, int w) {
    char type = 'W';
    int p = wpar[m], ans = 0;

    while (p != -1) {
        int a = ldist[p], b = rdist[p];
        bool left = lchild[p] == make_pair(type, m);

        if (left && (1LL * a * w) % b) return INF;
        if (!left && (1LL * b * w) % a) return INF;
        llong weight = left ? 1LL * a * w / b : 1LL * b * w / a;

        auto [t, n] = left ? rchild[p] : lchild[p];
        ans += total_weight(t, n, weight);
        if (ans >= INF) return INF;

        m = p;
        w += weight;
        p = apar[p];
        type = 'A';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t = 1;
    while (cin >> n, n) {
        apar.assign(n + 1, -1);
        wpar.assign(2 * n + 1, -1);
        ldist.resize(n + 1);
        rdist.resize(n + 1);
        lchild.resize(n + 1);
        rchild.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            int dl, dr, nl, nr; char tl, tr;
            cin >> dl >> dr >> tl >> tr >> nl >> nr;

            ldist[i] = dl;
            rdist[i] = dr;

            lchild[i] = make_pair(tl, nl);
            rchild[i] = make_pair(tr, nr);

            if (tl == 'A') apar[nl] = i;
            else wpar[nl] = i;

            if (tr == 'A') apar[nr] = i;
            else wpar[nr] = i;
        }

        int m, w;
        cin >> m >> w;

        int p = wpar[m];
        int g = gcd(ldist[p], rdist[p]);
        bool left = lchild[p] == make_pair('W', m);

        if (left)
            w = (w * g + rdist[p] - 1) / rdist[p] * rdist[p] / g;
        else
            w = (w * g + ldist[p] - 1) / ldist[p] * ldist[p] / g;

        int ans, cnt = 0;
        while ((ans = total_weight(m, w)) >= INF && cnt < 10000) {
            if (left) w += rdist[p] / g;
            else w += ldist[p] / g;
        }

        ans += w;
        cout << "Case " << t++ << ": " << ans << "\n";
    }
}