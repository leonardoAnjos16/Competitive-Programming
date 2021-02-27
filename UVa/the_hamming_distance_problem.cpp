#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, H; cin >> N >> H;
        for (int i = 0; i < (1 << N); i++) {
            int cnt = 0;
            string bin = "";

            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) bin += '1', cnt++;
                else bin += '0';
            }

            reverse(all(bin));
            if (cnt == H) cout << bin << "\n";
        }

        if (T) cout << "\n";
    }
}