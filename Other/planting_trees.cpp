#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<long> t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];

    sort(t.rbegin(), t.rend());

    long ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, t[i] + i + 2);

    cout << ans << "\n";
}