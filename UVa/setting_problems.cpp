#include<bits/stdc++.h>

using namespace std;

#define pair pair<int, int>
#define S first
#define G second

const int MAX = 105;

bool cmp(pair a, pair b) {
    return a.S + max(a.G, b.S) + b.G < b.S + max(b.G, a.S) + a.G;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        pair times[MAX];
        for (int i = 0; i < N; i++)
            scanf("%d", &times[i].S);

        for (int i = 0; i < N; i++)
            scanf("%d", &times[i].G);

        sort(times, times + N, cmp);

        int time = 0, ans = 0;
        for (int i = 0; i < N; i++) {
            int aux = min(time, times[i].S);

            int wait = times[i].S - aux;
            ans += wait + times[i].G;
            time += times[i].G - aux;
        }

        printf("%d\n", ans);
    }
}