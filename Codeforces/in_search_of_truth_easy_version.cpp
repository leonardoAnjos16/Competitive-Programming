#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;
const int SQRT = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x; cin >> x;

    bool marked[MAX] = {0};
    int dist[MAX] = {0};
    marked[x] = true;

    for (int i = 1; i < SQRT; i++) {
        cout << "+ 1\n";
        cout.flush();

        cin >> x;

        if (marked[x]) {
            cout << "! " << i << "\n";
            cout.flush();
            return 0;
        }

        marked[x] = true;
        dist[x] = i;
    }

    int cnt = 0;
    bool seen = false;

    for (int i = 1; i <= SQRT && !seen; i++) {
        cout << "+ " << SQRT << "\n";
        cout.flush();

        cin >> x;

        cnt++;
        if (marked[x])
            seen = true;
    }

    int ans = cnt * SQRT + SQRT - dist[x] - 1;
    cout << "! " << ans << "\n";
    cout.flush();
}