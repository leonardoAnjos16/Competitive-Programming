#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    set<int> ans;
    ans.insert(0);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        vector<int> sums;
        for (auto s: ans)
            sums.push_back(s + x);

        for (auto s: sums)
            ans.insert(s);
    }

    ans.erase(0);

    int k = ans.size();
    cout << k << "\n";

    for (auto s: ans)
        cout << s << " ";

    cout << "\n";
}