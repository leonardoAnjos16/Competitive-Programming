#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int count(vector<int> &t, vector<int> &s1, vector<int> &s2) {
    int ans = 0;
    for (int i = 0; i < (int) t.size(); i++) {
        auto it = find(s1.begin(), s1.end(), t[i]);
        if (it != s1.end()) {
            ans++;
            s1.erase(it);
            s2.push_back(t[i]);
        } else {
            bool two = false;
            it = find(s2.begin(), s2.end(), t[i]);

            for (int j = 0; j < i && !two; j++)
                if (it < find(s2.begin(), s2.end(), t[j]))
                    two = true;

            if (two) {
                ans += 2;
                s2.erase(it);
                s2.push_back(t[i]);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, u;
    cin >> p >> u;

    vector<int> sp(p);
    for (int i = 0; i < p; i++)
        cin >> sp[i];

    vector<int> su(u);
    for (int i = 0; i < u; i++)
        cin >> su[i];

    reverse(su.begin(), su.end());

    cin >> p >> u;

    vector<int> ep(p);
    for (int i = 0; i < p; i++)
        cin >> ep[i];

    vector<int> eu(u);
    for (int i = 0; i < u; i++)
        cin >> eu[i];

    reverse(eu.begin(), eu.end());

    int ans = count(ep, su, sp);
    ans += count(eu, sp, su);
    cout << ans << "\n";
}