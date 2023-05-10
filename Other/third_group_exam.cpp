#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> y(n);
    for (int i = 0; i < n; i++)
        cin >> y[i];

    string ans(n, '-');
    int grade = 0, theory = 0, practice = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ttop, ptot;

    for (int i = 0; i < n; i++) {
        if (x[i] >= y[i]) grade += x[i], theory++, ttop.emplace(x[i] - y[i], i), ans[i] = 'T';
        else grade += y[i], practice++, ptot.emplace(y[i] - x[i], i), ans[i] = 'P';
    }

    while (theory < a) {
        grade -= ptot.top().first;
        ans[ptot.top().second] = 'T';
        ptot.pop();
        practice--;
        theory++;
    }

    while (practice < b) {
        grade -= ttop.top().first;
        ans[ttop.top().second] = 'P';
        ttop.pop();
        practice++;
        theory--;
    }

    cout << grade << "\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}