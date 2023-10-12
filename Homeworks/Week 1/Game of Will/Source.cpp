#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int main()
{
    int n = 0;
    int k = 0;
    unsigned inp = 0;
    std::cin >> n >> k;
    std::vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        std::cin >> inp;
        arr.push_back(inp);
    }
    std::sort(arr.begin(), arr.end());
    int min = arr[n - 1];
    for (int i = 0; i <= n - k; i++)
    {
        if (arr[i + k - 1] - arr[i] < min)
            min = arr[i + k - 1] - arr[i];
    }
    std::cout << min;
}