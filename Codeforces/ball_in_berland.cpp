#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;

        map<int, int> boys, girls;
        map<pair<int, int>, int> pairs;

        vector<pair<int, int>> A(k);
        for (int i = 0; i < k; i++)
            cin >> A[i].first;

        for (int i = 0; i < k; i++)
            cin >> A[i].second;

        long ans = 0LL;
        for (int i = 0; i < k; i++) {
            ans += i - boys[A[i].first] - girls[A[i].second] + pairs[A[i]];
            boys[A[i].first]++; girls[A[i].second]++; pairs[A[i]]++;
        }

        cout << ans << "\n";
    }
}