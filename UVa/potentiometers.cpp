#include <bits/stdc++.h>

using namespace std;

class Fenwick_Tree {
    private:
        vector<int> tree;
        int size;

        int LSO(int number) {
            return (number & -number);
        }

        int RSQ(int index) {
            int sum = 0;
            while (index > 0) {
                sum += this->tree[index];
                index -= this->LSO(index);
            }

            return sum;
        }

    public:
        Fenwick_Tree(int size) {
            this->tree.assign(size + 1, 0);
            this->size = size;
        }

        void adjust(int index, int difference) {
            while (index <= this->size) {
                this->tree[index] += difference;
                index += this->LSO(index);
            }
        }

        int RSQ(int first_index, int second_index) {
            return this->RSQ(second_index) - this->RSQ(first_index - 1);
        }
};

int main() {
    int size, case_num = 1;
    while (scanf("%d", &size), size) {
        if (case_num > 1)  printf("\n");

        vector<int> potmeters(size);
        for (int i = 0; i < size; i++)
            scanf("%d", &potmeters[i]);

        Fenwick_Tree tree(size);
        for (int i = 0; i < size; i++)
            tree.adjust(i + 1, potmeters[i]);

        printf("Case %d:\n", case_num++);

        char action[10];
        while (scanf("%s", action), strcmp(action, "END")) {
            if (action[0] == 'S') {
                int index, new_value;
                scanf("%d %d", &index, &new_value);

                int difference = new_value - potmeters[index - 1];
                potmeters[index - 1] = new_value;
                tree.adjust(index, difference);
            } else {
                int first_index, last_index;
                scanf("%d %d", &first_index, &last_index);

                int RSQ = tree.RSQ(first_index, last_index);
                printf("%d\n", RSQ);
            }
        }
    }
}