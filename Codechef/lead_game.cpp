#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int lead[2] = {0};
    int score[2] = {0};

    while (N--) {
        int S, T;
        cin >> S >> T;

        score[0] += S;
        score[1] += T;

        int diff = score[0] - score[1];
        if (diff > 0) lead[0] = max(lead[0], diff);
        else lead[1] = max(lead[1], -diff);
    }

    if (lead[0] > lead[1]) cout << "1 " << lead[0] << "\n";
    else cout << "2 " << lead[1] << "\n";
}