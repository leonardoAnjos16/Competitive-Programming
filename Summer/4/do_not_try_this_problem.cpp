#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int SQRT = 320;

struct Update {
    int time;
    char letter;

    Update(): time(-1), letter('-') {}
    Update(int time, char letter): time(time), letter(letter) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    vector<Update> single_updates(n);
    for (int i = 0; i < n; i++)
        single_updates[i] = Update(0, s[i]);

    Update block_updates[SQRT][SQRT][SQRT];

    int q; cin >> q;
    for (int t = 1; t <= q; t++) {
        int i, a, k; char c;
        cin >> i >> a >> k >> c;

        i--;
        if (a >= SQRT) {
            for (int j = i; j <= i + k * a; j += a)
                single_updates[j] = Update(t, c);
        } else {
            int idx = i, start = i / SQRT, end = (i + k * a) / SQRT;
            while (idx <= i + k * a) {
                if (idx / SQRT == start || idx / SQRT == end) {
                    single_updates[idx] = Update(t, c);
                    idx += a;
                } else {
                    block_updates[idx / SQRT][i % a][a] = Update(t, c);
                    idx += ((idx / SQRT + 1) * SQRT - idx + a - 1) / a * a;
                    assert(idx % a == i % a);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        Update last = single_updates[i];
        for (int jump = 1; jump < SQRT; jump++)
            if (block_updates[i / SQRT][i % jump][jump].time > last.time)
                last = block_updates[i / SQRT][i % jump][jump];

        cout << last.letter;
    }

    cout << "\n";
}