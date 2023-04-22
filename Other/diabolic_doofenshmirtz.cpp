#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong ask(llong t) {
    cout << "? " << t << "\n";
    cout.flush();

    llong x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong t = 1LL, ans;
    while ((ans = ask(t)) == t)
        t <<= 1LL;

    ans = t - ans;
    cout << "! " << ans << "\n";
    cout.flush();
}