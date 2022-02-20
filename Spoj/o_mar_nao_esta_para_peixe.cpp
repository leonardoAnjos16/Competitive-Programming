#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    bool covered[MAX][MAX] = {0};
    while (N--) {
        int xi, xf, yi, yf;
        cin >> xi >> xf >> yi >> yf;

        for (int i = xi; i < xf; i++)
            for (int j = yi; j < yf; j++)
                covered[i][j] = true;
    }

    int ans = 0;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            ans += covered[i][j];

    cout << ans << "\n";
}