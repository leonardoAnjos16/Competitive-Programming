#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }

    sort(s.rbegin(), s.rend());

    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += s[i].first;

    if (sum < s[0].first) cout << "impossible\n";
    else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << s[i].second;
        }

        cout << "\n";
    }
}