#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n = 0;
    std::cin >> n;
    std::deque<long long> res;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        std::cin >> k;
        if (k > 0)
            res.push_back(k);
        else
        {
            while (true)
            {
	            if (res.empty())
	            {
		            std::cout << k << ' ';
                    break;
	            }
                if (abs(k) > res.back())
                {
                    res.pop_back();
                }
                else if (abs(k) < res.back())
                {
                    break;
                }
                else
                {
                    res.pop_back();
                    break;
                }
            }
        }
    }
    while (!res.empty())
    {
	    std::cout << res.front() << ' ';
        res.pop_front();
    }
}
