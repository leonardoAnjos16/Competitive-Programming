#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks[i] = make_pair(a, d);
    }

    sort(tasks.begin(), tasks.end());

    llong time = 0LL, ans = 0LL;
    for (int i = 0; i < n; i++) {
        time += tasks[i].first;
        ans += tasks[i].second - time;
    }

    cout << ans << "\n";
}