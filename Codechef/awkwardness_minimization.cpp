#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();

        int boys = 0, girls = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') boys++;
            else girls++;
        }

        string best = "";
        if (boys == girls) {
            for (int i = 0; i < boys; i++)
                best += "bg";
        } else if (boys > girls) {
            int aux = (boys - girls - 1) / 2;

            for (int i = 0; i < aux; i++)
                best += 'b';

            for (int i = 0; i < min(boys, girls); i++)
                best += "bg";

            best += 'b';
            for (int i = 0; i < aux; i++)
                best += 'b';

            if ((boys - girls - 1) % 2) best += 'b';
        } else {
            int aux = (girls - boys - 1) / 2;

            for (int i = 0; i < aux; i++)
                best += 'g';

            for (int i = 0; i < min(boys, girls); i++)
                best += "gb";

            best += 'g';
            for (int i = 0; i < aux; i++)
                best += 'g';

            if ((girls - boys - 1) % 2) best += 'g';
        }

        long ans = 0LL;
        long bsum = 0LL, gsum = 0LL;
        long bcnt = 0LL, gcnt = 0LL;

        for (int i = 0; i < n; i++) {
            if (best[i] == 'b') {
                ans += gcnt * i - gsum;
                bsum += i; bcnt++;
            } else {
                ans += bcnt * i - bsum;
                gsum += i; gcnt++;
            }
        }

        cout << ans << "\n";
    }
}