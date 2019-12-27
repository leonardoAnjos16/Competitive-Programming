#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

typedef pair<int, int> int_pair;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_stops;
        scanf("%d", &num_stops);

        int_pair stops[MAX];
        for (int i = 0; i <= num_stops; i++) {
            int distance, fuel;
            scanf("%d %d", &distance, &fuel);

            stops[i].first = distance;
            stops[i].second = fuel;
        }

        int town_distance = stops[num_stops].first;
        int curr_fuel = stops[num_stops].second;

        for (int i = 0; i < num_stops; i++)
            stops[i].first = town_distance - stops[i].first;

        sort(stops, stops + num_stops);

        priority_queue<int> heap;
        bool done = false;
        
        int stop_counter = 0, counter = 0;
        while (!done) {
            while (counter < num_stops && stops[counter].first <= curr_fuel)
                heap.push(stops[counter++].second);

            if (curr_fuel >= town_distance) {
                done = true;
            } else if (heap.empty()) {
                stop_counter = -1;
                done = true;
            } else {
                curr_fuel += heap.top();
                heap.pop();
                stop_counter++;
            }
        }

        printf("%d\n", stop_counter);
    }
}