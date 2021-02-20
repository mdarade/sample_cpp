#include <iostream>
#include <string>
#include <sstream>
//#include <boost/algorithm/string.hpp>

using namespace std;

int main() {
	std::string s("[[123,456],[789,012],[345,678]]");
	//s.erase(1,1);
	s.erase(s.size()-1,1);
	cout << s << endl;


      std::string token;
	  const char delimiter=']';
      std::istringstream tokenStream(s);
      while (std::getline(tokenStream, token, delimiter))
      {    
          std::string temp = token;
	      temp.erase(0,1);
		  cout << "temp is: " << temp << endl;
          std::size_t first = temp.find_first_of(",");
          if (first == std::string::npos) {
              return 1;
          }
		    
          std::string strNew = temp.substr(1, first);
          auto start = stol(strNew);
          //std::string start(strNew);
  
          strNew = temp.substr(first + 1, temp.length() - 1);
          auto length = stol(strNew);
          //std::string length(strNew);

		  cout << start << "/" << length << "/" << endl;

	  }

	return 0;

	size_t start_pos = s.find("[");
	size_t end_pos = s.find("]");
	cout << s.substr(start_pos+1,end_pos) << endl;


	return 0;
}

