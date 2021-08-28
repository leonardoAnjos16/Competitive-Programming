#include <bits/stdc++.h>

using namespace std;

#define long __int128

int n;
vector<int> p;
vector<vector<long>> memo;

long young_diagrams(int last, int i = 0) {
    if (i > n) return 0LL;
    if (i == n) return 1LL;

    long &ans = memo[last][i];
    if (~ans) return ans;
    
    ans = 0LL;
    if (!i) {
        ans += young_diagrams(1, i + 1);
        for (int j = 2; j <= last && i + j <= n && p[i + j - 1] > p[i + j - 2]; j++)
            ans += young_diagrams(j, i + j);
    } else {
        if (p[i] > p[i - last])
            ans += young_diagrams(1, i + 1);
        
        if (p[i] > p[i - last])
            for (int j = 2; j <= last && i + j <= n && p[i + j - 1] > p[i + j - 2] && p[i + j - 1] > p[i + j - last - 1]; j++)
                ans += young_diagrams(j, i + j);
    }
    
    return ans;
}

void print(long n) {
    if (n < 0) {
        cout << "-";
        n = -n;
    }

    if (n > 9) print(n / 10);
    int d = n % 10;
    cout << d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    memo.assign(n + 5, vector<long>(n + 5, -1LL));

    long ans = young_diagrams(n);
    print(ans); cout << "\n";
}