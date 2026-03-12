#include <bits/stdc++.h>

using namespace std;

int points(vector<int> &a, vector<int> &b, vector<int> &g, int initial) {
    int ans = 0;
    vector<int> state = { 1, 2, 3 };

    for (int i = 0; i < (int) a.size(); i++) {
        swap(state[a[i] - 1], state[b[i] - 1]);
        if (state[g[i] - 1] == initial) ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N), b(N), g(N);
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i] >> g[i];

    int ans = max({ points(a, b, g, 1), points(a, b, g, 2), points(a, b, g, 3) });
    cout << ans << "\n";
}