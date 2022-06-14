#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int l = 2, r = N;
        vector<int> ans(N, 1);

        for (int i = 1; i < N; i++)
            ans[N - i - 1] = i & 1 ? r-- : l++;

        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}