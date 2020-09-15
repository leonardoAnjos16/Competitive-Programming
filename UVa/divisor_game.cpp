#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;

int most_divs[MAX] = {0};

void get_most_divs() {
    int num_divs[MAX] = {0};
    for (int i = 1; i < MAX; i++) {
        most_divs[i]++;
        for (int j = 2 * i; j < MAX; j += i)
            num_divs[j]++;

        most_divs[i] = (num_divs[i] >= num_divs[most_divs[i - 1]]) ? i : most_divs[i - 1];
    }
}

int main() {
    int T; scanf("%d", &T);
    get_most_divs();
    
    while (T--) {
        int N; scanf("%d", &N);
        printf("%d\n", most_divs[N]);
    }
}