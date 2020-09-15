#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_jobs, position;
        scanf("%d %d", &num_jobs, &position);

        int jobs[MAX];
        queue< pair<int, int> > printer_queue;

        for (int i = 0; i < num_jobs; i++)
            scanf("%d", &jobs[i]), printer_queue.push({jobs[i], i});

        int priority = jobs[position];

        sort(jobs, jobs + num_jobs);
        reverse(jobs, jobs + num_jobs);

        int minutes = 0;
        while (true) {
            while (printer_queue.front().first < jobs[minutes])
                printer_queue.push(printer_queue.front()), printer_queue.pop();

            if (printer_queue.front().second == position) break;
            printer_queue.pop();
            minutes++;
        }

        printf("%d\n", ++minutes);
    }
}