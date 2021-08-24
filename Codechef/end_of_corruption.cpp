#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    priority_queue<int> heap;
    for (int i = 0; i < N + M; i++) {
        int wealth; cin >> wealth;
        if (~wealth) heap.push(wealth);
        else {
            int ans = heap.top(); heap.pop();
            cout << ans << "\n";
        }
    }
}