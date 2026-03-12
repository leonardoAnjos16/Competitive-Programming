#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int some_prime[MAX] = {0};
    for (int i = 2; i < MAX; i++)
        if (!some_prime[i])
            for (int j = i; j < MAX; j += i)
                some_prime[j] = i;

    string s; cin >> s;

    int idx = 0;
    vector<int> nums;
    bitset<MAX> facts;

    while (idx < (int) s.size()) {
        int base = 0;
        while (idx < (int) s.size() && s[idx] >= '0' && s[idx] <= '9') {
            base *= 10;
            base += s[idx++] - '0';
        }

        if (idx >= (int) s.size() || s[idx] == '*') nums.push_back(base), idx++;
        else if (s[idx] == '!' && (idx + 1 >= (int) s.size() || s[idx + 1] == '*')) facts[base] = !facts[base], idx += 2;
        else {
            bool fact_base = s[idx] == '!';
            if (fact_base) idx++;

            idx++;
            int exp = 0;

            while (idx < (int) s.size() && s[idx] >= '0' && s[idx] <= '9') {
                exp *= 10;
                exp += s[idx++] - '0';
            }

            if (idx >= (int) s.size() || s[idx] != '!') {
                if (exp & 1) {
                    if (fact_base) facts[base] = !facts[base];
                    else nums.push_back(base);
                }
            } else if (exp == 1) {
                if (fact_base) facts[base] = !facts[base];
                else nums.push_back(base);
            }

            while (idx < (int) s.size() && s[idx] != '*') idx++;
            idx++;
        }
    }

    bitset<MAX> odd;
    for (int num: nums) {
        int aux = num;
        while (aux > 1) {
            int p = some_prime[aux];
            odd[p] = !odd[p];
            aux /= p;
        }
    }

    bool even = true;
    for (int i = MAX - 1; i > 0; i--) {
        even ^= facts[i];
        if (!even) {
            int aux = i;
            while (aux > 1) {
                int p = some_prime[aux];
                odd[p] = !odd[p];
                aux /= p;
            }
        }
    }

    bool square = true;
    for (int i = 0; i < MAX && square; i++)
        if (odd[i]) square = false;

    cout << (square ? "S" : "N") << "\n";
}