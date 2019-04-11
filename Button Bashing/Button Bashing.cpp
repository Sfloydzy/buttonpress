
#include "pch.h"
#include <bits/stdc++.h>
#define HOUR 3601
#define INF 1e9
using namespace std;
typedef queue<int> q;
typedef vector<int> v;
int ck_time;

void printShort(v shortest) {
	for (int j = ck_time; j < HOUR; ++j) {
		if (shortest[j] != INF) {
			cout << shortest[j] << " " << HOUR - j << endl;
			break;
		}
	}
}


void bfs(int s, v btns, v &visited, v &shortest) {
	cout << "bfs "<< endl;
	q btn_press;
	visited[s] = 1; //source timing is zero
	shortest[s] = 0;
	btn_press.push(s);
	int n = s; // 0 is the beginning
	while (!btn_press.empty()) {
		int sum = btn_press.front(); btn_press.pop(); //current time of the queue
		for (auto &i : btns) {
			n = sum + i;
			if (n < 0) n = 0;
			else if (n > HOUR - 1) n = HOUR - 1; //if exceeded return bac to max time i.e 3600

			if (visited[n] != 1) {	//if next button press results in time that hasn't been done before push into queue
				btn_press.push(n);
				visited[n] = 1;
				shortest[n] = shortest[sum] + 1;
			}
		}
	}
	cout << " printshort" << endl;
	printShort(shortest);

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	while (n--) {
		v btns;
		int b;
		cin >> b >> ck_time;
		while (b--) {
			int bn; cin >> bn;
			btns.push_back(bn);
		}
		v visited;
		visited.assign(HOUR, 0);
		v shortest;
		shortest.assign(HOUR, INF);
		bfs(0, btns, visited, shortest);
	}
	return 0;
}


/*
Input
On the first line one positive number: the number of test cases, at most 100. After that per test case:
one line with two space-separated integers n and t (1≤n≤16 and 0≤t≤3600): the number of buttons available to change the cooking time, and the desired cooking time in seconds, respectively.
one line with n space-separated integers bi (−3600≤bi≤3600): the number of seconds added to the cooking time when button i is pressed.

Output
Per test case:

one line with two space-separated integers: the minimum number of button presses required to reach the required cooking time,
and the minimum number of extra seconds that the microwave must be running for, respectively.

Input
2
3 50
-10 10 60
1 50
20
Output
2 0
3 10
*/