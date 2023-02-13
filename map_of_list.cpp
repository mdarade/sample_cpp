#include <iostream>
#include <map>
#include <list>

using namespace std;

int main() {
	map<char, list<char>> adj;
	string str = "mahaveer";
	adj[str[0]].push_front(str[1]);

	return 0;
}
