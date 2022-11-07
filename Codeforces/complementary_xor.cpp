#include <bits/stdc++.h>

using namespace std;

#define llong long long int

string opposite(string s) {
    for (int i = 0; i < (int) s.size(); i++)
        s[i] = s[i] == '0' ? '1' : '0';

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a; cin >> a;
        string b; cin >> b;

        if (a != b && a != opposite(b)) cout << "NO\n";
        else {
            int idx = 0;
            set<pair<int, int>> ranges[2];

            while (idx < n) {
                int l = idx;
                while (idx + 1 < n && a[idx + 1] == a[idx]) idx++;
                ranges[a[idx] - '0'].emplace(l + 1, idx + 1);
                idx++;
            }

            vector<pair<int, int>> ans;
            bool equal = a == b, possible = true;

            while (!ranges[1].empty() && possible) {
                if (equal) {
                    if (ranges[0].empty()) {
                        ans.emplace_back(1, 1);
                        ranges[0].emplace(1, 1);

                        if (n == 1) possible = false;
                        else {
                            ranges[1].erase(ranges[1].begin());
                            ranges[1].emplace(2, n);
                        }
                    } else {
                        auto it = ranges[0].begin();
                        auto [l, r] = *it;

                        ans.emplace_back(l, r);
                        ranges[0].erase(it);

                        if (l > 1) {
                            l = 1;
                            ranges[1].erase(ranges[1].begin());
                        }

                        if (r < n) {
                            r = get<1>(*ranges[1].begin());
                            ranges[1].erase(ranges[1].begin());
                        }

                        ranges[1].emplace(l, r);
                    }
                } else {
                    auto it = ranges[1].begin();
                    auto [l, r] = *it;

                    ans.emplace_back(l, r);
                    ranges[1].erase(it);

                    if (l > 1) {
                        l = 1;
                        ranges[0].erase(ranges[0].begin());
                    }

                    if (r < n) {
                        r = get<1>(*ranges[0].begin());
                        ranges[0].erase(ranges[0].begin());
                    }

                    ranges[0].emplace(l, r);
                }

                equal = !equal;
            }

            if (possible && !equal) {
                if (n == 1) possible = false;
                else {
                    ans.emplace_back(1, 1);
                    ans.emplace_back(2, n);
                    ans.emplace_back(1, n);
                }
            }

            if (!possible) cout << "NO\n";
            else {
                cout << "YES\n";

                int size = ans.size();
                cout << size << "\n";

                for (auto [l, r]: ans)
                    cout << l << " " << r << "\n";
            }
        }
    }
}