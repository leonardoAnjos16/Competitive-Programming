#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> cnt[MAX];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        int curr[MAX] = {0};
        for (char c: s)
            curr[c - 'a']++;

        for (int j = 0; j < MAX; j++)
            cnt[j].push_back(curr[j]);
    }

    priority_queue<pair<int, char>> heap;
    for (int i = 0; i < MAX; i++) {
        sort(cnt[i].begin(), cnt[i].end());

        int aux = cnt[i].end() - upper_bound(cnt[i].begin(), cnt[i].end(), 0);
        heap.emplace(aux, 'a' + i);
    }

    string ans = "";
    int size = 0, curr[MAX] = {0};

    while (size < m) {
        auto [gain, c] = heap.top(); heap.pop();
        curr[c - 'a']++;
        ans += c;
        size++;

        int aux = cnt[c - 'a'].end() - upper_bound(cnt[c - 'a'].begin(), cnt[c - 'a'].end(), curr[c - 'a']);
        heap.emplace(aux, c);
    }

    cout << ans << "\n";
}