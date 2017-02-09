#pragma once
#include<string>
using namespace std;
class bloomfilter
{
public :
	bloomfilter();
	bloomfilter(int n, float p);
	void insert(string s);
	bool check(string s);
protected:
	size_t BKDRHash(string s1);
	size_t SDBMHash(string s1);
	size_t RSHash(string s1);
	size_t APHash(string s1);
	size_t JSHash(string s1);
private:
	int volume;
	int bitsize;
	char bitArray[1400];
};


