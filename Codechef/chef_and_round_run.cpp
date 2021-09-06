#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> A, vis;

int count(int i) {
    if (vis[i] == 2) return 0;
    if (vis[i] == 1) {
        int j = (i + A[i] + 1) % N, ans = 1;
        while (j != i) j = (j + A[j] + 1) % N, ans++;
        return ans;
    }

    vis[i]++;
    int ans = count((i + A[i] + 1) % N);
    vis[i]++;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vis.assign(N, 0);

        int ans = 0;
        for (int i = 0; i < N; i++)
            if (!vis[i]) ans += count(i);

        cout << ans << "\n";
    }
}