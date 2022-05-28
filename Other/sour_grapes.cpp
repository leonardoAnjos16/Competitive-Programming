#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string S; cin >> S;

    int dum = 0;
    multiset<int> sums;
    sums.insert(0);

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'C') dum++;
        else if (S[i] == 'R') dum--;
        else dum -= 2;

        sums.insert(dum);
    }

    int dee = 0, ans = max(0, dum);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'C') dee--;
        else if (S[i] == 'R') dee++;
        else dee -= 2;

        sums.erase(sums.lower_bound(dum));
        if (S[i] == 'C') dum--;
        else if (S[i] == 'R') dum++;
        else dum += 2;

        auto it = sums.end(); it--;
        ans = max(ans, dee + *it);
    }

    cout << ans << "\n";
}