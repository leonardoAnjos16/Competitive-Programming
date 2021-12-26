#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0, aux = i;
        for (int j = 2; j * j <= aux; j++) {
            if (!(aux % j)) cnt++;
            while (!(aux % j)) aux /= j;
        }

        if (aux > 1) cnt++;
        if (cnt == 2) ans++;
    }

    cout << ans << "\n";
}