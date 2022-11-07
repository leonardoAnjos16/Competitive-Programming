#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong N, L, D;
    cin >> N >> L >> D;

    llong ans = L * ((N * D + 1000 * L - 1) / (1000 * L));
    cout << ans << "\n";
}