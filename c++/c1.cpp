#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	unsigned int num0;
	float num1 = -118.625;
	memcpy(&num0, &num1, sizeof(num1));

	cout << num0 << endl;
	cout << num1 << endl;
}

