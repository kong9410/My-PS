#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

bool visit[9] = { false };
vector<int> v;
vector<vector<int>> vl;
void backtracking(int n, int m) {
	queue<int> q;
	if (v.size() == m) {
		for (auto it = v.begin(); it != v.end(); it++)
			cout << *it << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		
		if (visit[i]) continue;
		visit[i] = true;
		v.push_back(i);
		q.push(i);
		backtracking(n, m);
		v.pop_back();
	}
	while (!q.empty()) {
		visit[q.front()] = false;
		q.pop();
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	backtracking(n, m);
  
  return 0;
}
