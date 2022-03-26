#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k;
    cin >> n >> d >> k;

    vector<pair<int, string>> employees(n);
    for (int i = 0; i < n; i++) {
        string s; int c;
        cin >> s >> c;
        employees[i] = make_pair(c, s);
    }

    sort(employees.rbegin(), employees.rend());

    int cnt = 0, sum = 0;
    while (cnt < k && sum < d)
        sum += employees[cnt++].first;

    if (sum < d) cout << "impossible\n";
    else {
        cout << cnt << "\n";
        for (int i = 0; i < cnt; i++)
            cout << employees[i].second << ", YOU ARE FIRED!\n";
    }
}