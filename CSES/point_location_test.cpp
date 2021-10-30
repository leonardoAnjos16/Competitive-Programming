#include <bits/stdc++.h>

using namespace std;

#define long long long int

long cross(complex<long> u, complex<long> v) {
    return u.real() * v.imag() - u.imag() * v.real();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        complex<long> points[3];
        for (int i = 0; i < 3; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = { x, y };
        }

        complex<long> u = points[1] - points[0];
        complex<long> v = points[2] - points[0];

        long aux = cross(u, v);
        if (aux < 0) cout << "RIGHT\n";
        else if (aux > 0) cout << "LEFT\n";
        else cout << "TOUCH\n";
    }
}