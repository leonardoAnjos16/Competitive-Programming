#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> S(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> S[i];

    sort(S.begin() + 1, S.end());

    vector<llong> ps(N + 1, 0LL);
    for (int i = 1; i <= N; i++)
        ps[i] = ps[i - 1] + S[i];

    while (M--) {
        int Q; cin >> Q;

        int idx = upper_bound(S.begin() + 1, S.end(), Q) - S.begin();
        llong ans = ps[idx - 1] + Q * (N - idx + 1LL);
        cout << ans << "\n";
    }
}