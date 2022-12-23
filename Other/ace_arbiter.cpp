#include <bits/stdc++.h>

using namespace std;

void read_score(int &a, int &b) {
    string line; cin >> line;

    int x = 0, idx = 0;
    while (idx < (int) line.size() && line[idx] != '-') {
        x *= 10;
        x += line[idx++] - '0';
    }

    idx++;
    int y = 0;

    while (idx < (int) line.size()) {
        y *= 10;
        y += line[idx++] - '0';
    }

    a = x;
    b = y;
}

bool reachable(int x, int y, int a, int b, int cnt = 0) {
    if (cnt && ((a + b) & 1)) swap(a, b);
    if (cnt > 11) return false;
    if (x == a && y == b) return true;

    return reachable(x, y, a + 1, b, cnt + 1) || reachable(x, y, a, b + 1, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int a, b;
    read_score(a, b);

    bool valid = true;
    if (a == 11 && b == 11) valid = false;

    int entries = 1;
    bool end = a == 11 || b == 11;

    while (entries < n && valid) {
        int x, y;
        read_score(x, y);

        if (x == 11 && y == 11) valid = false;
        else {
            if (x == a && y == b) entries++;
            else if (!end && reachable(x, y, a, b)) a = x, b = y, entries++;
            else valid = false, entries++;

            if (a == 11 || b == 11) end = true;
        }
    }

    if (valid) cout << "ok\n";
    else cout << "error " << entries << "\n";
}