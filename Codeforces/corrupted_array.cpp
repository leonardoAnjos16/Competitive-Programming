#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        long b[MAX]; long sum = 0LL;
        for (int i = 0; i < n + 2; i++) {
            cin >> b[i];
            sum += b[i];
        }

        sort(b, b + n + 2);

        bool possible = false;
        for (int i = 0; i < n + 2 && !possible; i++) {
            if ((sum - b[i]) & 1) continue;

            long aux = (sum - b[i]) >> 1;
            int idx = lb(b, b + n + 2, aux) - b;

            if (idx >= n + 2 || b[idx] > aux || (idx == i && (idx + 1 >= n + 2 || b[idx + 1] > aux))) continue;

            if (idx == i) idx++;
            for (int j = 0; j < n + 2; j++) {
                if (j == i || j == idx) continue;
                cout << b[j] << " ";
            }

            cout << "\n";
            possible = true;
        }

        if (!possible) cout << "-1\n";
    }
}