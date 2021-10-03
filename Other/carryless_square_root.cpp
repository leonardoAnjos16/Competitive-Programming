#include <bits/stdc++.h>

using namespace std;

#define long long long int

int k;
vector<int> a, c;
bool done = false;

void solve(int i = 0) {
    if (done) return;
    if (i >= k) {
        done = true;
        return;
    }

    if (i >= (k + 1) / 2) {
        int sum = 0;
        for(int j = k / 2, l = i - j; l <= k / 2; l++, j--){
            sum += a[j] * a[l];
            sum %= 10;
        }

        if(sum == c[i])
            solve(i + 1);
    } else {
        int sum = 0;
        for (int j = 1, l = i - 1; j < i; j++, l--) {
            sum += a[j] * a[l];
            sum %= 10;
        }

        for (int d = 0; d < 10 && !done; d++) {
            a[i] = d;
            if ((sum + (!i ? a[i] * a[i] : 2 * a[0] * a[i])) % 10 == c[i])
                solve(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n; cin >> n;
    k = n.size();

    c.resize(k);
    for (int i = 0; i < k; i++)
        c[i] = n[i] - '0';

    int sz = (k + 1) / 2;
    a.resize(sz);

    solve();

    if (!done) cout << "-1\n";
    else {
        for (auto d: a)
            cout << d;

        cout << "\n";
    }
}