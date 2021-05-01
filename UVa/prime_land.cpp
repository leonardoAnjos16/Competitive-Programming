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

int exp(int b, int n) {
    if (!n) return 1;

    int aux = exp(b, n / 2);
    if (!(n & 1)) return aux * aux;
    else return aux * aux * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line), line != "0") {
        stringstream aux(line);

        int p, e, n = 1;
        while (aux >> p >> e)
            n *= exp(p, e);

        n--;
        vi factors;

        for (int i = 2; i * i <= n; i++)
            while (!(n % i)) factors.pb(i), n /= i;

        if (n > 1) factors.pb(n);

        vector<pii> ans;
        ans.pb({ factors[0], 1 });

        for (int i = 1; i < size(factors); i++) {
            if (factors[i] == factors[i - 1]) ans[size(ans) - 1].snd++;
            else ans.pb({ factors[i], 1 });
        }

        reverse(all(ans));
        for (int i = 0; i < size(ans); i++) {
            if (i) cout << " ";
            cout << ans[i].fst << " " << ans[i].snd;
        }

        cout << "\n";
    }
}