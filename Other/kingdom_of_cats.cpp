#include <bits/stdc++.h>

using namespace std;

#define long long long int

long cross(complex<long> &u, complex<long> &v) {
    return u.real() * v.imag() - u.imag() * v.real();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n) {
        vector<complex<long>> points(n);
        for (int i = 0; i < n; i++) {
            long x, y;
            cin >> x >> y;
            points[i] = { x, y };
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    for (int l = k + 1; l < n; l++) {
                        pair<long, long> order[4];
                        order[0] = make_pair(points[i].real(), points[i].imag());
                        order[1] = make_pair(points[j].real(), points[j].imag());
                        order[2] = make_pair(points[k].real(), points[k].imag());
                        order[3] = make_pair(points[l].real(), points[l].imag());

                        bool possible = false;
                        sort(order, order + 4);

                        do {
                            complex<long> aux[4];
                            for (int m = 0; m < 4; m++)
                                aux[m] = { order[m].first, order[m].second };

                            complex<long> u = aux[1] - aux[0];
                            complex<long> v = aux[2] - aux[0];
                            if (cross(u, v) >= 0) continue;

                            u = aux[2] - aux[1];
                            v = aux[3] - aux[1];
                            if (cross(u, v) >= 0) continue;

                            u = aux[3] - aux[2];
                            v = aux[0] - aux[2];
                            if (cross(u, v) >= 0) continue;

                            u = aux[0] - aux[3];
                            v = aux[1] - aux[3];
                            if (cross(u, v) >= 0) continue;

                            possible = true;
                        } while (!possible && next_permutation(order, order + 4));

                        if (possible) ans++;
                    }

        cout << ans << "\n";
    }
}