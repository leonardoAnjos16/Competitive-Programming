#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    vector<int> ordered(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ordered[i] = a[i];
    }

    sort(ordered.begin(), ordered.end());

    map<int, queue<int>> indices;
    for (int i = 0; i < n; i++)
        indices[ordered[i]].push(i);

    int ans = 0, idx = 0;
    while (idx < n) {
        int mx = a[idx];
        while (indices[mx].front() != idx) {
            if (a[idx + 1] <= mx) indices[a[++idx]].pop();
            else {
                indices[mx].pop();
                mx = a[++idx];
            }
        }

        ans++; idx++;
        indices[mx].pop();
    }

    cout << ans << "\n";
}