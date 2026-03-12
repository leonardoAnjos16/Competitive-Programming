#include "bits/stdc++.h"
using namespace std;

struct node{
    int cartas[13];
    bool temCoringa, podePassar;
};

vector<node> jogador;

bool venceu(int i){
    for(int j = 0; j < 13; j++){
        if(jogador[i].cartas[j] == 4) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    jogador.resize(n);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int t = 0; t < 13; t++){
            jogador[i].cartas[t] = 0;
        }
        jogador[i].temCoringa = false;
        jogador[i].podePassar = true;
        for(int j = 0; j < s.length(); j++){
            char c = s[j];
            if(c == 'A') jogador[i].cartas[0]++;
            else if(c == 'D') jogador[i].cartas[9]++;
            else if(c == 'Q') jogador[i].cartas[10]++;
            else if(c == 'J') jogador[i].cartas[11]++;
            else if(c == 'K') jogador[i].cartas[12]++;
            else jogador[i].cartas[c - '1']++;
        }
    }

    for(int i = 0; i < n; i++){
        if(venceu(i) && i+1 != k){
            cout << i+1 << '\n';
            return 0;
        }
    }

    int atual = k-1, nxt;

    jogador[atual].temCoringa = true;
    jogador[atual].podePassar = false;

    while(1){  
        nxt = (atual + 1) % n; 
        if(jogador[atual].temCoringa && jogador[atual].podePassar){
            jogador[atual].temCoringa = false;
            jogador[atual].podePassar = true;

            jogador[nxt].temCoringa = true;
            jogador[nxt].podePassar = false;
        }
        else{
            jogador[atual].podePassar = true;
            int min_ = 50, idx = -1;
            for(int i = 0; i < 13; i++){
                if(jogador[atual].cartas[i] < min_ && jogador[atual].cartas[i] != 0){
                    idx = i;
                    min_ = jogador[atual].cartas[i];
                }
            }
            jogador[atual].cartas[idx]--;
            jogador[nxt].cartas[idx]++;
        }
        if(venceu(atual)){
            cout << atual + 1 << '\n';
            return 0;
        }
        atual = nxt;
    }

    return 0;
}