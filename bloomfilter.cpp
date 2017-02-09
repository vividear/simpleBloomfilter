#include"bloomfilter.h"
#include<cmath>
#include<iostream>;
using namespace std;
bloomfilter::bloomfilter() {
	volume = 100;
	bitsize = 1400;  //false probility p=1/1000
	//initial bitarray to all zeros
	for (int i = 0; i < bitsize; i++)
		bitArray[i] = '0';
}
//notice: modify the type of bitsize before use this function
bloomfilter::bloomfilter(int n, float p) {  
	volume = n;
	bitsize = (int)(volume*log(1 / p) / 0.48);
	for (int i = 0; i < bitsize; i++)
		bitArray[i] = '0';
}
void bloomfilter::insert(string s) {
	//cout << this->BKDRHash(s) << "  " << this->RSHash(s) << "  " << this->SDBMHash(s) <<"  "<<this->APHash(s)<<"   "<<this->JSHash(s)<< endl;
	bitArray[this->BKDRHash(s)] = '1';
	bitArray[this->RSHash(s)] = '1';
	bitArray[this->SDBMHash(s)] = '1';
	bitArray[this->APHash(s)] = '1';
	bitArray[this->JSHash(s)] = '1';
}
bool bloomfilter::check(string s) {
	if(bitArray[this->BKDRHash(s)] == '1'&&
	bitArray[this->RSHash(s)] == '1'&&
	bitArray[this->SDBMHash(s)] == '1'&&
	bitArray[this->APHash(s)] == '1'&&
	bitArray[this->JSHash(s)] == '1')
	return true;
	else return false;
}
size_t bloomfilter::BKDRHash(string s1)
{
	const char *str = s1.c_str();
	size_t seed = 131;
	size_t hash = 0;
	while (*str != '\0')
	hash = hash*seed + (*str++);
	return (hash & this->bitsize);	
}
size_t bloomfilter::SDBMHash(string s1)
{
	const char *str = s1.c_str();
	register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
			{
			hash = 65599 * hash + ch;
		 	}
		return hash%this->bitsize;
}
size_t bloomfilter::RSHash(string s1)
{
	const char *str = s1.c_str();
	register size_t hash = 0;
	size_t magic = 63689;
	  while (size_t ch = (size_t)*str++)
		   {
		       hash = hash * magic + ch;
		      magic *= 378551;
		    }
	return hash%this->bitsize;
}
size_t bloomfilter::APHash(string s1)
{
	const char *str = s1.c_str();
	register size_t hash = 0;
	size_t ch;
	 	for (long i = 0; ch = (size_t)*str++; i++)
		{
		if ((i & 1) == 0)
				{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
				}
		else
				{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
				}
		 	}
		return hash%this->bitsize;
}
size_t bloomfilter::JSHash(string s1) {
	const char *str = s1.c_str();;
	register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
		hash ^= ((hash << 5) + ch + (hash >> 2));
	 	}
		return hash%this->bitsize;
}

