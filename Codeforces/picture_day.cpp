#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    n /= 2;

    pair<int, int> h[MAX];
    for (int i = 0; i < n; i++) {
        cin >> h[i].first >> h[i].second;
        if (h[i].first > h[i].second) swap(h[i].first, h[i].second);
    }

    sort(h, h + n);

    vector<pair<int, int>> nd, ni;
    for (int i = 0; i < n; i++) {
        bool fit_nd = nd.empty() || h[i].first >= nd.back().second;
        bool fit_ni = ni.empty() || h[i].first >= ni.back().second;

        if (fit_nd && fit_ni) {
            if (nd.empty()) ni.push_back(h[i]);
            else if (ni.empty()) nd.push_back(h[i]);
            else if (nd.back().second > ni.back().second) nd.push_back(h[i]);
            else ni.push_back(h[i]);
        }
        else if (fit_nd) nd.push_back(h[i]);
        else if (fit_ni) ni.push_back(h[i]);
        else {
            cout << "-1\n";
            return 0;
        }
    }

    for (auto p: nd) cout << p.first << " " << p.second << " ";

    reverse(ni.begin(), ni.end());
    for (auto p: ni) cout << p.second << " " << p.first << " ";

    cout << "\n";
}