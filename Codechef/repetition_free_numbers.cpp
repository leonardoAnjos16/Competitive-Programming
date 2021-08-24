#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool repetition_free_number(int n) {
    int cnt[10] = {0};
    while (n) {
        int d = n % 10;
        if (!d || ++cnt[d] > 1)
            return false;

        n /= 10;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    if (N >= 987654321) cout << "0\n";
    else {
        while (!repetition_free_number(++N));
        cout << N << "\n";
    }
}