#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct Queue {
private:
    stack<int> dequeue;
    stack<pair<int, int>> enqueue;

public:
    void push(int v) {
        int mx = v;
        if (!enqueue.empty() && enqueue.top().second > v)
            mx = enqueue.top().second;
        
        enqueue.emplace(v, mx);
    }

    void pop() {
        if (dequeue.empty()) move();
        dequeue.pop();
    }

    int min() {
        if (dequeue.empty()) move();

        int ans = dequeue.top();
        if (!enqueue.empty() && enqueue.top().second > ans)
            ans = enqueue.top().second;

        return ans;
    }

private:
    void move() {
        while (!enqueue.empty()) {
            int top = enqueue.top().first;
            if (!dequeue.empty() && dequeue.top() > top)
                top = dequeue.top();

            dequeue.push(top);
            enqueue.pop();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (q--) {
        int d; cin >> d;

        Queue aux;
        for (int i = 0; i < d; i++)
            aux.push(arr[i]);

        int ans = aux.min();
        for (int i = d; i < n; i++) {
            aux.pop();
            aux.push(arr[i]);
            ans = min(ans, aux.min());
        }

        cout << ans << "\n";
    }
}