#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("kids.in", "r", stdin);
    freopen("kids.out", "w", stdout);

    cout << setprecision(10) << fixed;

    int N, M;
    cin >> N >> M;

    long double ans = N * (1 - pow((N - 1.0) / N, M));
    cout << ans << "\n";
}