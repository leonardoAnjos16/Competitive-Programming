#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    priority_queue<llong, vector<llong>, greater<llong>> heap;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;

        if (i)
            while (!(p & 1) && (heap.top() << 1LL) < p) {
                heap.push(heap.top() << 1LL);
                heap.pop();
                p >>= 1;
            }

        heap.push(p);
    }

    llong ans = LLONG_MIN;
    while (!heap.empty()) {
        ans = heap.top();
        heap.pop();
    }

    cout << ans << "\n";
}