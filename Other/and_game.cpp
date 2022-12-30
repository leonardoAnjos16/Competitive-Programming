#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R; cin >> R;
    while (R--) {
        int D; cin >> D;

        int squares = D * D;
        llong ans = (squares + 1LL) * squares * squares / 2LL;
        cout << ans << "\n";
    }
}