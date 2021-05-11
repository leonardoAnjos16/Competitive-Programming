#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string S; cin >> S;

    int Q; cin >> Q;
    bool flipped = false;

    while (Q--) {
        int T, A, B;
        cin >> T >> A >> B;

        if (T == 2) flipped = !flipped;
        else if (!flipped) swap(S[A - 1], S[B - 1]);
        else swap(S[(A - 1 + N) % (2 * N)], S[(B - 1 + N) % (2 * N)]);
    }

    if (flipped)
        S = S.substr(N) + S.substr(0, N);

    cout << S << "\n";
}