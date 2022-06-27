#include <bits/stdc++.h>

using namespace std;

bool wrong_dir(char dir, int x, int y, int xd, int yd) {
    if (dir == 'E' && xd <= x) return true;
    if (dir == 'O' && xd >= x) return true;
    if (dir == 'N' && yd <= y) return true;
    if (dir == 'S' && yd >= y) return true;
    return false;
}

void turn_right(char &dir) {
    if (dir == 'E') dir = 'S';
    else if (dir == 'S') dir = 'O';
    else if (dir == 'O') dir = 'N';
    else dir = 'E';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y; char dir;
    cin >> x >> y >> dir;

    int xd, yd;
    cin >> xd >> yd;

    vector<string> ans;
    while (x != xd || y != yd) {
        while (wrong_dir(dir, x, y, xd, yd)) {
            ans.push_back("D");
            turn_right(dir);
        }

        if (dir == 'E' || dir == 'O') ans.push_back("A " + to_string(abs(xd - x))), x = xd;
        else ans.push_back("A " + to_string(abs(yd - y))), y = yd;
    }

    int ops = ans.size();
    cout << ops << "\n";

    for (string s: ans)
        cout << s << "\n";
}