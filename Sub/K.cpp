#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> a;
vector<vector<int>> memo;
vector<vector<bool>> chosen;

bool subset_sum(int sum, int i = 0, int csum = 0) {
    if (csum > sum) return false;
    if (csum == sum) return true;
    if (i >= N) return false;

    int &ans = memo[i][csum];
    if (~ans) return ans;

    if (subset_sum(sum, i + 1, csum)) return true;
    if (subset_sum(sum, i + 1, csum + a[i])) {
        chosen[i][csum] = true;
        return ans = true;
    }

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int sum = 0;
    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum & 1) {
        cout << "-1\n";
        return 0;
    }

    memo.assign(N + 5, vector<int>(sum + 5, -1));
    chosen.assign(N + 5, vector<bool>(sum + 5, false));

    if (!subset_sum(sum >> 1)) {
        cout << "-1\n";
        return 0;
    }

    int csum = 0;
    vector<int> alice, bob;

    for (int i = 0; i < N; i++) {
        if (!chosen[i][csum]) alice.push_back(a[i]);
        else {
            bob.push_back(a[i]);
            csum += a[i];
        }
    }

    vector<int> ans;
    int ialice = 0, salice = 0;
    int ibob = 0, sbob = 0;

    while (ialice < (int) alice.size() || ibob < (int) bob.size()) {
        if (salice <= sbob) {
            assert(ialice < (int) alice.size());
            ans.push_back(alice[ialice]);
            salice += alice[ialice++];
        } else {
            assert(ibob < (int) bob.size());
            ans.push_back(bob[ibob]);
            sbob += bob[ibob++];
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}