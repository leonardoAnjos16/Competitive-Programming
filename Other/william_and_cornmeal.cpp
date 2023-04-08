#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int people = 0;
    llong ans = 1LL;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        people += a;

        ans = lcm(ans, people);
    }

    cout << ans << "\n";
}