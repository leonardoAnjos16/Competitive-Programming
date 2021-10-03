#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<string> ans;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (t[i] != s[j]) {
                char aux = t[i];
                t[i] = s[j];
                ans.push_back(t);
                t[i] = aux;
            }

    for (int i = 0; i < m; i++) {
        string u = t.substr(0, i) + t.substr(i + 1);
        ans.push_back(u);
    }

    for (int i = 0; i <= m; i++)
        for (int j = 0; j < n; j++) {
            string u = t.substr(0, i) + s[j] + t.substr(i);
            ans.push_back(u);
        }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto a: ans)
        cout << a << "\n";
}