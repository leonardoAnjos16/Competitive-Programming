#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];

    sort(t.begin(), t.end());

    int r = N - 1;
    long ans = 0LL;

    while (r + 1 >= 4) {
        if (2 * t[1] < t[0] + t[r - 1]) ans += t[0] + 2LL * t[1] + t[r];
        else ans += 2LL * t[0] + t[r - 1] + t[r];
        r -= 2;
    }

    if (!r) ans += t[0];
    else if (r == 1) ans += t[1];
    else ans += t[0] + t[1] + t[2];

    cout << ans << "\n";
}