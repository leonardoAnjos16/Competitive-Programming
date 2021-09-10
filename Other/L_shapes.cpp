#include <bits/stdc++.h>

using namespace std;

#define long long long int

int dot(complex<int> &a, complex<int> &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

bool perp(pair<complex<int>, complex<int>> &a, pair<complex<int>, complex<int>> &b) {
    if ((a.first == b.first && a.second != b.second) || (a.first == b.second && a.second != b.first) ||
        (a.first != b.first && a.second == b.second) || (a.first != b.second && a.second == b.first)) {
        complex<int> u = a.second - a.first;
        complex<int> v = b.second - b.first;
        return !dot(u, v);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("lshape.in", "r", stdin);
    freopen("lshape.out", "w", stdout);

    int N; cin >> N;

    vector<pair<complex<int>, complex<int>>> segs(N);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        complex<int> p1 = { x1, y1 };
        complex<int> p2 = { x2, y2 };

        segs[i] = make_pair(p1, p2);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (perp(segs[i], segs[j]))
                ans++;

    cout << ans << "\n";
}