#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<long> to_base(long N, long K) {
    vector<long> rep;
    while (N) {
        rep.push_back(N % K);
        N /= K;
    }

    reverse(rep.begin(), rep.end());
    return rep;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N; int D;
    cin >> N >> D;

    if (!N) cout << "2 " << (!D ? "1" : "0") << "\n";
    else if (N - D < 2) {
        int K = 2, R = 0;
        for (int i = 2; i <= N + 1; i++) {
            vector<long> rep = to_base(N, i);

            int cnt = 0, idx = (int) rep.size() - 1;
            while (idx >= 0 && rep[idx] == D) cnt++, idx--;

            if (cnt > R) K = i, R = cnt;
        }

        cout << K << " " << R << "\n";
    } else {
        vector<long> divs;
        for (long i = 2LL; i * i <= N - D; i++)
            if (!((N - D) % i)) {
                divs.push_back(i);
                if (i * i < N - D)
                    divs.push_back((N - D) / i);
            }

        divs.push_back(N - D);
        sort(divs.begin(), divs.end());

        long K = 2LL; int R = 0;
        for (auto div: divs) {
            vector<long> rep = to_base(N, div);

            int cnt = 0, idx = (int) rep.size() - 1;
            while (idx >= 0 && rep[idx] == D) cnt++, idx--;

            if (cnt > R) K = div, R = cnt;
        }

        cout << K << " " << R << "\n";
    }
}