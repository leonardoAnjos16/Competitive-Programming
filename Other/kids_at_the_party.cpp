#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool div_four(string n) {
    int start = max((int) n.size() - 2, 0);
    int end = stoi(n.substr(start));
    return !(end % 4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string n; cin >> n;

        bool two = !((n.back()) & 1);

        int sum = 0;
        for (auto c: n)
            sum += c - '0';

        bool three = !(sum % 3);

        bool four = div_four(n);

        bool five = n.back() == '0' || n.back() == '5';
        bool six = two && three;

        vector<int> divs;
        if (two) divs.push_back(2);
        if (three) divs.push_back(3);
        if (four) divs.push_back(4);
        if (five) divs.push_back(5);
        if (six) divs.push_back(6);

        if (divs.empty()) cout << "-1\n";
        else {
            for (int i = 0; i < (int) divs.size(); i++) {
                if (i) cout << " ";
                cout << divs[i];
            }

            cout << "\n";
        }
    }
}