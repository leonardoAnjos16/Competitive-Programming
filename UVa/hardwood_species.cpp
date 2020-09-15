#include <bits/stdc++.h>

using namespace std;

#define MAX 31

int main() {
    int num_cases;
    scanf("%d\n\n", &num_cases);

    string species;
    while (num_cases--) {
        map<string, int> counter;
        double total = 0;

        while (getline(cin, species) && species != "") {
            if (counter.find(species) == counter.end()) counter[species] = 1;
            else counter[species]++;

            total++;
        }

        for (map<string, int>::iterator it = counter.begin(); it != counter.end(); it++)
            printf("%s %.4lf\n", (it->first).c_str(), ((it->second * 100) / total));

        if (num_cases > 0)
            printf("\n");
    }
}