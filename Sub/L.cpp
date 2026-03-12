#include <bits/stdc++.h>

using namespace std;

const int MAX = 31;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int bits[MAX] = {0};
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        for (int j = 0; j < MAX; j++)
            if (a & (1 << j))
                bits[j]++;
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX; j++)
            if (bits[j]) {
                ans[i] |= 1 << j;
                bits[j]--;
            }

        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}