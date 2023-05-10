#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

template<typename T>
struct MinQueue {
private:
    queue<T> q;
    deque<T> mn;

public:
    void push(T v) {
        q.push(v);
        while (!mn.empty() && mn.back() > v)
            mn.pop_back();

        mn.push_back(v);
    }

    void pop() {
        assert(!q.empty());
        if (q.front() == mn.front())
            mn.pop_front();

        q.pop();
    }

    T min() {
        assert(!q.empty());
        return mn.front();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> s(m + 1);
    vector<int> t(m + 1);

    for (int i = 1; i <= m; i++)
        cin >> s[i] >> t[i];

    s[0] = 1;
    t[0] = n;

    vector<int> dp(n + 1, INF);
    dp[1] = 0;

    for (int i = 1; i <= m; i++) {
        MinQueue<int> mq;
        int l = 1 - t[i - 1] + s[i - 1], r = 1 + t[i] - s[i];

        for (int j = max(l, 1); j <= min(r, n); j++)
            mq.push(dp[j]);

        vector<int> curr(n + 1, INF);
        for (int j = 1; j + t[i] - s[i] <= n; j++) {
            curr[j] = min(curr[j], mq.min() + abs(j - s[i]));
            if (l++ >= 1) mq.pop();
            if (++r <= n) mq.push(dp[r]);
        }

        dp.swap(curr);
    }

    int ans = *min_element(dp.begin(), dp.end());
    cout << ans << "\n";
}