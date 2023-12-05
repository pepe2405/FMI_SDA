#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (auto& num : arr)
        num = num == k ? 0 : num > k ? 1 : -1;

    int ind = 0, sum = 0, res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            ind = i;
            break;
        }
    }
    unordered_map<int, int> map;
    for (int i = ind; i >= 0; i--)
    {
        sum += arr[i];
        map[sum]++;
    }
    sum = 0;
    for (int i = ind; i < n; i++)
    {
        sum += arr[i];
        res += map[-sum];
    }
    std::cout << res;
}