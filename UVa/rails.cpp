#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int main() {
    int num_coaches;
    while (scanf("%d", &num_coaches), num_coaches) {
        int coaches[MAX], coach;
        while (scanf("%d", &coach), coach) {
            coaches[0] = coach;
            for (int i = 1; i < num_coaches; i++)
                scanf("%d", &coaches[i]);

            stack<int> station;
            station.push(coach = 1);

            bool possible = true;
            for (int i = 0; i < num_coaches && possible; i++) {
                while (coach <= num_coaches && (station.empty() || station.top() < coaches[i]))
                    station.push(++coach);

                if (coach > num_coaches || station.top() > coaches[i]) possible = false;
                else station.pop();
            }

            printf("%s\n", possible ? "Yes" : "No");
        }

        printf("\n");
    }
}