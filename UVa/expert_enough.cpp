#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<string, ii> sii;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int size; scanf("%d", &size);
        vector<sii> database(size);

        string name; int L, H;
        for (int i = 0; i < size; i++) {
            cin >> name; scanf("%d %d", &L, &H);
            database[i] = {name, {L, H}};
        }

        int num_queries;
        scanf("%d", &num_queries);

        while (num_queries--) {
            int price; scanf("%d", &price);
            string name = "UNDETERMINED";

            bool found = false;
            for (int i = 0; i < size; i++) {
                if (price >= database[i].second.first && price <= database[i].second.second) {
                    if (found) name = "UNDETERMINED";
                    else {
                        name = database[i].first;
                        found = true;
                    }
                }
            }

            printf("%s\n", name.c_str());
        }

        if (num_cases) printf("\n");
    }
}