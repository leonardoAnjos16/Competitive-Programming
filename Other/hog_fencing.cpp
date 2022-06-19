#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 0;
    for (int i = 1; i < N; i++)
        ans = max(ans, i * ((N - 2 * i) / 2));

    cout << ans << "\n";
}