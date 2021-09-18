#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 50;

int sum_digits(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int unluckiness(int n) {
    return abs(sum_digits(n / 1000) - sum_digits(n % 1000));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        int ti; cin >> ti;
        t[i] = make_pair(ti, i);
    }

    sort(t.begin(), t.end());

    int cnt[MAX] = {0};
    vector<int> ans(n, 0);

    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (i && t[i].first == t[i - 1].first)
            ans[t[i].second] = ans[t[i - 1].second];
        else {
            while (curr < t[i].first)
                cnt[unluckiness(curr++)]++;

            int aux = unluckiness(t[i].first);
            for (int j = 0; j < aux; j++)
                ans[t[i].second] += cnt[j];
        }
    }

    for (auto a: ans) cout << a << "\n";
}