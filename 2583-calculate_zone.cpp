#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int field[101][101] = { 0 };
bool visit[101][101] = { false };
queue<pair<int, int> > Q;
vector<int> V;
int bfs(int m, int n) {
	int dirX[] = { 1, 0, -1, 0 };
	int dirY[] = { 0, 1, 0, -1 };
	int cnt = 1;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dirX[i];
			int dy = y + dirY[i];
			if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
			if (field[dx][dy] != 0) continue;
			if (visit[dx][dy]) continue;
			Q.push(make_pair(dx, dy));
			visit[dx][dy] = true;
			cnt++;
		}
	}

	return cnt;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n, k;
	int lx, ly, rx, ry;
	int cnt = 0;
	cin >> m >> n >> k;

	//initialize
	for (int i = 0; i < k; i++) {
		cin >> lx >> ly >> rx >> ry;

		for (int j = ly; j < ry; j++) {
			for (int t = lx; t < rx; t++) {
				if (field[j][t] == 1) continue;
				field[j][t] = 1;
			}
		}
	}

	//to bfs
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == 1) continue;
			if (visit[i][j]) continue;
			Q.push(make_pair(i, j));
			visit[i][j] = true;
			V.push_back(bfs(m, n));
			cnt++;
		}
	}
	/*result*/
	sort(V.begin(), V.end());
	cout << cnt << "\n";
	for (auto it = V.begin(); it != V.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
