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

const int BASE = 257;
const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

vector<long> powers;

long get_hash(vector<long> &h, int l, int r) {
    if (!l) return h[r];
    return (h[r] - ((h[l - 1] * powers[r - l + 1]) % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    powers.assign(1, 1LL);
    for (int i = 1; i < MAX; i++)
        powers.pb((powers[i - 1] * BASE) % MOD);

    int T; cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;

        vector<long> hA(1, A[0]);
        for (int i = 1; i < size(A); i++)
            hA.pb((hA[i - 1] * BASE + A[i]) % MOD);

        vector<long> hB(1, B[0]);
        for (int i = 1; i < size(B); i++)
            hB.pb((hB[i - 1] * BASE + B[i]) % MOD);

        vi ans;
        for (int i = 0; i + size(B) < size(A) + 1; i++)
            if (get_hash(hA, i, i + size(B) - 1) == hB[size(B) - 1])
                ans.pb(i + 1);

        if (ans.empty()) cout << "Not Found\n";
        else {
            cout << size(ans) << "\n";
            for (int i: ans) cout << i << " ";
            cout << "\n";
        }

        if (T) cout << "\n";
    }
}