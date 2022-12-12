#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, w, m;
    cin >> d >> w >> m;

    string ans = w + m <= d || w > d ? "good luck" : "see you next semester";
    cout << ans << "\n";
}