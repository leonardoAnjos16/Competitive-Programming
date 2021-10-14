#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> curr;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(curr.begin(), curr.end(), x[i]);
        if (it == curr.end()) curr.push_back(x[i]);
        else curr[it - curr.begin()] = x[i];
    }

    int ans = curr.size();
    cout << ans << "\n";
}