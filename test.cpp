#include<iostream>
#include<string>
#include"bloomfilter.h"
using namespace std;
void main() {
	string s1 = "dabcdgd";
	string s2 = "dabcdd";
	bloomfilter b1;
	b1.insert(s1);
	cout << b1.check(s1)<<endl<<b1.check(s2)<<endl;
	getchar();
}