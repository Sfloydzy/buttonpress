/*
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;



void bfs(int s, vi &button, vi &visited, vi &shortestd) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	shortestd[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto &v : button) {
			int n = v + u;
			if (n > 3600) {
				n = 3600;
			}
			else if (n < 0) {
				n = 0;
			}

			if (!visited[n]) {
				visited[n] = 1;
				q.push(n);
				shortestd[n] = shortestd[u] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int cases; cin >> cases;
	while (cases--) {

		vi button;
		vi visited;
		vi shortestd;
		int n; cin >> n;
		int t; cin >> t;

		button.assign(n, 0);
		while (n--) {
			int a; cin >> a;

			button.push_back(a);
		}

		visited.assign(3601, 0);
		shortestd.assign(3601, INT_MAX);
		bfs(0, button, visited, shortestd);
		for (int i = t; i < 3601; i++) {
			if (shortestd[i] != INT_MAX) {
				cout << shortestd[i] << " " << i - t << endl;
				break;
			}
		}
	}
	return 0;
}
*/