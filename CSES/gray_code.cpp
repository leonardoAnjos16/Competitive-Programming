#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<string> ans;

void solve(int n) {
    if (n == 1) ans = vector<string>({ "0", "1" });
    else {
        solve(n - 1);

        int size = ans.size();
        for (int i = size - 1; i >= 0; i--) {
            ans.push_back("1" + ans[i]);
            ans[i] = "0" + ans[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    solve(n);
    for (string s: ans)
        cout << s << "\n";
}