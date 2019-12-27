#include <bits/stdc++.h>

using namespace std;

#define MAX 3000

typedef pair<int, int> int_pair;

struct Heap {
    vector<int_pair> heap;
    int size;

    Heap() {
        this->heap.push_back({0, 0});
        this->size = 0;
    }

    void insert(int q_num, int time) {
        this->heap.push_back({q_num, time});
        this->size++;

        bool done = false;
        for (int i = this->size; i > 1 && !done; i /= 2) {
            if (compare(this->heap[i], this->heap[i / 2])) {
                int_pair aux = this->heap[i];
                this->heap[i] = this->heap[i / 2];
                this->heap[i / 2] = aux;
            } else done = true;
        }
    }

    int_pair remove() {
        int_pair first = this->heap[1];
        this->heap[1] = this->heap[this->size--];
        this->heap.pop_back();
        this->heapify();
        return first;
    }

    void heapify(int index = 1) {
        if ((index * 2) <= this->size) {
            int son_index = index * 2;
            if (son_index < this->size && compare(this->heap[son_index + 1], this->heap[son_index])) son_index++;

            if (compare(this->heap[son_index], this->heap[index])) {
                int_pair aux = this->heap[index];
                this->heap[index] = this->heap[son_index];
                this->heap[son_index] = aux;
                this->heapify(son_index);
            }
        }
    }

    bool compare(int_pair element_1, int_pair element_2) {
        int q_num_1 = element_1.first;
        int time_1 = element_1.second;

        int q_num_2 = element_2.first;
        int time_2 = element_2.second;
        
        if (time_1 < time_2 || (time_1 == time_2 && (q_num_1 < q_num_2))) return true;
        else return false;
    }
};

int main() {
    char task[9];
    scanf("%s", task);

    Heap heap;
    int periods[MAX];

    while (task[0] != '#') {
        int q_num, period;
        scanf("%d %d", &q_num, &period);

        heap.insert(q_num, period);
        periods[q_num - 1] = period;

        scanf("%s", task);
    }

    int num_queries;
    scanf("%d", &num_queries);

    while (num_queries--) {
        int_pair next = heap.remove();
        int q_num = next.first;
        int time = next.second;

        printf("%d\n", q_num);
        heap.insert(q_num, (time + periods[q_num - 1]));
    }
}