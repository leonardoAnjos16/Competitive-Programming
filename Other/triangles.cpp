#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int sum = 0;
    vector<int> X(2 * N);

    for (int i = 0; i < N; i++) {
        cin >> X[i];
        X[N + i] = X[i];
        sum += X[i];
    }

    if (sum % 3) {
        cout << "0\n";
        return 0;
    }

    int rsum = 0;
    map<int, int> rcnt;

    for (int i = 2 * N - 1; i >= 0; i--) {
        rsum += X[i];
        rcnt[rsum]++;
    }

    int lsum = 0;
    map<int, int> lcnt;
    lcnt[0] = rcnt[0] = 1;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        lsum += X[i];
        rsum -= X[i];

        lcnt[lsum]++;
        rcnt[rsum]--;

        if (lcnt[lsum - sum / 3] && rcnt[rsum - sum / 3])
            ans++;
    }

    ans /= 2;
    cout << ans << "\n";
}