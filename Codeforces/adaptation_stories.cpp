#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;

        sum += v;
        if (sum < 0) {
            ans += abs(sum);
            sum = 0;
        }
    }

    cout << ans << "\n";
}