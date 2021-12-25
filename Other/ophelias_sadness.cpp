#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;
    int sum = 0, cnt = 0;

    while (n--) {
        char type; cin >> type;
        if (type == 'A') {
            long double ans = 1.0L * sum / cnt;
            cout << ans << "\n";
        } else {
            int c; cin >> c;
            sum += c; cnt++;
        }
    }
}