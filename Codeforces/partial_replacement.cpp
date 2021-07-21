#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> stars;
        string s; cin >> s;

        for (int i = 0; i < n; i++)
            if (s[i] == '*')
                stars.push_back(i);

        int m = stars.size();
        if (m < 2) cout << "1\n";
        else {
            int l = 0, r = m - 1, ans = 2;
            while (ans < m && stars[r] - stars[l] > k) {
                int next_l = l;
                while (stars[next_l] - stars[l] <= k) next_l++;
                next_l--;

                int next_r = r;
                while (stars[r] - stars[next_r] <= k) next_r--;
                next_r++;

                int diff_l = stars[next_l] - stars[l];
                int diff_r = stars[r] - stars[next_r];

                ans++;
                if (diff_l > diff_r) l = next_l;
                else r = next_r;
            }

            cout << ans << "\n";
        }
    }
}