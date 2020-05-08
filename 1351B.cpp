#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int a,b,c,d;

	while(t--)
	{
		cin >> a >> b;

		int x = max(a, b);
		int y = a + b - x;

		a = x;
		b = y;

		cin >> c >> d;

		x = max(c, d);
		y = c + d - x;

		c = x;
		d = y;

		if((a == c) && (b + d) == a)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}

	return 0;
}