#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int size(string &s) {
    int xs = (int) s.size() - 1;
    int ans = s.back() == 'S' ? -1 : (s.back() == 'L' ? 1 : 0);
    ans += (ans < 0 ? -xs : xs);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        if (size(a) < size(b)) cout << "<\n";
        else if (size(a) > size(b)) cout << ">\n";
        else cout << "=\n";
    }
}