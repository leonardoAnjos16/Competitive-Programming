#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<llong>> memo;

llong human(int num_digits, int max_first_digit = 9) {
    if (max_first_digit < 0) return 0;
    if (num_digits <= 2) return max_first_digit + 1;

    llong &ans = memo[num_digits][max_first_digit];
    if (~ans) return ans;

    return ans = (max_first_digit + 1) * human(num_digits - 2);
}

string reflect(string &N) {
    string reflected = N;
    for (int i = 0, j = (int) N.size() - 1; i < j; i++, j--)
        reflected[j] = N[i];

    return reflected;
}

void adjust_middle(string &N, int v) {
    int num_digits = N.size();
    int mid = (num_digits + 1) / 2 - 1;

    char forbidden = '9', desired = '0';
    if (v == -1) swap(forbidden, desired);

    while (mid >= 0 && N[mid] == forbidden) {
        N[mid] = N[num_digits - mid - 1] = desired;
        mid--;
    }

    if (mid >= 0) N[mid] = N[num_digits - mid - 1] = N[mid] + v;
    else if (v == 1) N.push_back('1'), N[0] = '1';

    if (N[0] == '0') {
        N.pop_back();
        for (int i = 0; i + 1 < num_digits; i++)
            N[i] = '9';
    }
}

llong human(string &N) {
    if (N == "0") return 0;

    llong ans = 0LL;
    int num_digits = N.size();

    for (int i = 1; i + 1 <= num_digits; i++) {
        if (i <= 2) ans += 9;
        else ans += 9 * human(i - 2);
    }

    for (int i = 0; i < (num_digits + 1) / 2; i++)
        ans += human(num_digits - 2 * i, N[i] - '0' - 1);

    ans -= human(num_digits, 0);

    string reflected = reflect(N);
    if (reflected <= N) ans++;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memo.assign(15, vector<llong>(10, -1LL));

    int Q; cin >> Q;
    while (Q--) {
        string A, B;
        cin >> A >> B;

        string sub_A = to_string(stoll(A) - 1LL);

        llong X = human(B) - human(sub_A);
        if (!X) cout << "0 -1 -1\n";
        else {
            string F = reflect(A);
            if (F < A) adjust_middle(F, 1);

            string L = reflect(B);
            if (L > B) adjust_middle(L, -1);

            cout << X << " " << F << " " << L << "\n";
        }
    }
}