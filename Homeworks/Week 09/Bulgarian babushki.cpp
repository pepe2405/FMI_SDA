#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>

int main()
{
    int n;
    std::cin >> n;
    int min = INT_MAX;

    //value, index
    std::unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;

        if (map.find(k) == map.end())
            map.insert({ k, i });
        else
        {
            if(i - map[k] < min)
                min = i - map[k];
        }
            

    }

    std::cout << min;
}
