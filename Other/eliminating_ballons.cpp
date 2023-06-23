#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int cnt[MAX] = {0}, ans = 0;
    for (int i = 0; i < N; i++) {
        int H; cin >> H;

        cnt[H]++;
        if (!cnt[H + 1]) ans++;
        else cnt[H + 1]--;
    }

    cout << ans << "\n";
}