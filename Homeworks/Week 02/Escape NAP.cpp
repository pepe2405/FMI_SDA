#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::vector<int> arr;
    std::cin >> n;
	    
    for (int i = 0; i < n; i++)
    {
        int el = 0;
        std::cin >> el;
        arr.push_back(el);
    }

    std::vector<int> copy = arr;
    std::sort(copy.begin(), copy.end());

    int k = 0, l = 0;

    for (int i = 0; i < n; i++)
    {
	    if (arr[i] != copy[i])
	    {
            k = i;
            break;
	    }
    }
    for (int i = n - 1; i >= 0; i--)
    {
	    if (arr[i] != copy[i])
	    {
            l = i;
            break;
	    }
    }

    if (l - k + 1 == 1)
    {
	    std::cout << 0;
        return 0;
    }
    std::cout << l - k + 1;
}
