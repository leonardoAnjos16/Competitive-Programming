#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    map<int, vector<int>> cnt;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a].push_back(i);
    }

    const int nums[6] = { 4, 8, 15, 16, 23, 42 };

    map<int, int> last;
    for (int i = 0; i < 6; i++)
        last[nums[i]] = -1;

    int seqs = 0;
    for (auto it = cnt[4].begin(); it != cnt[4].end(); it++) {
        auto index = it;
        bool done = false;

        for (int j = 1; j < 6 && !done; j++) {
            index = upper_bound(cnt[nums[j]].begin() + last[nums[j]] + 1, cnt[nums[j]].end(), *index);
            if (index == cnt[nums[j]].end()) done = true;
            else last[nums[j]] = index - cnt[nums[j]].begin();
        }

        if (done) break;
        else seqs++;
    }


    int ans = n - 6 * seqs;
    cout << ans << "\n";
}