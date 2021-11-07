#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int people[MAX];
    memset(people, -1, sizeof people);

    int mn = INT_MAX, dir = -1;
    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;
        people[t] = d;

        if (t < mn) {
            mn = t;
            dir = d;
        }
    }

    int ans = mn + 10;
    bool opposite = false;

    for (int i = mn + 1; i < MAX; i++) {
        if (i > ans) {
            if (!opposite) dir = -1;
            else {
                ans += 10;
                dir = 1 - dir;
                opposite = false;
            }
        }

        if (people[i] == -1) continue;
        if (dir == -1) dir = people[i];

        if (people[i] != dir) opposite = true;
        else ans = i + 10;
    }

    cout << ans << "\n";
}