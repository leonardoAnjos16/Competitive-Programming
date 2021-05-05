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
        string s; cin >> s;

        set<char> seen;
        bool suspicious = false;

        for (int i = 1; i < n && !suspicious; i++) {
            if (s[i] != s[i - 1]) {
                if (seen.count(s[i - 1])) suspicious = true;
                else seen.insert(s[i - 1]);
            }
        }

        if (seen.count(s[n - 1])) suspicious = true;
        cout << (suspicious ? "NO" : "YES") << "\n";
    }
}