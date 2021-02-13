#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    int r[MAX] = {0}, ans = 0;
    for (int i = 0; i < n; i++) {
        int d; cin >> d; d %= k;
        int comp = d ? k - d : 0;

        if (!r[comp]) r[d]++;
        else ans++, r[comp]--;
    }

    ans *= 2;
    cout << ans << "\n";
}