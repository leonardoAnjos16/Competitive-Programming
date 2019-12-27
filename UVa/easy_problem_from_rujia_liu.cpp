#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void merge(ii *array, ii *first, ii *second, int size) {
    int sizes[3], half = size / 2;
    sizes[0] = size;
    sizes[1] = half;
    sizes[2] = size - half;

    int counters[] = { 0, 0, 0 };
    while (counters[1] < sizes[1] && counters[2] < sizes[2]) {
        if (first[counters[1]].first <= second[counters[2]].first)
            array[counters[0]++] = first[counters[1]++];
        else
            array[counters[0]++] = second[counters[2]++];
    }

    if (counters[1] < sizes[1]) {
        for (int i = counters[1]; i < sizes[1]; i++)
            array[counters[0]++] = first[i];
    } else {
        for (int i = counters[2]; i < sizes[2]; i++)
            array[counters[0]++] = second[i];
    }
}

void merge_sort(ii *array, int size) {
    if (size > 1) {
        int half = size / 2;

        ii *first = new ii[half];
        ii *second = new ii[size - half];
        for (int i = 0; i < half; i++) {
            first[i] = array[i];
            second[i] = array[i + half];
        }

        if (half * 2 < size)
            second[half] = array[size - 1];

        merge_sort(first, half);
        merge_sort(second, size - half);
        merge(array, first, second, size);
    }
}

int binary_search(ii array[], int size, int number) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (array[middle].first == number) return middle;
        else if (array[middle].first < number) left = middle + 1;
        else right = middle - 1;
    }

    return -1;
}

int main() {
    int size, num_queries;
    while (cin >> size >> num_queries) {
        ii *array = new ii[size];
        for (int i = 0; i < size; i++) {
            int number;
            scanf("%d", &number);

            array[i].first = number;
            array[i].second = i;
        }

        merge_sort(array, size);

        for (int i = 0; i < num_queries; i++) {
            int ocurr, number;
            scanf("%d %d", &ocurr, &number);

            int index = binary_search(array, size, number);
            if (index == -1) printf("0\n");
            else {
                do {
                    index--;
                } while (index >= 0 && array[index].first == number);

                index += ocurr;
                if (index < size && array[index].first == number) printf("%d\n", (array[index].second + 1));
                else printf("0\n");
            }
        }
    }
}