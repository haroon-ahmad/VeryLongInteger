#ifndef VERYLONGINTEGER_H
#define VERYLONGINTEGER_H
#include <iostream>
using namespace std;
class VLI
{
private:
int *integer;
int digits;
public:
	VLI();
	VLI(int* integers,int digits);
	~VLI();
	VLI(int n);
	VLI(long l);
	VLI(long long ll);
	VLI(const VLI& integer);
	void setdigits(int _digits);
	VLI refinenumber(int size);
	VLI operator+( VLI number);
	VLI operator+(int n);
	VLI operator+(long l);
	VLI operator+(long long ll);
	VLI operator-(VLI number);
	VLI operator*(VLI number);
	VLI& operator=(const VLI& number);
	void setdata(char * _number);
	bool operator <(const VLI &number);
	bool operator <=(const VLI &number);
	bool operator >(const VLI &number);
	bool operator >=(const VLI &number);
	bool operator == (const VLI &number);
	bool operator != (const VLI &number);
	friend istream& operator>>(istream& in,VLI &number);
	friend ostream& operator<<(ostream & out, const VLI& number);
};
#endif