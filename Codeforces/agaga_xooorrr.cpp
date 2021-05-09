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

const int MAX = 2e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int a[MAX], acc[MAX] = {0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            acc[i] = acc[i - 1] ^ a[i];
        }

        bool possible = false;
        for (int i = 1; i < n && !possible; i++)
            if (acc[i] == (acc[n] ^ acc[i])) possible = true;

        for (int i = 2; i < n && !possible; i++)
            for (int j = i; j < n && !possible; j++)
                if (acc[i - 1] == (acc[j] ^ acc[i - 1]) && acc[i - 1] == (acc[n] ^ acc[j]))
                    possible = true;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}