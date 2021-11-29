#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> X(N);
        for (int i = 0; i < N; i++)
            cin >> X[i];

        sort(X.begin(), X.end());

        int mid = N / 2;
        int ans = X[mid] - X[mid - 1] + 1;
        cout << ans << "\n";
    }
}