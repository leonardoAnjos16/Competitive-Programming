#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_battlefields, size_green_army, size_blue_army;
        scanf("%d %d %d", &num_battlefields, &size_green_army, &size_blue_army);

        priority_queue<int> green_army, blue_army;
        for (int i = 0; i < size_green_army; i++) {
            int power; scanf("%d", &power);
            green_army.push(power);
        }

        for (int i = 0; i < size_blue_army; i++) {
            int power; scanf("%d", &power);
            blue_army.push(power);
        }

        while (!green_army.empty() && !blue_army.empty()) {
            queue<int> remaining_green, remaining_blue;
            int num_fights = min(num_battlefields, (int) min(green_army.size(), blue_army.size()));

            for (int i = 0; i < num_fights; i++) {
                int top_green = green_army.top(); green_army.pop();
                int top_blue = blue_army.top(); blue_army.pop();

                if (top_green > top_blue) remaining_green.push(top_green - top_blue);
                else if (top_blue > top_green) remaining_blue.push(top_blue - top_green);
            }

            while (!remaining_green.empty())
                green_army.push(remaining_green.front()), remaining_green.pop();

            while (!remaining_blue.empty())
                blue_army.push(remaining_blue.front()), remaining_blue.pop();
        }

        if (green_army.empty() && blue_army.empty()) printf("green and blue died\n");
        else if (green_army.empty()) {
            printf("blue wins\n");
            while (!blue_army.empty())
                printf("%d\n", blue_army.top()), blue_army.pop();
        } else {
            printf("green wins\n");
            while (!green_army.empty())
                printf("%d\n", green_army.top()), green_army.pop();
        }

        if (num_cases) printf("\n");
    }
}