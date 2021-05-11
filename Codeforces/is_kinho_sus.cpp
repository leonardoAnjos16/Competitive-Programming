#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vi> opinions(N);
    for (int i = 0; i < N; i++) {
        int S; cin >> S;
        opinions[i].resize(S);

        for (int j = 0; j < S; j++) {
            int suspicious; cin >> suspicious;
            opinions[i][j] = suspicious - 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        bitset<MAX> impostor;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                impostor[j] = true;

        bool valid = true;
        for (int j = 0; j < N && valid; j++) {
            int cnt = 0;
            for (auto k: opinions[j])
                if (impostor[k]) cnt++;

            if (impostor[j] && cnt) valid = false;
            else if (!impostor[j] && !cnt) valid = false;
        }

        if (valid) ans++;
    }

    cout << ans << "\n";
}