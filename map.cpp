#include <iostream>
#include <unordered_map>
#include <memory>
#include <unistd.h>
#include <thread>


using namespace std;
using map_t = std::unordered_map<uint64_t, std::shared_ptr<int>>;

class RpcMsg {
public:

		void fill_map() {
			cout << "map now has " << m_.size() << " elements" << std::endl;
			for (uint64_t i=0; i<10000; i++) {
				m_.emplace(std::make_pair(i, make_shared<int>(i)));	
			}
			cout << "map now has " << m_.size() << " elements" << std::endl;
			cout << "element at 500th index is " << *m_[5000] << std::endl;
		}

		void _print_aborted_msgs(std::shared_ptr<int> msg) {
			cout << "sleeping for 4 seconds in thread " << std::this_thread::get_id()
				<< " containing msg " << *msg << std::endl;
			sleep(4);
			cout << "thread exited for msg " << *msg << std::endl;
		}

		void _handle_aborted_msg(std::shared_ptr<int> msg) {
			auto td = std::thread(&RpcMsg::_print_aborted_msgs, this, msg);
			cout << "created thread " << td.get_id() << std::endl;
			td.detach();
		}
			

		void remove_matching_elements() {
			map_t::iterator it;
			for (it = m_.begin(); it != m_.end();) {
				auto msg = it->second;
				if (it->first%1000==0) {
					cout << "found matching msg" << std::endl;
					m_.erase(it++);
					_handle_aborted_msg(msg);
				} else {
					++it;
				}
			}
			//wait for all  10 threads to exit
			sleep(5);
		}	


	RpcMsg() { m_.reserve(10000); }
	~RpcMsg() {}


private:
	map_t m_;
};


int main(int argc, char* argv[]) {

	RpcMsg obj;
	obj.fill_map();
	obj.remove_matching_elements();

	return 0;
}
