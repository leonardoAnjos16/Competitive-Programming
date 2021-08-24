#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool average = false;
        for (int j = 0; j < N && !average; j++) {
            int idx = lower_bound(a.begin(), a.end(), 2 * a[i] - a[j]) - a.begin();
            if (idx < N && idx != j && a[idx] == 2 * a[i] - a[j]) average = true;
        }

        ans += average;
    }

    cout << ans << "\n";
}