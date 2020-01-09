#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_frosh;
    while (scanf("%d", &num_frosh), num_frosh) {
        map<vector<int>, int> counter;
        vector<int> courses(5);

        int max = INT_MIN;
        while (num_frosh--) {
            for (int i = 0; i < 5; i++)
                scanf("%d", &courses[i]);

            sort(courses.begin(), courses.end());
            if (counter.find(courses) == counter.end())
                counter[courses] = 1;
            else
                counter[courses]++;

            if (counter[courses] > max)
                max = counter[courses];
        }

        int num_students = 0;
        for (map<vector<int>, int>::iterator it = counter.begin(); it != counter.end(); it++)
            if (it->second == max)
                num_students++;

        num_students *= max;
        printf("%d\n", num_students);
    }
}