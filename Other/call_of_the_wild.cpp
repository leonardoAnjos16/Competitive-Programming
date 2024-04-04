#include <bits/stdc++.h>

using namespace std;

#define llong long long int

string N, power;
vector<int> border;
vector<vector<vector<llong>>> memo;

llong count(bool tight = true, int digit = 0, int matches = 0) {
    if (digit >= (int) N.size()) return matches >= (int) power.size();

    llong &ans = memo[tight][digit][matches];
    if (~ans) return ans;

    ans = 0LL;
    for (char d = '0'; d <= (tight ? N[digit] : '9'); d++) {
        if (matches >= (int) power.size()) ans += count(tight && (d == N[digit]), digit + 1, matches);
        else {
            int nmatches = matches;
            while (nmatches && d != power[nmatches])
                nmatches = border[nmatches - 1];

            ans += count(tight && (d == N[digit]), digit + 1, nmatches + (d == power[nmatches]));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> N >> x;

    power = to_string(1LL << x);
    border.assign((int) power.size(), 0);

    for (int i = 1; i < (int) power.size(); i++) {
        for (int j = 1; j <= i; j++) {
            bool same = true;
            for (int k = 0; k < j && same; k++)
                if (power[k] != power[i - j + k + 1])
                    same = false;

            if (same) border[i] = j;
        }
    }

    memo.assign(2, vector<vector<llong>>((int) N.size() + 5, vector<llong>((int) power.size() + 5, -1LL)));

    llong ans = count();
    cout << ans << "\n";
}