#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> ll_pair;
typedef pair<ll, ll_pair> triple;
 
int main() {
    int num_topics;
    scanf("%d", &num_topics);
    
    priority_queue<triple> heap;
    for (int i = 0; i < num_topics; i++) {
        ll id, score, posts, likes, comments, shares;
        scanf("%lld %lld %lld %lld %lld %lld", &id, &score, &posts, &likes, &comments, &shares);
        
        ll new_score = (50 * posts) + (5 * likes) + (10 * comments) + (20 * shares);
        ll diff_score = new_score - score;
        heap.push({diff_score, {id, new_score}});
    }
    
    ll_pair top_five[5];
    for (int i = 0; i < 5; i++) {
        triple aux = heap.top();
        heap.pop();
        
        top_five[i] = aux.second;
        printf("%lld %lld\n", top_five[i].first, top_five[i].second);
    }
}