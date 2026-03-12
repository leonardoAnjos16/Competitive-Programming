#include <bits/stdc++.h>

using namespace std;

int time_to_kill(int health, int damage, int reload) {
    int hits = (health + damage - 1) / damage;
    return 2 * (hits - 1) * reload + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, d1, t1;
    cin >> h1 >> d1 >> t1;

    int h2, d2, t2;
    cin >> h2 >> d2 >> t2;

    int tk1 = time_to_kill(h1, d2, t2);
    int tk2 = time_to_kill(h2, d1, t1);

    if (tk1 == tk2) cout << "draw\n";
    else if (tk1 > tk2) cout << "player one\n";
    else cout << "player two\n";
}