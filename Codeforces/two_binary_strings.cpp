#include <bits/stdc++.h>

using namespace std;

string a, b;
vector<int> memo;

bool possible(int i = 0) {
    if (i >= (int) a.size()) return true;
    if (a[i] != b[i]) return false;

    int &ans = memo[i];
    if (~ans) return ans;

    for (int j = i; j < (int) a.size(); j++)
        if (a[j] == a[i] && b[j] == b[i] && possible(j + 1))
            return ans = true;

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> a >> b;

        memo.assign((int) a.size() + 5, -1);

        cout << (possible() ? "YES" : "NO") << "\n";
    }
}