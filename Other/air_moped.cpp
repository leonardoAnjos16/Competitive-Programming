#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R; cin >> R;

    int ans = 0;
    for (int i = -R; i <= R; i++)
        for (int j = -R; j <= R; j++) {
            int diff = R * R - i * i - j * j;
            if (diff < 0) continue;

            int aux = sqrt(diff);
            if (aux * aux == diff)
                ans += (aux ? 2 : 1);
        }

    cout << ans << "\n";
}