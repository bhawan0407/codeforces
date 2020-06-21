#include <iostream>
#include <algorithm>

using namespace std;


bool anotherNumSys(string s)
{
	size_t pos1 = s.find_first_of('R');
	size_t pos2 = s.find_first_of('C');

	if(pos1 != string::npos && pos2 != string::npos)
	{
		for(size_t i = pos1; i <= pos2; i++)
		{
			if(isdigit(s[i]))
			{
				return true;
			}
		}

		return false;
	}

	return false;
}

string convert1(string s)
{
	size_t pos2 = s.find_first_of('C');

	string rowS = s.substr(1, pos2 - 1);

	string colS = s.substr(pos2 + 1);

	int col = atoi(colS.c_str());

	string res = "";

	while(col)
	{
		int r = col % 26;

		col = col/26 - (r == 0);

		if(r == 0)
			r = 26;

		res += ((r - 1) + 'A');
		
	}

	reverse(res.begin(), res.end()); 

	return res + rowS;

}

string convert2(string s)
{
	string rowS;
	int i;

	for(i = 0; i < s.length(); i++)
	{
		if(isdigit(s[i]))
		{
			break;
		}
	}

	rowS = s.substr(i);
	string colS = s.substr(0, i);

	long long res = 0;

	long long tmp = 1;

	for(int j = colS.length() - 1; j >= 0; j--)
	{
		res += (colS[j] - 'A' + 1) * tmp;
		tmp *= 26;
	}

	return 'R' + rowS + 'C' + to_string(res);
}


int main()
{
	int t;

	cin >> t;

	string s;

	while(t--)
	{
		string res;

		cin >> s;

		if(anotherNumSys(s))
		{
			res = convert1(s);
		}
		else
		{
			res = convert2(s);
		}

		cout << res << endl;
	}

	return 0;
}