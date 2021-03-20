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

const int MAX = 5e5 + 5;

int n; long m[MAX];
long s[2][MAX];

void get_sums(int j) {
    set<pll> aux;
    aux.emplace(m[0], 0);
    s[j][0] = m[0];

    for (int i = 1; i < n; i++) {
        auto it = aux.ub(make_pair(m[i], -1));

        if (it == aux.begin()) s[j][i] = m[i] * (i + 1), aux.clear();
        else {
            s[j][i] = s[j][(--it)->snd] + m[i] * (i - it->snd);
            aux.erase(++it, aux.end());
        }

        aux.emplace(m[i], i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i];

    get_sums(0);
    reverse(m, m + n);

    get_sums(1);
    reverse(m, m + n);
    reverse(s[1], s[1] + n);

    long mx_sum = 0; int idx = 0;
    for (int i = 0; i < n; i++) {
        long sum = s[0][i] + s[1][i] - m[i];
        if (sum > mx_sum) {
            idx = i;
            mx_sum = sum;
        }
    }

    long ans[MAX];
    ans[idx] = m[idx];

    for (int i = idx - 1; i >= 0; i--)
        ans[i] = min(m[i], ans[i + 1]);

    for (int i = idx + 1; i < n; i++)
        ans[i] = min(m[i], ans[i - 1]);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}