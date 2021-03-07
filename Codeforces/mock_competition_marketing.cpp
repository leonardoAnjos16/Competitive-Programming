#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int b[10];
    for (int i = 0; i < 6; i++)
        cin >> b[i];

    int c[MAX];
    for (int i = 0; i < N; i++)
        cin >> c[i];

    int ans = 0;
    for (int i = 0; i < (1 << 6); i++) {
        int sum = 0, cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << (c[j] - 1))) {
                if (sum + b[c[j] - 1] > K) break;
                else sum += b[c[j] - 1], cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}