#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(9) << fixed;

    int facts[MAX] = {1};
    for (int i = 1; i < MAX; i++)
        facts[i] = facts[i - 1] * i;

    int T; cin >> T;
    while (T--) {
        string n; cin >> n;
        int size = n.size();

        int idx = 0;
        for (int i = 1; i < size; i++)
            for (int j = 0; j < i; j++)
                if (n[j] < n[i])
                    idx += facts[size - j - 1];

        long double aux = 1.0 / facts[size];
        if (!idx) cout << 0.0 << "\n";
        else if (idx == 1) cout << aux << "\n";
        else {
            long double a = pow(aux, 1.0 / (idx - 1));
            long double b = aux * a;

            long double ans = pow(a + b, idx - 1);
            cout << ans << "\n";
        }
    }
}