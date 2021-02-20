#include <fstream>
#include <iostream>


using namespace std;


int main() {
	size_t size = 16 * 1024 * 1024;
	const char* bitmap = "00100010101010010101010101010110010101100101101001101010010101101001101001010110";
	std::string os_path("/home/md/1_1_10.bt");



	
	std::ifstream fs(os_path, ios::in);
	if (fs.good())
		cout << "file exists" << std::endl;
	else 
		cout << "file doesn't exists" << std::endl;

	return 0;


//dump bitmap into file
std::ofstream ofs;
ofs.open(os_path);
ofs << bitmap;
ofs.close();

	

	//read bitmap from file into string
std::ifstream ifs(os_path, ios::in);
std::string bt;
ifs >> bt; 
cout << bt << endl;
cout << bt.size() << endl;
ifs.close();


	return 0;
}
