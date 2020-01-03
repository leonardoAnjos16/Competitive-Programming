#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    long long int position;

    while (scanf("%d %lld", &size, &position), size, position) {
        int line, column;
        line = column = (size + 1) / 2;

        long long int counter = 1;
        int direction = 0, num_blocks = 1;
        
        while (counter < position) {
            if (direction == 0) line += num_blocks;
            else if (direction == 1) column -= num_blocks;
            else if (direction == 2) line -= num_blocks;
            else column += num_blocks;

            counter += num_blocks;
            direction = ++direction % 4;

            if (direction % 2 == 0) num_blocks++;
        }

        if (counter > position) {
            direction = (direction + 3) % 4;
            int aux = counter - position;

            if (direction == 0) line -= aux;
            else if (direction == 1) column += aux;
            else if (direction == 2) line += aux;
            else column -= aux;
        }

        printf("Line = %d, column = %d.\n", line, column);
    }
}