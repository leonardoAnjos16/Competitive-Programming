#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C, T;
    cin >> N >> C >> T;

    vector<int> P(N);
    int sum = 0, mx = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        sum += P[i];
        mx = max(mx, P[i]);
    }

    int l = mx, r = sum, ans;
    while (l <= r) {
        int mid = (l + r) / 2;

        int cnt = 1, curr_sum = 0;
        for (int i = 0; i < N; i++) {
            if (curr_sum + P[i] <= mid) curr_sum += P[i];
            else {
                cnt++;
                curr_sum = P[i];
            }
        }

        if (cnt > C) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    ans = (ans + T - 1) / T;
    cout << ans << "\n";
}