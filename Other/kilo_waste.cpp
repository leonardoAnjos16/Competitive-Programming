#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 5e4 + 5;

int p;
vector<int> rices;
int memo[MAX];

int waste(int rice) {
    if (rice <= 0) return -rice;

    int &ans = memo[rice];
    if (~ans) return ans;

    ans = INT_MAX;
    for (int i = 0; i < p; i++)
        ans = min(ans, waste(rice - rices[i]));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k >> p;

    rices.resize(p);
    for (int i = 0; i < p; i++)
        cin >> rices[i];

    memset(memo, -1, sizeof memo);

    for (int i = 0; i < k; i++) {
        int n; cin >> n;

        int ans = waste(n);
        cout << ans << "\n";
    }
}