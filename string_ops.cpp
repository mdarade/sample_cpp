#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <unistd.h>
#include <cstring>

using namespace std;
int main() {


	std::string ss;
	int len = 10;
	//ss.reserve(len);
	ss[5] = 'c';

	return 0;

	//std::string dsid = "5c458ed3-c4eb5a84-cec5-00266cf03524/testvm_rhel_7.6-010";
	std::string dsid = "[Datastore_for_vddk_vm] vddk_vm/vddk_vm_3-000001.vmdk";

	int pos1 = dsid.find_first_of('[');
	int pos2 = dsid.find_first_of(']');
	int pos3 = dsid.find_first_of('/');

	std::string id = dsid.substr(pos1 + 1, pos2 - pos1 - 1);
	std::string vm_name = dsid.substr(pos2 + 2, pos3 - pos2 - 2);
	
	auto dstore = id + "/" + vm_name;
	cout << dstore << std::endl;
	return 0;




	char* st = new char[1024];
	::memset(st, 0, 1024);
	*st= 'a';
	cout << strlen(st) << std::endl;
	return 0;

	long int i = 12;
	string s1="true";
	string s2="True";
	string input="true";
#if 0
	if (std::tolower(input) == std::tolower(s2)) {
		cout << "match";
		cout << "input is:" << input;
	}
#endif
	return 0;



	std::stringstream str;
	str << i;
	cout << str.str();
	return 0;

	std::string b="1:2:3:4:5:6:7";
	std::string str1 = b.substr(8, b.find(":"));
	//cout << str1;
	int64_t num = atoi(str1.c_str());
	cout << num;

	return 0;

	std::string s("mahaveer");
	s.append(1, ':').append("howdy");

	cout << s;
	return 0;
}
