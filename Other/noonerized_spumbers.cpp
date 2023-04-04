#include <bits/stdc++.h>

using namespace std;

#define llong __int128

llong stoll(string &s) {
    llong ans = 0;
    for (char c: s) {
        ans *= 10;
        ans += c - '0';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string operands[3], op, equal;
    cin >> operands[0] >> op >> operands[1] >> equal >> operands[2];

    bool found = false;
    for (int i = 0; i < 3 && !found; i++)
        for (int j = i + 1; j < 3 && !found; j++)
            for (int k = 0; k < (int) operands[i].size() && !found; k++)
                for (int l = 0; l < (int) operands[j].size() && !found; l++) {
                    string noperands[3];
                    for (int m = 0; m < 3; m++) {
                        if (m == i) noperands[m] = operands[j].substr(0, l) + operands[i].substr(k);
                        else if (m == j) noperands[m] = operands[i].substr(0, k) + operands[j].substr(l);
                        else noperands[m] = operands[m];
                    }

                    llong x = stoll(noperands[0]);
                    llong y = stoll(noperands[1]);
                    llong z = stoll(noperands[2]);

                    if ((op == "+" && x + y == z) || (op == "*" && x * y == z)) {
                        found = true;
                        cout << noperands[0] << " " << op << " " << noperands[1] << " = " << noperands[2] << "\n";
                    }
                }
}