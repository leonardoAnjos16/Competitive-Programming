#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;
const int INF = 2e6 + 5;

string v;
vector<int> pos[MAX];
vector<int> memo;

int missing(int i = 0) {
    int &ans = memo[i];
    if (~ans) return ans;

    for (char c: v)
        if (lower_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), i) == pos[c - 'a'].end())
            return ans = 1;

    ans = INF;
    for (char c: v) {
        auto it = lower_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), i);
        ans = min(ans, missing(*it + 1) + 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> v >> s;

    for (int i = 0; i < (int) s.size(); i++)
        pos[s[i] - 'a'].push_back(i);

    memo.assign((int) s.size() + 5, -1);

    int size = missing();

    int n; cin >> n;
    while (n--) {
        string q; cin >> q;

        int idx = -1;
        bool subsequence = true;

        for (char c: q) {
            auto it = upper_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), idx);
            if (it == pos[c - 'a'].end()) {
                subsequence = false;
                break;
            }

            idx = *it;
        }

        bool ans = !subsequence && (int) q.size() == size;
        cout << ans << "\n";
    }
}