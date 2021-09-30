#include <bits/stdc++.h>

using namespace std;

const int MAX = 205;

long long int to_ms(int h, int m, int s, int ms) {
    long long int ans = h * 60 * 60 * 1000LL;
    ans += m * 60 * 1000LL;
    ans += s * 1000LL;
    ans += ms;
    return ans;
}

pair<long long int, long long int> to_time(string line) {
    string start = line.substr(0, 12);
    int h = stoi(start.substr(0, 2));
    int m = stoi(start.substr(3, 2));
    int s = stoi(start.substr(6, 2));
    int ms = stoi(start.substr(9));
    long long int l = to_ms(h, m, s, ms);

    string end = line.substr(17);
    h = stoi(end.substr(0, 2));
    m = stoi(end.substr(3, 2));
    s = stoi(end.substr(6, 2));
    ms = stoi(end.substr(9));
    long long int r = to_ms(h, m, s, ms);

    return make_pair(l, r);
}

string zero_padding(int n, int pad = 2) {
    string ans = "";
    if (n < 10)
        ans += "0";

    if (pad > 2 && n < 100)
        ans += "0";

    return ans + to_string(n);
}

string time_format(long long int ms) {
    int h = ms / (60 * 60 * 1000LL);
    ms %= 60 * 60 * 1000LL;

    int m = ms / (60 * 1000LL);
    ms %= 60 * 1000LL;

    int s = ms / 1000LL;
    ms %= 1000LL;

    string h_str = zero_padding(h);
    string m_str = zero_padding(m);
    string s_str = zero_padding(s);
    string ms_str = zero_padding(ms, 3);

    return h_str + ":" + m_str + ":" + s_str + "," + ms_str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; long double delay;
    cin >> N >> delay;

    vector<tuple<int, pair<long long int, long long int>, string>> subtitles(N);
    for (int i = 0; i < N; i++) {
        int order;
        cin >> order;
        cin.ignore();

        string line;
        getline(cin, line);

        pair<long long int, long long int> time = to_time(line);

        time.first += delay * 1000;
        time.second += delay * 1000;

        getline(cin, line);
        string subs = line;

        getline(cin, line);
        if (!line.empty()) {
            subs += "\n" + line;
            getline(cin, line);
        }

        subtitles[i] = make_tuple(order, time, subs);
    }

    sort(subtitles.begin(), subtitles.end());

    for (int i = 0; i < N; i++) {
        if (i) cout << "\n";

        auto [order, time, subs] = subtitles[i];
        cout << order << "\n";
        cout << time_format(time.first) << " --> " << time_format(time.second) << "\n";
        cout << subs << "\n";
    }
}