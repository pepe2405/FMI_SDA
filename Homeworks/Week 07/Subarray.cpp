#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    std::set <int> set;
    vector<int> res;
    vector<int> seq(m);

	for (int i = 1; i <= n; i++) 
        set.insert(i);
    
    for (int i = 0; i < m; i++) 
    {
        int curr = 0;
        cin >> curr;
        seq[i] = curr;
        set.erase(curr);
    }

    auto first = set.begin();
    auto second = seq.begin();

    while (res.size() != n - 1 && first != set.end() && second != seq.end()) {
        if (*first < *second) {
            res.push_back(*first);
            first++;
        }
        else {
            res.push_back(*second);
            second++;
        }

    }

    while (first != set.end()) {
        res.push_back(*first);
        first++;
    }

    while (second != seq.end()) {
        res.push_back(*second);
        second++;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}