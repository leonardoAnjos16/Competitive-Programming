#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        int zeros = 0, sum = 0;
        priority_queue<int> neg, pos;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (!a) zeros++;
            else if (a < 0) neg.push(-a);
            else pos.push(-a);
            sum += a;
        }

        while (k--) {
            if (!neg.empty()) {
                sum += 2 * neg.top();
                pos.push(-neg.top());
                neg.pop();
            } else if (!zeros) {
                sum += 2 * pos.top();
                neg.push(-pos.top());
                pos.pop();
            }
        }

        cout << sum << "\n";
    }
}