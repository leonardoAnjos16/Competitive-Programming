#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int f = N / 2;
    int c = N - f;

    llong ans = 1LL * f * c + N + 1;
    cout << ans << "\n";
}