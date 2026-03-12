#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 10;

llong llong_volume(string v) {
    llong ans = 0LL;
    int decimal = 0;
    bool seen = false;

    for (char c: v) {
        if (c == 'L') continue;
        if (c == '.') seen = true;
        else {
            ans *= 10LL;
            ans += c - '0';
            if (seen) decimal++;
        }
    }

    while (decimal < MAX) {
        decimal++;
        ans *= 10LL;
    }

    return ans;
}

string next_name(string last_name) {
    if (last_name.back() == 'z') last_name += 'a';
    else last_name[(int) last_name.size() - 1]++;

    return last_name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string last_name = "a";
    map<llong, string> names;

    while (n--) {
        string v; cin >> v;

        llong lv = llong_volume(v);
        if (!names.count(lv)) {
            names[lv] = next_name(last_name);
            last_name = names[lv];
        }

        cout << names[lv] << "\n";
    }
}