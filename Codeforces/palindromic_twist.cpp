#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        bool possible = true;
        for (int i = 0; i < n / 2 && possible; i++)
            if (s[i] != s[n - i - 1] && abs(s[i] - s[n - i - 1]) != 2)
                possible = false;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}