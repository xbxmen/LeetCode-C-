#include <iostream>
using namespace std;

class Student {
 public:
  Student() { cout << "Student" << endl; }

 private:
  string m_strName;
};

int main() {
  Student stu1;
  Student stu2 = stu1;
  Student stu3(stu1);
  return 0;
}
