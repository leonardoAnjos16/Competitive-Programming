#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<pair<int, int>> order(N);
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        order[i] = make_pair(A, i);
    }

    sort(order.begin(), order.end());

    int v = N;
    vector<int> ans(N);

    for (auto [_, idx]: order)
        ans[idx] = v--;

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}