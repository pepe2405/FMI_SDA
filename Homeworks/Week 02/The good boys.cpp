#include <algorithm>
#include <iostream>
#include <vector>

bool comparison(const std::pair<std::pair<double, int>, double>& lhs, const std::pair<std::pair<double, int>, double>& rhs)
{
	const double eps = std::numeric_limits<double>::epsilon();
	if (abs(lhs.first.first - rhs.first.first) < eps)
	{
		return lhs.second > rhs.second;
	}
	return lhs.first.first > rhs.first.first;
}


int main()
{
    int n = 0;
    std::cin >> n;
	std::vector<std::pair<std::pair<double,int>, double>> arr;
	for (int i = 0; i < n; i++)
	{
		double d = 0;
		double t = 0;
		std::cin >> d >> t;

		double ef = ((d / 2.0) * (d / 2.0)) / t;

		std::pair<double, int> p(ef, i + 1);
		std::pair<std::pair<double, int>, double> el(p, d);
		arr.push_back(el);
	}
	std::sort(arr.begin(), arr.end(), comparison);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i].first.second << ' ';
	}
}

