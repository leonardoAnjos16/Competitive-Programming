#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int offsets[8] = { 0, 2, 4, 5, 7, 9, 11, 12 };
const string notes[12] = { "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si" };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> scales(12, 0);
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 8; j++) {
            int idx = (i + offsets[j]) % 12;
            scales[i] |= (1 << idx);
        }

    int N; cin >> N;

    vector<int> songs(N);
    for (int i = 0; i < N; i++) {
        string note; cin >> note;
        songs[i] = find(notes, notes + 12, note) - notes;
    }

    vector<bool> valid(1 << 12, false);
    for (int i = 0; i < (1 << 12); i++)
        for (int j = 0; j < 12 && !valid[i]; j++)
            if ((scales[j] & i) == i)
                valid[i] = true;

    int ans = INT_MAX;
    for (int i = 0; i < 12; i++) {
        int start = 0;
        while (start < N && (scales[i] & (1 << songs[start]))) start++;

        int end = N;
        while (end - 1 >= 0 && (scales[i] & (1 << songs[end - 1]))) end--;

        if (!end) ans = 1;
        else {
            int idx = start, cnt = 1;
            while (idx < end) {
                bool done = false;
                int used = 1 << songs[idx];

                while (idx + 1 < end && !done) {
                    int nused = used | (1 << songs[idx + 1]);
                    if (!valid[nused]) done = true;
                    else {
                        idx++;
                        used = nused;
                    }
                }

                cnt++;
                idx++;
            }

            ans = min(ans, cnt);
        }
    }

    cout << ans << "\n";
}