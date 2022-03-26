#include <iostream>
using namespace std;

// class String {
//  public:
//   //  通用构造函数
//   String(const char* str = NULL);

//   // 拷贝构造函数
//   String(const String& another);

//   // 析构函数
//   ~String();†

//   // 赋值函数
//   String& operator=(const String& str);

//   char* m_char;
// }

// String::String(const char* str) {
//   if (str == NULL) {
//     m_char = new char[1];
//     m_char[0] = '/0';
//   } else {
//   }
// }

int main() {
  char str[12] = {'I', ' ', 'a', 'm', ' ', 'h', 'a', 'p', 'p', 'y'};
  cout << strlen(str);
  cout << sizeof(str);

  const char* str2 = "I love CHINA!1111";
  cout << str2 << endl;
  cout << sizeof(str2) << endl;

  return 0;
}
