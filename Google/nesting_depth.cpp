#include <bits/stdc++.h>

using namespace std;

string S;

string fill(int i = 0, char curr = '0', int cnt = 0) {
    if (i >= (int) S.size()) return string(cnt, ')');

    string ans = "";
    int diff = S[i] - curr;

    if (diff > 0) for (int j = 0; j < diff; j++) ans += '(';
    else if (diff < 0) for (int j = 0; j < -diff; j++) ans += ')';

    ans += S[i] + fill(i + 1, S[i], cnt + diff);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> S;
        string ans = fill();
        cout << "Case #" << t << ": " << ans << "\n";
    }
}