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

long fact(long n) {
    return !n ? 1 : fact(n - 1) * n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;

        int cnt[30] = {0};
        for (char c: s)
            cnt[c - 'A']++;

        long ans = fact(size(s));
        for (int i = 0; i < 26; i++)
            ans /= fact(cnt[i]);

        cout << "Data set " << t << ": " << ans << "\n";
    }
}