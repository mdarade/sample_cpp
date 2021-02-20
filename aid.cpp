#include <iostream>
#include <string>
#include <vector>
#include <iterator>

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
                      UnaryPredicate predicate)
{
    while (first!=last) {
        if(predicate(*first)){
            *result++ = *first++;
        }
        else
            *first++;
    }
    return result;
}


std::string filter_string(std::string source)
{
	source.erase(filter(std::begin(source), std::end(source),
                        std::begin(source),
                        AlphaNumericPredicate{}),
                 std::end(source));

    return source;
}


int main()
{
    while (!std::cin.eof())
    {
        std::string source;
        std::getline(std::cin, source);
        std::cout << filter_string(source) << std::endl;
    }
    return 0;
}

