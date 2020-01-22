#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_places;
        scanf("%d", &num_places);

        vector<int> places;
        int min = INT_MAX;

        for (int i = 1; i <= num_places; i++) {
            int num_neighbours = 1;

            int neighbour; char delimeter;
            scanf("%d", &neighbour);

            while (scanf("%c", &delimeter) != EOF && delimeter == ' ')
                scanf("%d", &neighbour), num_neighbours++;

            if (num_neighbours == min) places.push_back(i);
            else if (num_neighbours < min) {
                min = num_neighbours;
                places.clear(); places.push_back(i);
            }
        }

        printf("%d", places[0]);
        for (int i = 1; i < (int) places.size(); i++)
            printf(" %d", places[i]);

        printf("\n");
    }
}