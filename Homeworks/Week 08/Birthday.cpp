#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Person {
    long ind;
    long timeIn;
    long timeOut;
    int chair;

    Person(long timeIn, long timeOut, long index) : ind(index), timeIn(timeIn), timeOut(timeOut) {
        chair = -1;
    }

    bool operator<(const Person& other) const {
	    if (timeIn == other.timeIn)
	    {
            return timeOut > other.timeOut;
	    }
        return timeIn > other.timeIn;
    }
};

struct Comp {
    bool operator()(const Person& first, const Person& second) const {
        return first.timeOut > second.timeOut;
    }
};

int main() {
    long n;
    cin >> n;

    priority_queue<Person> outside;
    priority_queue<Person, vector<Person>, Comp> inside;
    


    for (long i = 0; i < n; i++) {
        long x, y;
        cin >> x >> y;
        outside.emplace(x, y, i);
    }

    long T;
    cin >> T;
    priority_queue<long, vector<long>, greater<long>> chairs;

    for (int i = 0; i < n; i++) {
        chairs.push(i);
    }

    long long free  = 0;

    while (!outside.empty()) {
        Person currFriend = outside.top();
        outside.pop();

        while (!inside.empty() && inside.top().timeOut <= currFriend.timeIn) {
            chairs.push(inside.top().chair);
            inside.pop();
        }

        currFriend.chair = chairs.top();
        if (currFriend.ind == T) {
            free = currFriend.chair;
            break;
        }

        chairs.pop();
        inside.push(currFriend);
    }

    cout << free;
    return 0;
}