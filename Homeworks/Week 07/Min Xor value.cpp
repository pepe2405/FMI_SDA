#include <iostream>
#include <set>
#include <climits>
#include <vector>
using namespace std;

int findMinimumXOR(set<int>& arr, int newNum) {
	int minimum = INT_MAX;

	auto it = arr.lower_bound(newNum);

	if (it != arr.end()) {
		minimum = min(minimum, *it ^ newNum);
	}

	if (it != arr.begin())
	{
		it--;

		minimum = min(minimum, *it ^ newNum);
	}

	return minimum;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n = 0;
	cin >> n;

	set<int> arr;
	vector<int> result;

	arr.insert(0);

	int minimum = INT_MAX;
	for (int i = 0; i < n; i++) {
		int current;
		std::cin >> current;

		if (arr.find(current) == arr.end()) {
			int l = findMinimumXOR(arr, current);
			minimum = std::min(minimum, l);
			result.push_back(minimum);
			arr.insert(current);
		}
		else {
			result.push_back(minimum);
		}


	}

	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}