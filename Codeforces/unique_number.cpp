#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, string> memo;

string unique(int sum, int used = 0) {
    if (!sum) return "";
    if (memo.count({sum, used})) return memo[{sum, used}];

    memo[{sum, used}] = "-1";
    for (int i = min(sum, 9); i >= 0; i--) {
        if (!(used & (1 << i))) {
            string aux = unique(sum - i, used | (1 << i));
            if (aux != "-1") {
                char number = i + '0';
                aux = number + aux;

                if (memo[{sum, used}] == "-1" || stoll(aux) < stoll(memo[{sum, used}]))
                    memo[{sum, used}] = aux;
            }
        }
    }

    return memo[{sum, used}];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int x; scanf("%d", &x);

        long long int ans = stoll(unique(x));
        printf("%lli\n", ans);
    }
}