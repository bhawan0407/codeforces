#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string s;

	unordered_map<char, pair<int, int>> mp;

	mp['N'] = make_pair(0, 1);
	mp['S'] = make_pair(0, -1);
	mp['E'] = make_pair(1, 0);
	mp['W'] = make_pair(-1, 0);

	while(t--)
	{
		set <pair< pair<int, int>,  pair<int, int> > > st;
		int currx = 0;
		int curry = 0;
		int newx;
		int newy = 0;

		int cost = 0;

		cin >> s;

		for(auto c: s)
		{
			newx = currx + mp[c].first;
			newy = curry + mp[c].second;	

			if(st.find({{newx, newy}, {currx, curry}}) == st.end())
			{
				cost += 5;
				st.insert({{newx, newy}, {currx, curry}});
				st.insert({{currx, curry}, {newx, newy}});
			}
			else
			{
				cost += 1;
			}

			currx = newx;
			curry = newy;
		}

		cout << cost << endl;
	}

	return 0;
}