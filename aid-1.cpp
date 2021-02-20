#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>

class AlphaNumericPredicate {
public:
bool operator() (char c)
{
    return (isalnum(c));
}
};

template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator filter(InputIterator first, InputIterator last,
                      OutputIterator result,
                      UnaryPredicate predicate, int history_size)
{

	int cur_pos = 0;
	
	std::map<char, int> store;
    while (first!=last) {
        if(predicate(*first)){
			auto it = store.find(*first);
			if (it == store.end()) {
					store.insert(std::make_pair(*first, cur_pos));
					*result++ = *first++;
			} else {
				auto prev_pos = it->second;
				if (cur_pos - prev_pos > history_size) {
					it->second = cur_pos;
					*result++ = *first++;
				} else {
					first++;
				}
			}
        }
        else {
            *first++;
		}
		cur_pos++;
    }
    return result;
}


std::string filter_string(std::string source, int history_size)
{
	source.erase(filter(std::begin(source), std::end(source),
                        std::begin(source),
                        AlphaNumericPredicate{}, history_size),
                 std::end(source));

    return source;
}


int main()
{
		int history_size = 1;
    while (!std::cin.eof())
    {
        std::string source;
        std::getline(std::cin, source);
        std::cout << filter_string(source, history_size) << std::endl;
    }
    return 0;
}

