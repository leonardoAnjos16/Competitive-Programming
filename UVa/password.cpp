#include <bits/stdc++.h>

using namespace std;

int K;
char a[5][6], b[5][6];
char password[6], curr[6];

void get_password(int index = 0) {
    if (index >= 5 && --K == 0) strcpy(password, curr);
    else if (index < 5 && K) {
        char last = '-';
        for (int i = 0; i < 6 && K; i++) {
            if (a[index][i] != last && binary_search(b[index], b[index] + 6, a[index][i])) {
                curr[index] = a[index][i];
                get_password(index + 1);
            }

            last = a[index][i];
        }
    }
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        scanf("%d\n", &K);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++)
                scanf("%c", &a[j][i]);

            scanf("\n");
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++)
                scanf("%c", &b[j][i]);

            scanf("\n");
        }

        for (int i = 0; i < 5; i++) {
            sort(a[i], a[i] + 6);
            sort(b[i], b[i] + 6);
        }

        get_password();
        password[5] = '\0';

        if (K) printf("NO\n");
        else printf("%s\n", password);
    }
}