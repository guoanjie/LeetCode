#include <iostream>
#include <limits>
#include <map>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
        events[0] = 0;
        K = 0;
    }
    
    int book(int start, int end) {
        auto it = events.upper_bound(start); --it;
        events[start] = it->second;
        it = events.upper_bound(end);   --it;
        events[end] = it->second;

        auto b = events.find(start), e = events.find(end);
        for (it = b; it != e; ++it)
            K = max(++it->second, K);

        return K;
    }

private:
    map<int, int> events;
    int K;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

int main() {
    MyCalendarThree obj;
    cout << obj.book(10, 20) << endl    // returns 1
         << obj.book(50, 60) << endl    // returns 1
         << obj.book(10, 40) << endl    // returns 2
         << obj.book(5 , 15) << endl    // returns 3
         << obj.book(5 , 10) << endl    // returns 3
         << obj.book(25, 55) << endl;   // returns 3
    return 0;
}
