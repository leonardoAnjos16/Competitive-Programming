#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 55;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans[MAX] = { 0, 4 };

    bool three = true;
    for (int i = 2; i < MAX; i++) {
        ans[i] = ans[i - 1] + (three ? 3 : 4);
        three = !three;
    }

    int N; cin >> N;
    cout << ans[N] << "\n";
}