#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_pokemons;
    scanf("%d", &num_pokemons);
    
    priority_queue<int> pokemons;
    while (num_pokemons--) {
        int pokemon; scanf("%d", &pokemon);
        pokemons.push(pokemon);
    }
    
    int num_days = 1;
    int days_left = pokemons.top(); pokemons.pop();
    
    while (!pokemons.empty()) {
        int pokemon = pokemons.top(); pokemons.pop();
        if (--days_left < pokemon) days_left = pokemon;
        num_days++;
    }
    
    num_days += days_left + 1;
    printf("%d\n", num_days);
}