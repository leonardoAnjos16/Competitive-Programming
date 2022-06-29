#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAXD = 20;
const int MAXS = 200;

vector<int> digits;
long memo[2][MAXD][MAXS];

long count(int sum, bool tight = true, int digit = 0) {
    if (!sum) return 1;
    if (sum < 0) return 0;
    if (digit >= (int) digits.size()) return 1;

    long &ans = memo[tight][digit][sum];
    if (~ans) return ans;

    ans = 0LL;
    for (int d = 0; d <= (tight ? digits[digit] : 9); d++)
        ans += count(sum - d, tight && (d == digits[digit]), digit + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N, K;
    cin >> N >> K;

    while (N) {
        digits.push_back(N % 10LL);
        N /= 10LL;
    }

    reverse(digits.begin(), digits.end());
    memset(memo, -1, sizeof memo);

    int sum = 0;
    long aux = K;
    vector<int> K_digits;

    while (aux) {
        K_digits.push_back(aux % 10LL);
        sum += aux % 10LL;
        aux /= 10LL;
    }

    while (K_digits.size() < digits.size())
        K_digits.push_back(0);

    reverse(K_digits.begin(), K_digits.end());

    bool tight = true;
    long position = count(sum - 1) - 1LL;

    for (int i = 0; i < K_digits.size(); i++) {
        for (int j = 0; j < K_digits[i]; j++) {
            position += count(sum - j, tight && (j == digits[i]), i + 1);
            position -= count(sum - j - 1, tight && (j == digits[i]), i + 1);
        }

        sum -= K_digits[i];
        tight &= (K_digits[i] == digits[i]);
    }

    position++;

    sum = 0;
    while (count(sum) <= K) sum++;
    K -= count(sum - 1);

    tight = true;
    long at = 0LL;

    for (int i = 0; i < (int) digits.size(); i++) {
        int d = 0;
        long cnt = 0LL;

        while (cnt + count(sum - d, tight && (d == digits[i]), i + 1) - count(sum - d - 1, tight && (d == digits[i]), i + 1) <= K)
            cnt += count(sum - d, tight && (d == digits[i]), i + 1) - count(sum - d - 1, tight && (d == digits[i]), i + 1), d++;

        K -= cnt;
        sum -= d;
        tight &= (d == digits[i]);

        at *= 10LL;
        at += d;
    }

    cout << position << " " << at << "\n";
}