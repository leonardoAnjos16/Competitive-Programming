#include <bits/stdc++.h>

using namespace std;

#define bs binary_search
#define lb lower_bound

const int MAX = 1e4 + 5;

int main() {
    int num_books;
    while (scanf("%d", &num_books) != EOF) {
        int books[MAX];
        for (int i = 0; i < num_books; i++)
            scanf("%d", &books[i]);

        sort(books, books + num_books);

        int price;
        scanf("%d", &price);

        int i = price / 2, j = price - i;
        int index = lb(books, books + num_books, i) - books;

        if (i == j && (index >= (num_books - 1) || books[index + 1] != i)) i--, j++;
        while (!(bs(books, books + num_books, i) && bs(books, books + num_books, j))) i--, j++;
        printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
    }
}