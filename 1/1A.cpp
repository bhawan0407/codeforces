#include <iostream>

using namespace std;

int main()
{
	long long n,m,a;

	cin >> n >> m >> a;

	long long res;

	res = ((n-1)/a + 1) * ((m-1)/a + 1);


	cout << res << endl;

	return 0;
}