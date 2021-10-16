#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 0;
    while (N--) {
        int door; cin >> door;
        ans += door != 1;
    }

    cout << ans << "\n";
}