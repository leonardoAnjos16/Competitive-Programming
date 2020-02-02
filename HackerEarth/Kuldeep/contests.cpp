#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
int main() {
    int num_contests;
    scanf("%d", &num_contests);
    
    vector<ii> contests;
    for (int i = 0; i < num_contests; i++) {
        char times[100]; scanf("%s", times);
        int init_hour, init_minute, end_hour, end_minute;
        
        sscanf(times, "%d:%d-%d:%d", &init_hour, &init_minute, &end_hour, &end_minute);
        int init_time = (init_hour * 60) + init_minute;
        int end_time = (end_hour * 60) + end_minute;
        
        contests.push_back({init_time, end_time});
    }
    
    bool need_moderator = false;
    for (int i = 0; i < num_contests && !need_moderator; i++) {
        for (int j = 0; j < num_contests && !need_moderator; j++) {
            if ((contests[i].first > contests[j].first && 
                 contests[i].first < contests[j].second) ||
                (contests[i].second > contests[j].first &&
                 contests[i].second < contests[j].second))
                need_moderator = true;
        }
    }
    
    printf("%s\n", need_moderator ? "Will need a moderator!" : "Who needs a moderator?");
}