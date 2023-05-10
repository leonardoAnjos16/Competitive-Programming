template<typename T>
struct MinQueue {
private:
    queue<T> q;
    deque<T> mn;

public:
    void push(T v) {
        q.push(v);
        while (!mn.empty() && mn.back() > v)
            mn.pop_back();

        mn.push_back(v);
    }

    void pop() {
        assert(!q.empty());
        if (q.front() == mn.front())
            mn.pop_front();

        q.pop();
    }

    T min() {
        assert(!q.empty());
        return mn.front();
    }
};