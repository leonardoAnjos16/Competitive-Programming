#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> tools(n);
    for (int i = 0; i < n; i++)
        tools[i] = vector<int>(1, i);

    while (q--) {
        int s, t;
        cin >> s >> t;

        for (int tool: tools[s - 1])
            tools[t - 1].push_back(tool);

        vector<int>().swap(tools[s - 1]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        for (int tool: tools[i])
            ans[tool] = i + 1;

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}