#include <bits/stdc++.h>
using namespace std;

int ans, d;
deque<int> pt;

void dfs(int step)
{
	if (step >= ans) return;
	if (abs(pt.front() - pt.back()) <= d) {
		ans = min(ans, step);
		return;
	}
	int ft = pt.front(), bk = pt.back();
	pt.erase(pt.begin()); dfs(step+1); pt.push_front(ft);
	pt.erase(pt.end()-1); dfs(step+1); pt.push_back(bk);
}

int main()
{
	int n; cin >> n >> d;
	while (n--)
	{
		int i; cin >> i;
		pt.push_back(i); 
	}
	sort(pt.begin(), pt.end());
	
	ans = pt.size()-1;
	
	if (pt.size() != 1) dfs(0);
	cout << ans << endl;
}
