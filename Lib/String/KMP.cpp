template<typename T>
struct KMP {
private:
    int n;
    T pattern;
    vector<int> border;

public:
    KMP(T pattern) {
        n = pattern.size();
        this->pattern = pattern;
        get_border();
    }

    vector<int> get_matches(T text) {
        vector<int> matches;
        int m = text.size(), last = 0;

        for (int i = 0; i < m; i++) {
            int j = last;
            while (j > 0 && (j >= n || pattern[j] != text[i]))
                j = border[j - 1];

            last = j < n && pattern[j] == text[i] ? j + 1 : 0;
            if (last == n) matches.push_back(i);
        }

        return matches;
    }

private:
    void get_border() {
        border.assign(n, 0);
        for (int i = 1; i < n; i++) {
            int j = border[i - 1];
            while (j > 0 && pattern[j] != pattern[i])
                j = border[j - 1];

            if (pattern[j] == pattern[i])
                border[i] = j + 1;
        }
    }
};