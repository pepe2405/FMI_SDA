#include <complex>
#include <iostream>
#include <queue>

struct Point
{
    int x = 0;
    int y = 0;
    long long dist = 0;
    Point(int x, int y) : x(x), y(y) {}
    void getDist(int otherX, int otherY)
    {
        dist = (long long)(otherX - x) * (otherX - x) + (long long)(otherY - y) * (otherY - y);
    }

    bool operator>(const Point& other) const
    {
        if (dist == other.dist)
        {
            if (x == other.x)
            {
                return y > other.y;
            }
            return x > other.x;

        }
        return dist > other.dist;
    }
};

int main()
{
    std::priority_queue<Point, std::vector<Point>, std::greater<Point>> pq;
    int x = 0, y = 0, k = 0, n = 0;
    std::cin >> x >> y >> n >> k;
    Point person(x, y);
    for (int i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        Point point(x, y);
        point.getDist(person.x, person.y);
        pq.push(point);
    }
    for (int i = 0; i < k; i++)
    {
        std::cout << pq.top().x << ' ' << pq.top().y << std::endl;
        pq.pop();
    }
    return 0;

}
