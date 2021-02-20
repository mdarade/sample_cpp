#include <sys/time.h>
#include <iostream>

using namespace std;

std::string get_time_in_microseconds() {
    char fmt[64];
    char buf[64];
    struct timeval tv;
    struct tm *tm;

    gettimeofday (&tv, NULL);
    tm = localtime (&tv.tv_sec);
    strftime (fmt, sizeof (fmt), "%H:%M:%S:%%06u", tm);
    snprintf (buf, sizeof (buf), fmt, tv.tv_usec);
    std::string time(buf);

    return time;
}

int main() {

	cout << get_time_in_microseconds();
	return 0;
}
