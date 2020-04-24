#include <bits/stdc++.h>

using namespace std;

#define long long long int

long pow(long a, int n) {
    if (!n) return 1;
    else return a * pow(a, n - 1);
}

string to_base_3(long n) {
    string num = "";
    while (n) {
        int d = n % 3;
        num += (char) (d + '0');
        n /= 3;
    }

    num += '0';
    return num;
}

string next_good(string num) {
    int n = num.size();

    int pos = -1;
    for (int i = 0; i < n; i++)
        if (num[i] == '2') pos = i;

    if (pos == -1) return num;

    while (num[++pos] != '0');
    for (int i = 0; i < pos; i++)
        num[i] = '0';

    num[pos] = '1';
    return num;
}

int main() {
    int q; scanf("%d", &q);

    while (q--) {
        long n; scanf("%lld", &n);

        string good_num = next_good(to_base_3(n));

        long ans = 0LL;
        for (int i = 0; i < (int) good_num.size(); i++)
            if (good_num[i] == '1') ans += pow(3LL, i);

        printf("%lld\n", ans);
    }
}