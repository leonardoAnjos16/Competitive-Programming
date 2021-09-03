#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int leds[10] = {
    0b1110111,
    0b0010010,
    0b1011101,
    0b1011011,
    0b0111010,
    0b1101011,
    0b1101111,
    0b1010010,
    0b1111111,
    0b1111011
};

int n, k;
vector<int> on, digs;
vector<vector<int>> memo;

int to_digit(int mask) {
    for (int i = 0; i < 10; i++)
        if (mask == leds[i]) return i;

    return -1;
}

int need(int mask, int d) {
    for (int i = 0; i < 7; i++)
        if (!(leds[d] & (1 << i)) && (mask & (1 << i)))
            return -1;

    int cnt = 0;
    for (int i = 0; i < 7; i++)
        if ((leds[d] & (1 << i)) && !(mask & (1 << i)))
            cnt++;

    return cnt;
}

bool possible(int i = 0, int used = 0) {
    int &ans = memo[i][used];
    if (~ans) return ans;

    if (used >= k) {
        for (int j = i; j < n; j++) {
            int d = to_digit(on[j]);
            if (d == -1) {
                for (int l = i; l < j; l++)
                    digs[l] = -1;

                return ans = false;
            }

            digs[j] = d;
        }

        return ans = true;
    }

    if (i >= n) return ans = false;

    for (int j = 9; j >= 0; j--) {
        int aux = need(on[i], j);
        if (~aux && used + aux <= k) {
            digs[i] = j;
            if (possible(i + 1, used + aux))
                return ans = true;
        }

        digs[i] = -1;
    }

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    on.resize(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        on[i] = 0;
        for (int j = 0; j < 7; j++)
            if (s[j] == '1') on[i] |= (1 << (6 - j));
    }

    digs.assign(n, -1);
    memo.assign(n + 5, vector<int>(k + 5, -1));

    if (!possible()) cout << "-1\n";
    else {
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += to_string(digs[i]);

        cout << ans << "\n";
    }
}