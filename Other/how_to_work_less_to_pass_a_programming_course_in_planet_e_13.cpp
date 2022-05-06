#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, G;
    cin >> N >> G;

    int total = 0;
    vector<int> P(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        total += P[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < (1 << N); i++) {
        int grade = 0;
        for (int j = 0; j < N; j++)
            if (i & (1 << j)) grade += P[j];

        grade = 100.0L * grade / total;
        if (grade >= G) ans.emplace_back(i, grade);
    }

    assert(!ans.empty());

    int problems = N;
    for (auto [mask, grade]: ans)
        problems = min(problems, __builtin_popcount(mask));

    int combs = 0;
    for (auto [mask, grade]: ans)
        combs += __builtin_popcount(mask) == problems;

    cout << problems << " " << combs << "\n";
    for (auto [mask, grade]: ans)
        if (__builtin_popcount(mask) == problems) {
            cout << grade;
            for (int i = 0; i < N; i++)
                if (mask & (1 << i))
                    cout << " " << (i + 1);

            cout << "\n";
        }
}