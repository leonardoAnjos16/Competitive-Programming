#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        if (a[0] == b[0]) cout << "YES\n" << a[0] << "*\n";
        else if (a.back() == b.back()) cout << "YES\n*" << a.back() << "\n";
        else {
            string common = "";
            for (int i = 1; i < (int) a.size() && common == ""; i++)
                for (int j = 1; j < (int) b.size() && common == ""; j++)
                    if (a[i - 1] == b[j - 1] && a[i] == b[j]) common = a.substr(i - 1, 2);

            if (common == "") cout << "NO\n";
            else cout << "YES\n*" << common << "*" << "\n";
        }
    }
}