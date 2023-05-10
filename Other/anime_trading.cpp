#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    vector<int> c(N);
    for (int i = 0; i < N; i++)
        cin >> c[i];

    sort(c.begin(), c.end());

    int idx = 0;
    set<int> uniq;
    llong ans = LLONG_MAX;

    for (int i = N; i <= 80 * N; i++) {
        while (idx < N && c[idx] <= i)
            uniq.insert(c[idx++]);

        int rem = N - (int) uniq.size();
        ans = min(ans, 1LL * rem * A + 1LL * (i - N) * B);
    }

    cout << ans << "\n";
}