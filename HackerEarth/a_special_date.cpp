#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string D; cin >> D;

        int day = stoi(D.substr(0, 2));
        int month = stoi(D.substr(2, 2));
        int year = stoi(D.substr(4));

        string aux = D.substr(4);

        string rev = aux;
        reverse(rev.begin(), rev.end());

        int curr_day = stoi(rev.substr(0, 2));
        int curr_month = stoi(rev.substr(2));

        string ans = "";
        bool found = false;

        if (curr_day >= 1 && curr_day <= 30 && curr_month >= 1 && curr_month <= 12)
            if (curr_month < month || (curr_month == month && curr_day < day)) {
                found = true;
                ans = rev + aux;
            }

        for (int i = year - 1; i > 0 && !found; i--) {
            string aux = to_string(i);
            while ((int) aux.size() < 4)
                aux = "0" + aux;

            string rev = aux;
            reverse(rev.begin(), rev.end());

            int curr_day = stoi(rev.substr(0, 2));
            int curr_month = stoi(rev.substr(2));

            if (curr_day >= 1 && curr_day <= 30 && curr_month >= 1 && curr_month <= 12) {
                found = true;
                ans = rev + aux;
            }
        }

        if (!found) cout << "-1\n";
        else cout << ans << "\n";
    }
}