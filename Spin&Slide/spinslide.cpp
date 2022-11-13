#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int t, n, m; 
// t는 테스트 케이스 개수
// n은 격자 판 크기 nxn
// m은 spinslide의 횟수

char origin[101][101];
char spinslide[101][101];

void spin(int n) {
	for (int i = 0; i < n; i++) { // spin 구간 
		for (int j = 0; j < n; j++) {
			spinslide[i][n - 1 - j] = origin[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			origin[i][j] = spinslide[i][j]; // spin을 한 값을 spinslide 배열에 넣기
		}
	}
}

void slide(int n) {
	for (int i = n - 1; i > 0; i--) { 
		for (int j = 0; j < n; j++) { 
			if (origin[i][j] == '.') {
				for (int k = i - 1; k >= 0; k--) {
					if (origin[k][j] != '.') {
						origin[i][j] = origin[k][j];
						origin[k][j] = '.';
						break;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

	freopen("spinslide.inp", "r", stdin);
	freopen("spinslide.out", "w", stdout);

	cin >> t;
	
	int start = 0;

	while (true) {
		start++;
		if (start == t+1) break;

		cout << "Case #" << start << ": \n";

		cin >> n >> m; 
		for (int i = 0; i < n; i++) {	
			for (int j = 0; j < n; j++) {
				cin >> origin[i][j];
			}
		} 

		for (int i = 0; i < m; i++) {
			spin(n);
			slide(n);
		} 

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << origin[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
}