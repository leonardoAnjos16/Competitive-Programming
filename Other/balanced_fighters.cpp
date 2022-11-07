#include <bits/stdc++.h>

using namespace std;

bool win(tuple<string, int, int, int> &A, tuple<string, int, int, int> &B) {
    auto [nameA, HPA, ATA, DFA] = A;
    auto [nameB, HPB, ATB, DFB] = B;

    int damageA = ATB - DFA;
    int damageB = ATA - DFB;

    if (damageB <= 0) return false;
    if (damageA <= 0) return true;

    int roundsA = (HPA + damageA - 1) / damageA;
    int roundsB = (HPB + damageB - 1) / damageB;

    return roundsB < roundsA;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<tuple<string, int, int, int>> fighters(N);
    for (int i = 0; i < N; i++) {
        string name; int HP, AT, DF;
        cin >> name >> HP >> AT >> DF;
        fighters[i] = make_tuple(name, HP, AT, DF);
    }

    vector<tuple<string, string, string>> ans;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                vector<tuple<string, int, int, int>> curr = { fighters[i], fighters[j], fighters[k] };
                sort(curr.begin(), curr.end());

                bool intransitive = false;
                do {
                    if (win(curr[0], curr[1]) && win(curr[1], curr[2]) && win(curr[2], curr[0]))
                        intransitive = true;
                } while (!intransitive && next_permutation(curr.begin(), curr.end()));

                if (intransitive) ans.emplace_back(get<0>(curr[0]), get<0>(curr[1]), get<0>(curr[2]));
            }

    int K = ans.size();
    cout << K << "\n";

    for (auto [A, B, C]: ans)
        cout << A << " " << B << " " << C << "\n";
}