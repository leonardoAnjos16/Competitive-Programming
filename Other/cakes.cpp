#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = INT_MAX;
    while (N--) {
        int need, have;
        cin >> need >> have;
        ans = min(ans, have / need);
    }

    cout << ans << "\n";
}