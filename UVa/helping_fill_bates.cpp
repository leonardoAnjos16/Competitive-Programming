#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX = 1e6 + 5;

int main() {
    char str[MAX];
    scanf("%s", str);

    vector<vi> indices(52, vi());
    int size = strlen(str);

    for (int i = 0; i < size; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') indices[str[i] - 'A'].push_back(i);
        else indices[str[i] - 'a' + 26].push_back(i);
    }

    int Q; scanf("%d", &Q); 
    while (Q--) {
        scanf("%s", str);
        size = strlen(str);

        int pos = -1;
        bool okay = true;

        for (int i = 0; i < size && okay; i++) {
            int state = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - 'A' : str[i] - 'a' + 26;
            vi::iterator it = upper_bound(indices[state].begin(), indices[state].end(), pos);

            if (it == indices[state].end()) okay = false;
            else pos = *it;
        }

        if (!okay) printf("Not matched\n");
        else {
            int state = (str[0] >= 'A' && str[0] <= 'Z') ? str[0] - 'A' : str[0] - 'a' + 26;
            int init_pos = *upper_bound(indices[state].begin(), indices[state].end(), -1);

            printf("Matched %d %d\n", init_pos, pos);
        }
    }
}