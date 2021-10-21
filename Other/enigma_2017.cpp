#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
string S;
vector<vector<int>> memo;

long exp(int a, int e) {
    if (!e) return 1LL;

    long ans = exp(a, e >> 1);
    ans = (ans * ans) % N;

    if (!(e & 1)) return ans;
    return (ans * a) % N;
}

bool possible(int i = 0, int rem = 0) {
    if (i >= (int) S.size()) return !rem;

    int &ans = memo[i][rem];
    if (~ans) return ans;

    long pot = exp(10, (int) S.size() - i - 1);
    if (S[i] >= '0' && S[i] <= '9') {
        int d = S[i] - '0';
        int aux = (d * pot) % N;
        return ans = possible(i + 1, (rem + aux) % N);
    }

    for (int j = !i ? 1 : 0; j < 10; j++) {
        int aux = (j * pot) % N;
        if (possible(i + 1, (rem + aux) % N)) {
            S[i] = '0' + j;
            return ans = true;
        }
    }

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> N;

    memo.assign((int) S.size() + 5, vector<int>(N + 5, -1));

    if (!possible()) cout << "*\n";
    else cout << S << "\n";
}