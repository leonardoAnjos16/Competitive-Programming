#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        map<int, int> cnt;
        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;
            cnt[A]++;
        }

        priority_queue<int> heap;
        for (auto p: cnt)
            heap.push(p.second);

        while (K-- && heap.top() > 1) {
            int top = heap.top();
            heap.pop();
            heap.push(1);
            heap.push(top - 1);
        }

        long ans = 0LL;
        while (!heap.empty()) {
            ans += 1LL * heap.top() * (N - heap.top());
            heap.pop();
        }

        ans /= 2LL;
        cout << ans << "\n";
    }
}