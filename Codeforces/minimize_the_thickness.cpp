#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int sum = 0, ans = n;
        for (int i = 0; i < n; i++) {
            sum += a[i];

            bool possible = true;
            int idx = i, curr_sum = 0, length = 0, thickness = i + 1;

            while (idx + 1 < n && possible) {
                if (curr_sum + a[idx + 1] > sum) possible = false;
                else if (curr_sum + a[idx + 1] < sum) curr_sum += a[++idx], length++;
                else if (curr_sum + a[idx + 1] == sum) {
                    thickness = max(thickness, length + 1);
                    curr_sum = length = 0;
                    idx++;
                }
            }

            possible &= !curr_sum;
            if (possible) ans = min(ans, thickness);
        }

        cout << ans << "\n";
    }
}