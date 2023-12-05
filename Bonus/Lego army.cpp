#include <iostream>
#include <queue>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        pq.push(k);
    }
    int count = 0;
    while (pq.top() < m)
    {
	    if (pq.size() < 2)
	    {
		    std::cout << -1;
            return 0;
	    }
	    int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + 2 * b;
        pq.push(c);
        count++;
    }

    std::cout << count;
}
