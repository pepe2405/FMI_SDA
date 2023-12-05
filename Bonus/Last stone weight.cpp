#include <iostream>
#include <queue>

int main()
{
    int n;
    std::cin >> n;
    std::priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        pq.push(k);
    }
    while (pq.size() != 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a - b;
        pq.push(c);
    }

    std::cout << pq.top();
}
