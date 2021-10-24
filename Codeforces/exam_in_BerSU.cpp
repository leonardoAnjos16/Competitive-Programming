#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    cin >> n >> M;

    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int sum = 0;
    vector<int> ans(n, 0);
    priority_queue<int> heap;

    for (int i = 0; i < n; i++) {
        sum += t[i];
        vector<int> rem;

        while (sum > M) {
            rem.push_back(heap.top());
            sum -= heap.top();
            heap.pop();
            ans[i]++;
        }

        for (auto r: rem) {
            sum += r;
            heap.push(r);
        }
        
        heap.push(t[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}