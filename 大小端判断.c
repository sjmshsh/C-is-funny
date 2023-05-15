#include <iostream>

using namespace std;

int main() {
  union {
    short s;
    char c[sizeof(short)];
  } un;
  un.s = 0x0102; // 这个值的二进制表示为 00000001 00000010 其中高字节为00000001 低字节 00000010
  if (sizeof(short) == 2) {
    if (un.c[0] == 1 && un.c[1] == 2) {
      cout << "big" << endl;
    } else if (un.c[1] == 1 && un.c[0] == 2) {
      cout << "small" << endl;
    } else {
      cout << "unknown" << endl;
    }
  } else {
    cout << "sizeof(short)=" << sizeof(short) << endl;
  }
  return 0;
}
