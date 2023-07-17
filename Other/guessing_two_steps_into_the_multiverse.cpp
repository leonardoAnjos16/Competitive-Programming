#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

void update(pair<int, int> &mx, pair<int, int> &smx, int nv, int v) {
    if (v == mx.second) mx.first++;
    else {
        if (nv >= mx.first) {
            smx = mx;
            mx = make_pair(nv, v);
        } else if (nv > smx.first) {
            smx = make_pair(nv, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    llong ways = 0LL;
    vector<int> din(n, 0), dout(n, 0);

    int mx = -INF;
    pair<int, int> mx_in = make_pair(-INF, -1), smx_in = make_pair(-INF, -1);
    pair<int, int> mx_out = make_pair(-INF, -1), smx_out = make_pair(-INF, -1);

    for (int i = 0; i < t; i++) {
        int u, v;
        cin >> u >> v;

        din[v - 1]++;
        dout[u - 1]++;

        ways += dout[v - 1];
        ways += din[u - 1];
        if (u == v) ways--;

        mx = max(mx, din[u - 1] + dout[u - 1]);
        mx = max(mx, din[v - 1] + dout[v - 1]);

        update(mx_in, smx_in, din[v - 1], v - 1);
        update(mx_out, smx_out, dout[u - 1], u - 1);

        int add = mx + 1;
        if (mx_in.second != mx_out.second) add = max(add, mx_in.first + mx_out.first);
        else add = max({ add, mx_in.first + smx_out.first, smx_in.first + mx_out.first });

        cout << ways << " " << add << "\n";
    }
}