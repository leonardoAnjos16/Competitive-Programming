#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const int MAX = 60;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    ldouble p[MAX] = {1.0L, 0.0L};
    for (int i = 2; i < MAX; i++)
        p[i] = (p[i - 1] + p[i - 2]) / 2.0L;

    llong n; cin >> n;

    ldouble pi = 100.0L * (n >= 60 ? p[MAX - 1] : p[n - 1]);
    cout << pi << " " << (100.0L - pi) << "\n";
}