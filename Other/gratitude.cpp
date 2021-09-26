#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    cin.ignore();

    map<string, int> cnt;
    map<string, int> last;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            string s; getline(cin, s);
            cnt[s]++; last[s] = 3 * i + j;
        }
    }

    vector<tuple<int, int, string>> ans;
    for (auto [s, c]: cnt)
        ans.push_back(make_tuple(c, last[s], s));

    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < K && i < (int) ans.size(); i++)
        cout << get<2>(ans[i]) << "\n";
}