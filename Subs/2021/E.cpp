#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    queue<int> times[2];
    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;
        times[d].push(t);
    }

    int available = INT_MAX, dir = -1;
    for (int i = 0; i < 2; i++)
        if (!times[i].empty() && times[i].front() + 10 < available)
            available = times[i].front() + 10, dir = i;

    times[dir].pop();
    while (!times[dir].empty() || !times[1 - dir].empty()) {
        if (!times[dir].empty() && (times[dir].front() < available || times[1 - dir].empty() || times[dir].front() < times[1 - dir].front())) {
            available = times[dir].front() + 10;
            times[dir].pop();
        } else {
            dir = 1 - dir;
            int navailable = max(available, times[dir].front()) + 10;
            while (!times[dir].empty() && times[dir].front() < available) times[dir].pop();
            available = navailable;
        }
    }

    cout << available << "\n";
}