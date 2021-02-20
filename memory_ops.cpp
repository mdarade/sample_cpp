#include <iostream>
#include <string.h>
using namespace std;
int main() {
	char *p="mahaveer1111111111111111111111111111111111111";
	void *x=p;
	char b[20]={'\0'};
	::strcpy(b, (char*)x);
	cout << b;
	return 0;
}
