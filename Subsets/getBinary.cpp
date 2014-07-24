#include <iostream>
#include <string>

using namespace std;

string getBinary(int a, int len)
{
  string str = "";
  while (a > 0)
  {
    str = str + char((a % 2) + '0');
    a = a / 2;
  }
  for (int i = 0; i < len - str.size(); i++)
  {
    str = str + '0';
  }
  return str;
}

int main(int argc, char* argv[])
{
  for (int i = 0; i < 8; i++)
  {
    cout<<"number: " << i << " binary: " << getBinary(i, 3) <<endl;
  }
}