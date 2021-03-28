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

const int MAX = 105;

int n, a[MAX];
int factors[MAX];

int memo[MAX][1 << 16];
int chosen[MAX][1 << 16];

int sum(int i = 0, int used = 0) {
    if (i >= n) return 0;

    int &ans = memo[i][used];
    if (~ans) return ans;

    chosen[i][used] = 1;
    ans = a[i] - 1 + sum(i + 1, used);

    if (used + 1 == (1 << 16)) return ans;

    for (int j = 2; j <= 53; j++) {
        bool possible = !(used & factors[j]);
        if (possible) {
            int aux = abs(a[i] - j) + sum(i + 1, used | factors[j]);
            if (aux < ans) {
                ans = aux;
                chosen[i][used] = j;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = factors[1] = 0;
    unordered_map<int, int> primes;

    for (int i = 2; i <= 53; i++) {
        int prime = 2;
        while (i % prime) prime++;

        if (prime == i) primes[i] = cnt++;
        factors[i] = factors[i / prime] | (1 << primes[prime]);
    }

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(memo, -1, sizeof memo);

    vi ans(n); sum();
    ans[0] = chosen[0][0];

    for (int i = 1, used = factors[ans[0]]; i < n; used |= factors[ans[i++]])
        ans[i] = chosen[i][used];

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}