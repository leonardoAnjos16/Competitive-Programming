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

long gcd(long a, long b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    cin.ignore();

    while (N--) {
        string line;
        getline(cin, line);
        stringstream aux(line);

        long a[MAX], sz = 0;
        while (aux >> a[sz++]);

        long ans = 0; sz--;
        for (int i = 0; i < sz - 1; i++)
            for (int j = i + 1; j < sz; j++)
                ans = max(ans, gcd(a[i], a[j]));

        cout << ans << "\n";
    }
}