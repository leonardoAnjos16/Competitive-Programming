#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const long double EPS = 1e-9;

int sign(long double x) {
    return abs(x) < EPS ? 0 : (x > EPS ? 1 : -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int B1, P1, B2, P2;
        cin >> B1 >> P1 >> B2 >> P2;

        if (!B1 && !B2) cout << "Lazy\n";
        else if (!B1) cout << "Congrats\n";
        else if (!B2) cout << "HaHa\n";
        else {
            long double left = P1 * log(B1);
            long double right = P2 * log(B2);

            int ans = sign(left - right);
            if (!ans) cout << "Lazy\n";
            else if (ans < 0) cout << "Congrats\n";
            else cout << "HaHa\n";
        }
    }
}