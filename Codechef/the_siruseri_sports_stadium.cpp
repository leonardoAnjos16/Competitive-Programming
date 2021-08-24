#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<pair<int, int>> events;
vector<int> memo;

int max_events(int i) {
    if (i >= N) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = max_events(i + 1);

    pair<int, int> aux = make_pair(events[i].first + events[i].second, INT_MAX);
    int nxt = upper_bound(events.begin(), events.end(), aux) - events.begin();
    ans = max(ans, max_events(nxt) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    events.resize(N);
    for (int i = 0; i < N; i++) {
        int S, D;
        cin >> S >> D;
        events[i] = make_pair(S, D);
    }

    sort(events.begin(), events.end());
    memo.assign(N + 5, -1);

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, max_events(i));

    cout << ans << "\n";
}