#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 50;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long two_pots[MAX] = { 1LL };
    for (int i = 1; i < MAX; i++)
        two_pots[i] = two_pots[i - 1] << 1LL;

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 1; i < n; i++) {
        if (a[i] % a[0]) {
            cout << "-1\n";
            return 0;
        }

        a[i] /= a[0];
        if (!binary_search(two_pots, two_pots + MAX, a[i])) {
            cout << "-1\n";
            return 0;
        }
    }

    a[0] = 1;
    
    map<long, long> cnt;
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;

    long ans = 0LL;
    while ((int) cnt.size() > 1 || cnt.begin()->second > 1LL) {
        pair<long, long> aux = *cnt.begin();
        cnt.erase(cnt.begin());

        if (aux.second & 1LL) aux.second++, ans++;
        cnt[aux.first << 1LL] += (aux.second >> 1LL);
    }

    cout << ans << "\n";
}