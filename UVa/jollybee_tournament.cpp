#include<bits/stdc++.h>

using namespace std;

#define MAX 1 << 10

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int N, M;
        scanf("%d %d", &N, &M);

        bitset<MAX> players;
        int size = 1 << N;

        for (int i = 0; i < size; i++)
            players.set(i);

        for (int i = 0; i < M; i++) {
            int player; scanf("%d", &player);
            players.reset(player - 1);
        }

        int num_wos = 0;
        while (size > 1) {
            for (int i = 0; i < size; i += 2) {
                if (players.test(i) != players.test(i + 1))
                    num_wos++;

                if (!players.test(i) && !players.test(i + 1))
                    players.reset(i / 2);
                else
                    players.set(i / 2);
            }

            size = size >> 1;
        }

        printf("%d\n", num_wos);
    }
}