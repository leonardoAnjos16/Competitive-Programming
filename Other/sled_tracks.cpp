#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    long ans = 0LL, last = -1LL;
    for (int i = 0; i < N; i++) {
        long a; cin >> a;
        if (i) ans += abs(last - a);
        last = a;
    }

    cout << ans << "\n";
}