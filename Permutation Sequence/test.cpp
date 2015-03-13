#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 9;
	string res;
	for (int i = 1; i <= n; i++)
	{
		res += char(i + '0');
	}
	cout<<res<<endl;
}