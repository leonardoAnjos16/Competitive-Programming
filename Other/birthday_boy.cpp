#include <bits/stdc++.h>

using namespace std;

const int DAYS = 365;
const int MONTHS = 12;

int main() {
    const int days[MONTHS + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int ps[MONTHS + 1] = {0};
    for (int i = 1; i <= MONTHS; i++)
        ps[i] = ps[i - 1] + days[i];

    int n; cin >> n;

    bool used[DAYS + 1] = {0};
    for (int i = 0; i < n; i++) {
        string name, date;
        cin >> name >> date;

        int day = stoi(date.substr(3));
        int month = stoi(date.substr(0, 2));
        used[ps[month - 1] + day] = true;
    }

    int mx_dist = INT_MIN, ans = -1;
    for (int i = 1; i <= DAYS; i++) {
        if (!used[i]) {
            int idx = i - 1, cnt = 0;
            while (idx > 0 && !used[idx])
                cnt++, idx--;

            if (idx <= 0) {
                idx = DAYS;
                while (idx > 0 && !used[idx])
                    cnt++, idx--;
            }

            if (cnt > mx_dist) {
                ans = i;
                mx_dist = cnt;
            } else if (cnt == mx_dist && ans <= 300 && i > 300) {
                ans = i;
            }
        }
    }

    assert(ans != -1);

    int month = 1;
    while (month <= MONTHS && ps[month] < ans)
        month++;

    int day = ans - ps[month - 1];
    printf("%02d-%02d\n", month, day);
}