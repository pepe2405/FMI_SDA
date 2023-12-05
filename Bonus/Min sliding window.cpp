#include <deque>
#include <iostream>
#include <vector>

int main()
{
    long long sum = 0;
    std::vector<long long> arr;
    std::deque<long long> deq;
    long long n = 0, k = 0;
    std::cin >> n >> k;
    for (long long i = 0; i < n; i++)
    {
        long long l = 0;
        std::cin >> l;
        arr.push_back(l);
    }

    for (long long i = 0; i < k; i++)
    {
	    while (!deq.empty() && deq.back() > arr[i])
            deq.pop_back();

        deq.push_back(arr[i]);
    }

    sum += deq.front();

    long long size = arr.size();
    for (int i = k; i < size; i++)
    {
	    if (deq.front() == arr[i - k])
            deq.pop_front();

        while (!deq.empty() && deq.back() > arr[i])
            deq.pop_back();

        deq.push_back(arr[i]);
        sum += deq.front();
    }

    std::cout << sum;
}
