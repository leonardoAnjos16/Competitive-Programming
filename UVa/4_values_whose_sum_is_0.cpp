#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> A(n), B(n), C(n), D(n);
        for (int i = 0; i < n; i++)
            cin >> A[i] >> B[i] >> C[i] >> D[i];

        vector<int> AB, CD;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                AB.push_back(A[i] + B[j]);
                CD.push_back(C[i] + D[j]);
            }

        sort(all(AB));
        sort(all(CD));

        int ans = 0;
        for (int i = 0; i < size(AB); i++) {
            auto lb = lower_bound(all(CD), -AB[i]);
            auto ub = upper_bound(all(CD), -AB[i]);
            ans += ub - lb;
        }

        cout << ans << "\n";
        if (t) cout << "\n";
    }
}