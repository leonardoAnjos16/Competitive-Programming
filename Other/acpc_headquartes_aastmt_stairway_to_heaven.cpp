#include <bits/stdc++.h>

using namespace std;

const int MAX = 400;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        map<string, vector<pair<int, int>>> contests;
        while (N--) {
            string C; int S, E, V;
            cin >> C >> S >> E >> V;

            while (V--) {
                string name; cin >> name;
                contests[name].emplace_back(S, E);
            }
        }

        vector<string> ans;
        for (auto [name, dates]: contests) {
            int cnt[MAX] = {0};
            for (auto [S, E]: dates) {
                cnt[S]++;
                cnt[E + 1]--;
            }

            bool conflict = false;
            for (int i = 1; i < MAX && !conflict; i++) {
                cnt[i] += cnt[i - 1];
                if (cnt[i] > 1) conflict = true;
            }

            if (conflict) ans.push_back(name);
        }

        int cnt = ans.size();
        cout << cnt << "\n";

        for (string name: ans)
            cout << name << "\n";
    }
}