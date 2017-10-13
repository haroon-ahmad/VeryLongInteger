#include <iostream>
#include "verylongint.h"
using namespace std;
int main()
{
	VLI v1,v2,v3,v4,v5;
	cout<<"Enter first very long integer : \n";
	cin>>v1;
	cout<<"Enter second very long integer : \n";
	cin>>v2;
	cout<<"\n first number: "<<v1<<"\n second number : "<<v2;
	v3=v1+v2;
	v4=v1-v2;
	v5=v1*v2;
	cout<<"\nsum of the two numbers :"<<v3<<"\n difference of the two numbers: "<<v4<<" \n product of the two numbers : "<<v5;
	int a=123;
	long b=45676;
	long long c=3142345436;
	VLI v6(a),v7(b),v8(c);
	cout<<"\nvery long integer with int :"<<v6<<"\n very long integer with long :"<<v7<<"\n Very long integer with long long :"<<v8<<endl;
	if(v1==v2)
	{
		cout<<"equal";
	}
	if(v1<v2)
	{
		cout<<"less";
	}
	if(v1>v2)
	{
		cout<<"greater";
	}
}