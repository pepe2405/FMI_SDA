#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Group {
    long count;
    int x;
    int y;

    Group(long count, int x, int y) : count(count), x(x), y(y) {}
};

struct CompOutside {
    bool operator()(const Group& first, const Group& second) const
	{
        return first.y > second.y;
    }
};

struct CompInside {
    bool operator()(const Group& first, const Group& second) const
	{
        return first.x > second.x;
    }
};

int main() {
    long countQueries;
    cin >> countQueries;

    for (int i = 0; i < countQueries; i++) 
    {
        long n, c;
        cin >> n >> c;

        priority_queue<Group, vector<Group>, CompInside> outside;
        priority_queue<Group, vector<Group>, CompOutside> inside;


        for (int j = 0; j < n; j++) 
        {
            int k, x, y;
            cin >> k >> x >> y;

            outside.emplace(k, x, y);
        }

        bool x = 1;
        long currentCountPeople = 0;

        while (!outside.empty()) 
        {
            int nextArrive = outside.top().x;
            int nextDepart = INT_MAX;
           
            if(!inside.empty()) 
                nextDepart = inside.top().y;
           
            if (nextArrive < nextDepart) 
            { 
                Group current = outside.top();
                currentCountPeople += current.count;
               
                outside.pop();
                inside.push(current);

                if (c < currentCountPeople)
                {
                    x = 0;
                    break;
                }
            }
            else {
                while (!inside.empty() && inside.top().y <= nextArrive) 
                { 
                    Group current = inside.top();
                    inside.pop();

                    currentCountPeople -= current.count;
                }

            }

        }
        cout << x << endl;

    }

    return 0;
}