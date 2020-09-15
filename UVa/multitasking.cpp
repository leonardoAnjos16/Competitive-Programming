#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

struct task {
    int start_time;
    int end_time;
    int repetition_interval;
};

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
        task one_time[100];
        for (int i = 0; i < n; i++)
            scanf("%d %d", &one_time[i].start_time, &one_time[i].end_time);

        task repeating[100];
        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &repeating[i].start_time, &repeating[i].end_time, &repeating[i].repetition_interval);

        bitset<MAX> minutes;
        bool conflict = false;

        for (int i = 0; i < n && !conflict; i++) {
            one_time[i].end_time--;
            for (int j = one_time[i].start_time; j <= one_time[i].end_time && !conflict; j++) {
                if (minutes.test(j)) conflict = true;
                else minutes.set(j);
            }
        }

        for (int i = 0; i < m && !conflict; i++) {
            int counter = repeating[i].start_time;
            repeating[i].end_time--;
            
            while (counter < MAX && !conflict) {
                if (minutes.test(counter)) conflict = true;
                else minutes.set(counter);

                if (++counter > repeating[i].end_time) {
                    repeating[i].start_time += repeating[i].repetition_interval;
                    repeating[i].end_time += repeating[i].repetition_interval;
                    counter = repeating[i].start_time;
                }
            }
        }

        if (conflict) printf("CONFLICT\n");
        else printf("NO CONFLICT\n");
    }
}