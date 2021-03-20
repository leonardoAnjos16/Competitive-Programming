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

const int MAX = 1e3 + 5;
const int MOD = 1e9 + 7;

int n, a[30];
string s;

pii memo[MAX];
int max_l = 1;

pii splits(int i = 0) {
    if (i >= n) return { 1, 0 };

    pii &ans = memo[i];
    if (~ans.fst) return ans;

    ans = splits(i + 1);
    ans.fst %= MOD;
    ans.snd++;

    int mn = a[s[i] - 'a'], l = 1;
    for (int j = i + 1; j < n; j++) {
        mn = min(mn, a[s[j] - 'a']);
        if (mn < ++l) break;

        pii aux = splits(j + 1);
        ans.fst += aux.fst;
        ans.fst %= MOD;

        max_l = max(max_l, l);
        ans.snd = min(ans.snd, aux.snd + 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    for (int i = 0; i < 26; i++)
        cin >> a[i];

    for (int i = 0; i <= n; i++)
        memo[i] = { -1, -1 };
    
    pii ans = splits();
    cout << ans.fst << "\n";
    cout << max_l << "\n";
    cout << ans.snd << "\n";
}