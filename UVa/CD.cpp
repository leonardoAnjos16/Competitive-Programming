#include <bits/stdc++.h>

using namespace std;

int main() {
    int size_jack, size_jill;
    while (scanf("%d %d", &size_jack, &size_jill), size_jack || size_jill) {
        set<int> jack_cds;
        int catalog_number;
        while (size_jack--)
            scanf("%d", &catalog_number), jack_cds.insert(catalog_number);

        int counter = 0;
        while (size_jill--) {
            scanf("%d", &catalog_number);
            if (jack_cds.find(catalog_number) != jack_cds.end())
                counter++;
        }

        printf("%d\n", counter);
    }
}