#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    private:
        vector<int> numbers, tree;
        int size;

        int left(int i) { return (i << 1); }
        int right(int i) { return (i << 1) + 1; }

        void build(int i, int L, int R) {
            if (L == R) {
                if (numbers[L] < 0) tree[i] = -1;
                else if (numbers[L] > 0) tree[i] = 1;
                else tree[i] = 0;
            } else {
                int middle = (L + R) / 2;
                build(left(i), L, middle);
                build(right(i), middle + 1, R);

                tree[i] = tree[left(i)] * tree[right(i)];
            }
        }

        void update(int i, int L, int R, int updated_index) {
            if (L > updated_index || R < updated_index) return;
            if (L == R) {
                if (numbers[L] < 0) tree[i] = -1;
                else if (numbers[L] > 0) tree[i] = 1;
                else tree[i] = 0;
            } else {
                int middle = (L + R) / 2;
                update(left(i), L, middle, updated_index);
                update(right(i), middle + 1, R, updated_index);

                tree[i] = tree[left(i)] * tree[right(i)];
            }
        }

        int rpq(int i, int L, int R, int a, int b) {
            if (L > b || R < a) return 2;
            if (L >= a && R <= b) return tree[i];

            int middle = (L + R) / 2;
            int p1 = rpq(left(i), L, middle, a, b);
            int p2 = rpq(right(i), middle + 1, R, a, b);

            if (p1 == 2) return p2;
            if (p2 == 2) return p1;
            return p1 * p2;
        }

    public:
        SegmentTree(const vector<int> &_numbers) {
            numbers = _numbers;
            size = numbers.size();
            tree.reserve(4 * size);
            build(1, 0, size - 1);
        }

        void update(int i, int v) {
            numbers[i] = v;
            update(1, 0, size - 1, i);
        }

        int rpq(int a, int b) {
            return rpq(1, 0, size - 1, a, b);
        }
};

int main() {
    int size, num_rounds;
    while (scanf("%d %d", &size, &num_rounds) != EOF) {
        vector<int> numbers(size);
        for (int i = 0; i < size; i++)
            scanf("%d", &numbers[i]);

        scanf("\n");

        SegmentTree st(numbers);
        while (num_rounds--) {
            char type; scanf("%c", &type);
            if (type == 'C') {
                int i, v; scanf("%d %d\n", &i, &v);
                st.update(i - 1, v);
            } else {
                int i, j; scanf("%d %d\n", &i, &j);
                int rpq = st.rpq(i - 1, j - 1);

                if (rpq == -1) printf("-");
                else if (rpq == 1) printf("+");
                else printf("0");
            }
        }

        printf("\n");
    }
}