#include <bits/stdc++.h>

using namespace std;

char nucleotides[4] = {'A', 'C', 'G', 'T'};

set<string> all_sols;
string DNA;
int N;

void get_sols(string curr, int K, int index = 0) {
    if (K == 0) all_sols.insert(curr);
    else if (index < N) {
        for (int i = index; i < N; i++) {
            char original = curr[i];
            for (int j = 0; j < 4; j++) {
                curr[i] = nucleotides[j];
                get_sols(curr, K - 1, i + 1);
            }

            curr[i] = original;
        }
    }
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int K; scanf("%d %d", &N, &K);
        cin >> DNA;

        get_sols(DNA, K);
        int num_sols = all_sols.size();

        printf("%d\n", num_sols);
        for (set<string>::iterator it = all_sols.begin(); it != all_sols.end(); it++)
            printf("%s\n", (*it).c_str());

        all_sols.clear();
    }
}