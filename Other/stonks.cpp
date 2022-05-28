#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    map<string, int> original, current, time;
    priority_queue<tuple<int, int, string>> profits;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string op; cin >> op;
        if (op == "BUY") {
            string s; int x;
            cin >> s >> x;

            time[s] = i;
            original[s] = current[s] = x;
            profits.emplace(0, i, s);
        } else if (op == "UPDATE") {
            string s; int x;
            cin >> s >> x;

            if (current.count(s)) {
                current[s] = x;
                profits.emplace(x - original[s], time[s], s);
            }
        } else {
            int profit, t; string s;
            do {
                auto top = profits.top();
                tie(profit, t, s) = top;
                profits.pop();
            } while (!current.count(s) || profit > current[s] - original[s]);

            ans += profit;
            current.erase(s);
        }
    }

    cout << ans << "\n";
}