#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble EPS = 1e-9;

template<class T, class C = greater<T>>
struct MinQueue {
    MinQueue() { clear(); }

    void clear() {
        id = 0;
        q.clear();
    }

    void push(T x) {
        pair<int, T> nxt(1, x);
        while (q.size() > id && cmp(q.back().second, x)) {
            nxt.first += q.back().first;
            q.pop_back();
        }

        q.push_back(nxt);
    }

    T qry() { return q[id].second; }

    void pop() {
        q[id].first--;
        if (q[id].first == 0) { id++; }
    }

private:
    vector<pair<int, T>> q;
    int id;
    C cmp;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(12) << fixed;

    int N; cin >> N;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    vector<llong> ps(2 * N + 1, 0LL);
    for (int i = 1; i <= 2 * N; i++)
        ps[i] = ps[i - 1] + a[i <= N ? i : i - N];

    ldouble l = 0.0L, r = 2e9;
    for (int i = 0; i < 200; i++) {
        ldouble m = (l + r) / 2.0L;

        MinQueue<ldouble> q;
        for (int j = 1; j <= N; j++)
            q.push(ps[j] - m * j);

        bool possible = false;
        for (int j = N + 1; j <= 2 * N && !possible; j++) {
            ldouble v = ps[j] - m * j;
            if (q.qry() - v <= EPS) possible = true;
            q.pop();
        }

        if (possible) l = m;
        else r = m;
    }

    ldouble ans = (l + r) / 2.0L;
    for (int i = 0; i <= N; i++)
        ans = max(ans, (ldouble) (ps[N] - ps[i]) / (N - i));

    cout << ans << "\n";
}