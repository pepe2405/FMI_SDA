#include <algorithm>
#include <iostream>
#include <vector>

void MergeSortedIntervals(std::vector<int>& v, int s, int m, int e) {

	std::vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}
void MergeSort(std::vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0, k = 0;
	std::cin >> n >> k;
	std::vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int el = 0;
		std::cin >> el;
		arr.push_back(el);
	}

	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < k; i++)
	{
		int count = 0;

		int l = 0, r = 0;
		std::cin >> l >> r;
		auto lower = std::lower_bound(arr.begin(), arr.end(), l);
		int lowerIndex = (lower - arr.begin());
		auto upper = std::upper_bound(arr.begin(), arr.end(), r);
		int upperIndex = (upper - arr.begin());
		for (int j = lowerIndex; j < upperIndex; j++)
		{
				count++;
		}
		std::cout << count << std::endl;
	}
}

