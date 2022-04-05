#include <cstring>
#include <iostream>

using namespace std;

class String {
 public:
  //  通用构造函数
  String(const char* str = NULL);

  // 拷贝构造函数
  String(const String& another);

  // 析构函数
  ~String();

  // 赋值函数
  String& operator=(const String& str);

 private:
  // 用于保存字符串
  char* m_data;
}

// 构造函数
// 1、判断str是否为NULL
String::String(const char* str) {
  if (str == NULL) {
    m_data = new char[1];
    m_data[0] = '/0';
  } else {
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);
  }
}

// 复制构造函数
String::String(const String& another) {
  m_data = new char[strlen(another.m_data) + 1];
  strcpy(m_data, another.m_data);
}

// 赋值函数(操作符重载)
String& String::operator=(const String& another) {
  if (this == &another) {
    return *this;
  }

  delete[] m_data;
  m_data = new char[strlen(another.m_data) + 1];
  strcpy(m_data, another.m_data);
  return *this;
}

// 析构函数
String::~String() {
  delete[] m_data;
  m_data = nullptr;
}

int main() {
  char str[12] = {'I', ' ', 'a', 'm', ' ', 'h', 'a', 'p', 'p', 'y'};
  cout << strlen(str);
  cout << sizeof(str) << endl;

  const char* str2 = "I love CHINA!1111";
  cout << str2 << endl;
  cout << sizeof(str2) << endl;

  return 0;
}
