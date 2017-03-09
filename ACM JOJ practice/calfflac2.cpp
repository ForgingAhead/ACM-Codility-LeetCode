/*
ID:chenfen5
PROB:calfflac
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char lower(char source)
{
	if (source < 'a')
		return source + 'a' - 'A';
	return source;
}

int main(void)
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	char c;
	string s("");
	while (!fin.eof ())
	{
		c = fin.get();
		s += c;
	}
	int max = 0, ms = 0, l, r, me = 0, len = s.length (), all = 0, maxall = 0;
	for (unsigned int i = 0; i < len; ++i)
	{
		if (!isalpha(s[i]))
			continue;
		l = i; r = i;
		int j = 0;
		all = 1;
        while (true)
		{
			++r; --l;
			if ((r >= len) || l < 0)
				break;
			while (!isalpha(s[r]))
			{
				++r;
				if (r >= len)
					break;
			}
			while (!isalpha(s[l]))
			{
				--l;
				if (l < 0)
					break;
			}
			all += 2;
			++j;
			if (r >= len || l < 0)
				break;
			if (lower(s[r]) != lower(s[l]))
				break;
			if (maxall < all)
			{
				max = j;
				ms = l;
				me = r;
				maxall = all;
			}
		}
		l = i; r = i + 1;
		while (!isalpha(s[r]))
		{
			r++;
			if (r >= len)
				break;
		}
		if (r >= len)
				continue;
		if (s[r] != s[l])
			continue;
		j = 0;
		all = 2;
        while (true)
		{
			++r; --l;
			if ((r >= len) || l < 0)
				break;
			while (!isalpha(s[r]))
			{
				++r;
				if (r >= len)
					break;
			}
			while (!isalpha(s[l]))
			{
				--l;
				if (l < 0)
					break;
			}
			all += 2;
			++j;
			if (r >= len || l < 0)
				break;
			if (lower(s[r]) != lower(s[l]))
				break;
			if (maxall < all)
			{
				max = j;
				ms = l;
				me = r;
				maxall = all;
			}
		}
	}
	fout << maxall << endl << s.substr(ms, me - ms + 1) << endl;
	return 0;
}
