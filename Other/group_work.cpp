#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 1;
    for (int i = 0; i < N; i++)
        ans *= 2;

    ans -= N + 1;
    cout << ans << "\n";
}