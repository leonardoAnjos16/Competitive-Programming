#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

struct FenwickTree {
private:
    int n;
    vector<llong> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    llong sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    llong sum(int i) {
        if (i < 0) return 0LL;

        llong ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t = 1;
    FenwickTree cnt_zo(MAX), sum_zo(MAX), cnt_oz(MAX), sum_oz(MAX);

    while (cin >> N, N) {
        string S, E;
        cin >> S >> E;

        vector<int> tax(N);
        for (int i = 0; i < N; i++)
            cin >> tax[i];

        llong sum = 0LL;
        vector<int> zo, oz, oo;

        for (int i = 0; i < N; i++) {
            if (S[i] == '0' && E[i] == '1') zo.push_back(tax[i]), cnt_zo.add(tax[i], 1), sum_zo.add(tax[i], tax[i]);
            else if (S[i] == '1' && E[i] == '0') oz.push_back(tax[i]), cnt_oz.add(tax[i], 1), sum_oz.add(tax[i], tax[i]);
            else if (S[i] == '1') oo.push_back(tax[i]), sum += tax[i];
        }

        sort(zo.begin(), zo.end());
        sort(oz.rbegin(), oz.rend());
        sort(oo.rbegin(), oo.rend());

        llong ans = 0LL;
        int czo = zo.size();
        int coz = oz.size();

        for (int i = 0; i < czo; i++)
            ans += 1LL * (czo - i) * zo[i];

        for (int i = 0; i < coz; i++)
            ans += 1LL * i * oz[i];

        for (int cost: oo)
            ans += 1LL * (czo + coz) * cost;

        llong curr = ans;
        int dist = czo + coz;

        for (int cost: oo) {
            llong diff = -1LL * dist * cost;
            diff += cnt_oz.sum(cost + 1, MAX) * cost + sum_oz.sum(0, cost);
            diff += (cnt_zo.sum(cost + 1, MAX) + 1LL) * cost + sum_zo.sum(0, cost);
            diff += 2LL * (sum - cost);

            curr += diff;
            ans = min(ans, curr);

            cnt_oz.add(cost, 1);
            cnt_zo.add(cost, 1);
            sum_oz.add(cost, cost);
            sum_zo.add(cost, cost);

            sum -= cost;
            dist += 2;
        }

        for (int i = 0; i < czo; i++) {
            cnt_zo.add(zo[i], -1);
            sum_zo.add(zo[i], -zo[i]);
        }

        for (int i = 0; i < coz; i++) {
            cnt_oz.add(oz[i], -1);
            sum_oz.add(oz[i], -oz[i]);
        }

        for (int cost: oo) {
            cnt_zo.add(cost, -1);
            cnt_oz.add(cost, -1);
            sum_zo.add(cost, -cost);
            sum_oz.add(cost, -cost);
        }

        cout << "Case " << t++ << ": " << ans << "\n";
    }
}