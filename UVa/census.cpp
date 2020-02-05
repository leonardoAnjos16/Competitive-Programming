#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class SegmentTree {
    private:
        vi numbers;
        vector<ii> tree;
        int size;

        int left(int index) { return (index << 1); }
        int right(int index) { return (index << 1) + 1; }

        void build(int i, int L, int R) {
            if (L == R) tree[i] = {numbers[L], numbers[L]};
            else {
                int middle = (L + R) / 2;
                build(left(i), L, middle);
                build(right(i), middle + 1, R);

                tree[i] = {max(tree[left(i)].first, tree[right(i)].first), min(tree[left(i)].second, tree[right(i)].second)};
            }
        }

        void update(int i, int L, int R, int updated_index) {
            if (L > updated_index || R < updated_index) return;

            if (L == R) tree[i] = {numbers[updated_index], numbers[updated_index]};
            else {
                int middle = (L + R) / 2;
                update(left(i), L, middle, updated_index);
                update(right(i), middle + 1, R, updated_index);

                tree[i] = {max(tree[left(i)].first, tree[right(i)].first), min(tree[left(i)].second, tree[right(i)].second)};
            }
        }

        ii rmq(int i, int L, int R, int a, int b) {
            if (L > b || R < a) return {INT_MIN, INT_MAX};
            if (L >= a && R <= b) return tree[i];

            int middle = (L + R) / 2;
            ii c1 = rmq(left(i), L, middle, a, b);
            ii c2 = rmq(right(i), middle + 1, R, a, b);

            return {max(c1.first, c2.first), min(c1.second, c2.second)};
        }

    public:
        SegmentTree(const vi &_numbers) {
            numbers = _numbers;
            size = numbers.size();
            tree.reserve(4 * size);
            build(1, 0, size - 1);
        }

        void update(int index, int value) {
            numbers[index] = value;
            update(1, 0, size - 1, index);
        }

        ii rmq(int a, int b) {
            return rmq(1, 0, size - 1, a, b);
        }
};

int main() {
    int size; scanf("%d", &size);
    vector<vi> matrix; matrix.assign(size, vi(size));

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);

    vector<SegmentTree> trees;
    for (int i = 0; i < size; i++)
        trees.push_back(SegmentTree(matrix[i]));

    int num_queries;
    scanf("%d", &num_queries);

    while (num_queries--) {
        char query; scanf("%s", &query);
        if (query == 'q') {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            int max_population = INT_MIN, min_population = INT_MAX;
            for (int i = x1 - 1; i < x2; i++) {
                ii rmq = trees[i].rmq(y1 - 1, y2 - 1);
                max_population = max(max_population, rmq.first);
                min_population = min(min_population, rmq.second);
            }

            printf("%d %d\n", max_population, min_population);
        } else {
            int x, y, value;
            scanf("%d %d %d", &x, &y, &value);
            trees[x - 1].update(y - 1, value);
        }
    }
}