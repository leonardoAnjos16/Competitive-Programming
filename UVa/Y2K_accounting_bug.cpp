#include <bits/stdc++.h>

using namespace std;

int s, d, max_surplus = INT_MIN;

void get_max_surplus(int months[], int counter = 0) {
    if (counter >= 12) {
        bool okay = true;
        for (int i = 0; i < 8 && okay; i++) {
            int sum = 0;
            for (int j = i; j < i + 5; j++)
                sum += months[j];

            if (sum >= 0) okay = false;
        }

        if (okay) {
            int sum = 0;
            for (int i = 0; i < 12; i++)
                sum += months[i];

            max_surplus = max(max_surplus, sum);
        }
    } else {
        months[counter] = s; get_max_surplus(months, counter + 1);
        months[counter] = d; get_max_surplus(months, counter + 1);
    }
}

int main() {
    while (scanf("%d %d", &s, &d) != EOF) {
        int months[12];
        d *= -1;

        get_max_surplus(months);
        if (max_surplus > 0) printf("%d\n", max_surplus);
        else printf("Deficit\n");

        max_surplus = INT_MIN;
    }
}