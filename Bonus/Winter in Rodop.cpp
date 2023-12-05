#include <iostream>
#include <queue>

struct Apple
{
    int x = 0;
    int y = 0;
    Apple(int x, int y) : x(x), y(y){}
};

int main()
{
    int n = 0, m = 0, t = 0;
    std::cin >> n >> m >> t;

    std::queue<Apple> arr;
    int count = 0;
    bool rotten[n + 1][m + 1] = {};
    int x = 0, y = 0;
    while (std::cin >> x >> y)
    {
        Apple apple(x, y);
        arr.push(apple);
        count++;
        rotten[x][y] = true;
    }

    for (int i = 0; i < t; i++)
    {
        int size = arr.size();
        for (int j = 0; j < size; j++)
        {
            int first = 0, second = 0;
            first = arr.front().x;
            second = arr.front().y;
            if (first - 1 > 0 && first - 1 <= n)
            {
	            if (rotten[first - 1][second] == false)
	            {
                    count++;
                    Apple newApp(first - 1, second);
                    arr.push(newApp);
                    rotten[first - 1][second] = true;
	            }
            }
            if (first + 1 > 0 && first + 1 <= n)
            {
                if (rotten[first + 1][second] == false)
                {
                    count++;
                    Apple newApp(first + 1, second);
                    arr.push(newApp);
                    rotten[first + 1][second] = true;
                }
            }
            if (second - 1 > 0 && second - 1 <= m)
            {
                if (rotten[first][second - 1] == false)
                {
                    count++;
                    Apple newApp(first, second - 1);
                    arr.push(newApp);
                    rotten[first][second - 1] = true;
                }
            }
            if (second + 1 > 0 && second + 1 <= m)
            {
                if (rotten[first][second + 1] == false)
                {
                    count++;
                    Apple newApp(first, second + 1);
                    arr.push(newApp);
                    rotten[first][second + 1] = true;
                }
            }
            arr.pop();
        }
    }

    std::cout <<  n * m - count;
}
