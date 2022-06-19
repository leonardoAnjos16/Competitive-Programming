#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 0, aux = N;
    while (aux) {
        int digit = aux % 10;
        ans += (digit && N % digit == 0);
        aux /= 10;
    }

    cout << ans << "\n";
}