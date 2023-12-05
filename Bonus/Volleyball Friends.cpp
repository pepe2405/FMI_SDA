#include <iostream>
#include <set>

int main()
{
    int first, n;
    std::cin >> first >> n;
    std::set<int> set;
    set.insert(first);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (set.find(x) != set.end())
        {
            set.insert(y);
        }
    }

    std::cout << set.size();
}
