#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int groups; cin >> groups;
    while (groups--) {
        int people; cin >> people;
        vector<string> names(people);
        
        for (int i = 0; i < people; i++)
            cin >> names[i];

        map<string, int> money;
        for (int i = 0; i < people; i++) {
            string name; int have;
            cin >> name >> have;

            int friends; cin >> friends;
            if (!friends) continue;

            money[name] -= have;
            for (int j = 0; j < friends; j++) {
                string friend_name; cin >> friend_name;
                money[friend_name] += have / friends;
            }

            money[name] += have % friends;
        }

        for (int i = 0; i < people; i++)
            cout << names[i] << " " << money[names[i]] << "\n";

        cout << "\n";
    }
}