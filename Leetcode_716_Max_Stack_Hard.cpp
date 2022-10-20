class MaxStack {
public:
    MaxStack() {
        this->maxTime = 0;
    }
    
    void push(int x) {
        time = maxTime + 1;
        maxTime++;
        time_map[time] = x;             //O(logn)
        maxPQ.push(Value(x, time));     //O(logn)
    }
    
    int pop() {
        time = prev(time_map.end())->first;
        int value = time_map[time];     //O(1)
        time_map.erase(time);           //O(logn)
        return value;
    }
    
    int top() {
        time = prev(time_map.end())->first;
        return time_map[time];          //O(1)
    }
    
    int peekMax() {
        while (time_map.find(maxPQ.top().time) == time_map.end())
        {
            maxPQ.pop();                //O(logn)
        }
        return maxPQ.top().val;
    }
    
    int popMax() {
        while (time_map.find(maxPQ.top().time) == time_map.end())
        {
            maxPQ.pop();                //O(logn)
        }
        int value = maxPQ.top().val;    //O(1)
        int t = maxPQ.top().time;       //O(1)
        maxPQ.pop();                    //O(logn)
        time_map.erase(t);              //O(logn)
        return value;
    }
    
    int time;
    int maxTime;
    map<int, int> time_map;
    
    class Value {
    public:
        int val;
        int time;
        Value (int val_, int time_) : val(val_), time(time_) {}
    };
    struct valueComp {
        bool operator() (Value const& v1, Value const& v2) const {
            if (v1.val == v2.val)
            {
                return v1.time < v2.time;
            }
            return v1.val < v2.val;
        }    
    };
    priority_queue<Value, vector<Value>, valueComp> maxPQ;
};