#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1125;
const int MAX_P = 250;
const int MAX_K = 20;

vector<int> p;
int memo[MAX_N][MAX_K][MAX_P];

void get_primes() {
    bitset<MAX_N> marked;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (marked[i]) continue;
        for (int j = 2 * i; j < MAX_N; j += i)
            marked[j] = true;
    }

    for (int i = 2; i <= MAX_N; i++)
        if (!marked[i]) p.push_back(i);
}

int ways(int n, int k, int i = 0) {
    if (!n && !k) return 1;
    if (n <= 1 || !k) return 0;

    int &ans = memo[n][k][i];
    if (ans != -1) return ans;

    ans = 0;
    for (int j = i; j < (int) p.size() && p[j] <= n; j++)
        ans += ways(n - p[j], k - 1, j + 1);

    return ans;
}

int main() {
    get_primes();
    memset(memo, -1, sizeof memo);

    int n, k;
    while (scanf("%d %d", &n, &k), n || k) {
        int ans = ways(n, k);
        printf("%d\n", ans);
    }
}