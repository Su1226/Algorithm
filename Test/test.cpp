#include <iostream>
#include <string>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int n;

map<string, pair<string, string>> people;
map<string, int> family;

int main() {
	ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string num, first, last;
		cin >> num >> first >> last;
		people.insert({ num, pair<string, string>(first, last)});
	}

	for (auto &m : people) {
		cout << m.first << " " << m.second.first << " " << m.second.second << "\n";
		family[m.second.second]++;
	}

	cout << "\n";

	for (auto &ms : family) {
		if (ms.second != 1) {
			cout << ms.first << " " << ms.second << "\n";
		}
	}
}