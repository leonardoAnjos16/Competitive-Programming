#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int q[MAX];
    for (int i = 1; i < n; i++)
        cin >> q[i];

    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;

        int p[MAX];
        bitset<MAX> used;

        p[0] = mid;
        used[mid] = true;

        bool possible = true;
        for (int i = 1; i < n && possible; i++) {
            int next = p[i - 1] + q[i];

            if (next < 1) l = mid + 1, possible = false;
            else if (next > n) r = mid - 1, possible = false;
            else if (used[next]) l = r + 1, possible = false;
            else p[i] = next, used[next] = true;
        }

        if (possible) {
            for (int i = 0; i < n; i++)
                cout << p[i] << " ";

            cout << "\n";
            return 0;
        }
    }

    cout << "-1\n";
}