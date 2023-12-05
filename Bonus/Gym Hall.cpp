#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Member
{
	long long start;
	long long end;

	Member(long long start, long long end)
	{
		this->start = start;
		this->end = end;
	}
};

struct compareStart
{
	bool operator()(const Member& first, const Member& second) const
	{
		return first.start > second.start;
	}
};

struct compareEnd
{
	bool operator()(const Member& first, const Member& second) const
	{
		return first.end > second.end;
	}
};


int main()
{
	long long n = 0;
	std::cin >> n;

	std::priority_queue<Member, std::vector<Member>, compareStart> outsideGym;
	std::priority_queue<Member, std::vector<Member>, compareEnd> insideGym;

	for (long long i = 0; i < n; i++)
	{
		long long x = 0, y = 0;
		std::cin >> x >> y;
		Member m(x, y);
		outsideGym.push(m);
	}

	long long maxSize = 0;

	while (!outsideGym.empty())
	{
		Member curr = outsideGym.top();
		outsideGym.pop();
		insideGym.push(curr);
		while(!insideGym.empty() && curr.start >= insideGym.top().end)
		{
			insideGym.pop();
		}
		


		if (maxSize < insideGym.size())
			maxSize = insideGym.size();
	}

	std::cout << maxSize;
}
