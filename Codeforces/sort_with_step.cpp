#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<int> wrong;
        for (int i = 0; i < n; i++)
            if (abs(i - p[i]) % k)
                wrong.push_back(i);

        if (wrong.empty()) cout << "0\n";
        else if ((int) wrong.size() > 2) cout << "-1\n";
        else if ((int) wrong.size() == 2 && !(abs(wrong[0] - p[wrong[1]]) % k) && !(abs(wrong[1] - p[wrong[0]]) % k)) cout << "1\n";
        else {
            bool possible = false;
            for (int i = 0; i < n && !possible; i++)
                if (i != wrong[0] && !(abs(i - p[wrong[0]]) % k) && !(abs(wrong[0] - p[i]) % k))
                    possible = true;

            cout << (possible ? "1" : "-1") << "\n";
        }
    }
}