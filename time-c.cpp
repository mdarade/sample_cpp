#include <sys/time.h>
#include <iostream>

using namespace std;

int main() {
char fmt[64];
char buf[64];
struct timeval tv;
struct tm *tm;

gettimeofday (&tv, NULL);
tm = localtime (&tv.tv_sec);
strftime (fmt, sizeof (fmt), "%H:%M:%S:%%06u", tm);
snprintf (buf, sizeof (buf), fmt, tv.tv_usec);
std::cout << buf;
//printf ("%s\n", buf);
return 0;
}


