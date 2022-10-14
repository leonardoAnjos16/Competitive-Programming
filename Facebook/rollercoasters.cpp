#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int scariness;
    vector<int> A;

    while (cin >> scariness)
        A.push_back(scariness);

    int n = A.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while (i + cnt < n && A[i + cnt] > A[i + cnt - 1]) cnt++;
        ans = max(ans, cnt);
    }

    ans *= 10;
    cout << ans << "\n";
}