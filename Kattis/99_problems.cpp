#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int prev = N - 1;
    while (prev && prev % 100 != 99) prev--;

    int nxt = N + 1;
    while (nxt % 100 != 99) nxt++;

    int ans = prev && N - prev < nxt - N ? prev : nxt;
    cout << ans << "\n";
}