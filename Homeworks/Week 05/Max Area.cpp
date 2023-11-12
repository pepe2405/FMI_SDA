#include <iostream>
#include <vector>

int main() {
    long long n = 0, maxArea = 0;
    std::cin >> n;
    std::vector<long long> arr;

    for (int i = 0; i < n; i++) {
        int k = 0;
        std::cin >> k;
        arr.push_back(k);
    }

    for (int i = 0; i < n; i++) {
        long long curr = arr[i];
        int width = 1;
        for (int k = i + 1; k < n; k++) {
            if (arr[i] <= arr[k])
            {
                width++;
            }
            else {
                break;
            }
        }
        for (int k = i - 1; k >= 0; k--) {
            if (arr[i] <= arr[k])
                width++;
            else 
                break;
        }
        curr = curr * width;
        if (maxArea < curr)
            maxArea = curr;
    }

    std::cout << maxArea;

    return 0;
}
