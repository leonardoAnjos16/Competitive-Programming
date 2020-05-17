#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    while (N--) {
        string exp; cin >> exp;

        vector<long> vals;
        vector<char> ops;

        string num = "";
        for (int i = 0; i < (int) exp.size(); i++) {
            if (exp[i] != '+' && exp[i] != '*') num += exp[i];
            else {
                vals.push_back((long) stoi(num));
                ops.push_back(exp[i]);
                num = "";
            }
        }

        vals.push_back((long) stoi(num));

        long prod = vals[0], sum = vals[0];
        vector<long> mn, mx;

        for (int i = 0; i < (int) ops.size(); i++) {
            if (ops[i] == '+') {
                mn.push_back(prod);
                prod = vals[i + 1];
                sum += vals[i + 1];
            } else {
                mx.push_back(sum);
                sum = vals[i + 1];
                prod *= vals[i + 1];
            }
        }

        mn.push_back(prod);
        mx.push_back(sum);

        prod = 1; sum = 0;
        for (int i = 0; i < (int) mn.size(); i++) sum += mn[i];
        for (int i = 0; i < (int) mx.size(); i++) prod *= mx[i];

        cout << "The maximum and minimum are " << prod << " and " << sum << ".\n";
    }
}