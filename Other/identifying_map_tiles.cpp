#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int x = 0, y = 0;
    int level = s.size();

    for (char c: s) {
        x <<= 1;
        if ((c - '0') & 1) x++;

        y <<= 1;
        if ((c - '0') / 2) y++;
    }

    cout << level << " " << x << " " << y << "\n";
}