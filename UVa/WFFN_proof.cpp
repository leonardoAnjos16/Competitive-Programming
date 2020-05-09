#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    while (cin >> str && str != "0") {
        sort(str.begin(), str.end());

        int ops = lower_bound(str.begin(), str.end(), 'N') - str.begin();
        int vars = str.end() - upper_bound(str.begin(), str.end(), 'N');

        if (!vars) str = "no WFF possible";
        else if (ops + 1 >= vars) str = str.substr(ops - vars + 1);
        else str = str.substr(0, (int) str.size() - (vars - ops - 1));

        printf("%s\n", str.c_str());
    }
}