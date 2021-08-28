#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    while (cin >> s >> t) {
        int n = s.size();
        int m = t.size();

        int sz = m / n;
        vector<string> strs;

        for (int i = 0; i < m; i += sz)
            strs.push_back(t.substr(i, sz));

        vector<pair<char, int>> aux(n);
        for (int i = 0; i < n; i++)
            aux[i] = make_pair(s[i], i);

        sort(aux.begin(), aux.end());

        vector<string> order(n);
        for (int i = 0; i < n; i++)
            order[aux[i].second] = strs[i];

        string ans = "";
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < n; j++)
                ans += order[j][i];

        cout << ans << "\n";
    }
}