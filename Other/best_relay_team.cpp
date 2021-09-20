#include <bits/stdc++.h>

using namespace std;

const long double INF = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<string> names(n);
    vector<long double> first(n);
    vector<pair<long double, int>> other(n);

    for (int i = 0; i < n; i++) {
        cin >> names[i] >> first[i] >> other[i].first;
        other[i].second = i;
    }

    sort(other.begin(), other.end());

    array<int, 4> chosen;
    long double ans = INF;

    for (int i = 0; i < n; i++) {
        array<int, 3> curr;
        long double time = first[i];

        bool equal = false;
        for (int j = 0; j < 3; j++) {
            if (other[j].second == i) equal = true;

            if (!equal) time += other[j].first, curr[j] = other[j].second;
            else time += other[j + 1].first, curr[j] = other[j + 1].second;
        }

        if (time < ans) {
            ans = time;
            chosen[0] = i;

            for (int j = 0; j < 3; j++)
                chosen[j + 1] = curr[j];
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < 4; i++)
        cout << names[chosen[i]] << "\n";
}