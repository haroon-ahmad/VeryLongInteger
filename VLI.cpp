#include <iostream>
#include "verylongint.h"
#include <string>
using namespace std;
VLI::VLI()//default constructor
{
	integer=nullptr;
	digits=0;
}
VLI::VLI(int *_integer,int _digits)//overloaded constructor
{
	integer=_integer;
	digits=_digits;
}
VLI::~VLI()//destructor
{
	delete[]integer;
}
VLI::VLI(int n)
{
	int temp=n;
	int temp1=n;
	int i=0;
	for( ;temp>9;i++)
	{
		temp=temp/10;
	}
	i++;
	integer=new int [i];
	for(int j=i-1;j>-1;j--)
	{
			integer[j]=temp1%10;
		temp1=temp1/10;	
	}
	digits=i;
}

VLI::VLI(long l)
{
	long temp=l;
	int i;
	for( i=0;temp>9;i++)
	{
		temp=temp/10;
	}
	i++;
	long temp1=l;
	integer=new int [i];
	for(int j=i-1;temp1>9;j--)
	{
		integer[j]=temp1%10;
		temp1=temp1/10;
		
	}
	integer[0]=temp1;
	digits=i;
}
VLI::VLI(long long ll)
{
	long long temp=ll;
	int i;
	for( i=0;temp>9;i++)
	{
		temp=temp/10;
	}
	i++;
	long long temp1=ll;
	integer=new int [i];
	for(int j=i-1;temp1>9;j--)
	{
		integer[j]=temp1%10;
		temp1=temp1/10;
	}
	integer[0]=temp;
	digits=i;
}
VLI::VLI(const VLI& number)//copy constructor
{
	digits=number.digits;
	integer=new int [digits];
	for(int i=0;i<digits;i++)
	{
		integer[i]=number.integer[i];
	}
}
void VLI::setdigits(int _digits)//sets digits
{
	digits=_digits+1;
}
void VLI::setdata(char * str)//sets the size and array
{
		int size=strlen(str);
	digits=size;
	integer=new int[digits];
	for(int i=0;i<digits;i++)
	{
		integer[i]=(str[i]-48);
	}
}
istream& operator>>(istream& in,VLI &number)//overloaded input
{
	char  str[100];
	cout<<"Enter the number";
	in>>str;
	number.setdata(str);

	return in;
}
ostream& operator<<(ostream& out, const VLI& number)//overloaded output
{
	for(int i=0;i<number.digits;i++)
	{
		out<<number.integer[i];
	}
	return out;
}
VLI VLI::operator+( long long ll)//sum operator overloaded
{
	VLI number(ll);
	VLI sum;
	int n;
	int carry=0;
	int x;
	int size;
	int j;//index of sum
	if(digits>number.digits)
	{
		number.refinenumber(digits);//resizing the array
	}
	else if(digits<number.digits)
	{
		this->refinenumber(number.digits);
	}

	size=digits+1;
	sum.digits=digits;
	sum.integer=new int [sum.digits+1];
	for(int i=0;i<sum.digits;i++)
	{
		sum.integer[i]=0;
	}
	 j=sum.digits;
	for(int i=digits-1;i>0;i--,j--)
	{

	    x=integer[i]+number.integer[i]+carry;
		carry=x/10;//taking carry
		n=x%10;
		sum.integer[j]=n;
	}
	x=integer[0]+number.integer[0]+carry;
	n=x%10;
	sum.integer[j]=n;
	carry=x/10;
	sum.integer[j-1]=carry;
	sum.setdigits(digits);
	return sum;
}

VLI VLI::operator+( VLI number)//sum operator overloaded
{
	VLI sum;
	int n;
	int carry=0;
	int x;
	int size;
	int j;//index of sum
	if(digits>number.digits)
	{
		number.refinenumber(digits);//resizing the array
	}
	else if(digits<number.digits)
	{
		this->refinenumber(number.digits);
	}

	size=digits+1;
	sum.digits=digits;
	sum.integer=new int [sum.digits+1];
	for(int i=0;i<sum.digits;i++)
	{
		sum.integer[i]=0;
	}
	 j=sum.digits;
	for(int i=digits-1;i>0;i--,j--)
	{

	    x=integer[i]+number.integer[i]+carry;
		carry=x/10;//taking carry
		n=x%10;
		sum.integer[j]=n;
	}
	x=integer[0]+number.integer[0]+carry;
	n=x%10;
	sum.integer[j]=n;
	carry=x/10;
	sum.integer[j-1]=carry;
	sum.setdigits(digits);
	return sum;
}
VLI VLI::refinenumber(int size)//resizing the array to required size
{

	int *temp=new int [digits];
	for(int i=0;i<digits;i++)
	{
		temp[i]=integer[i];
	}
	delete[]integer;
	integer=new int[size];
	for(int i=0;i<size;i++)
	{
		integer[i]=0;
	}
	for(int i=digits-1,j=size-1;i>-1;i--,j--)
	{
		integer[j]=temp[i];
	}
	this->setdigits((size-1));
	return (*this);
}
VLI& VLI::operator=(const VLI& number)//equal to operator over loaded
{
	 if (this==&number) 
		return *this;
	 else
	 {
		digits=number.digits;
		integer=new int [digits];
		 for(int i=0;i<digits;i++)
		 {
			 integer[i]=number.integer[i];
		 }
		 return *this;
	 }
}
VLI VLI::operator*(VLI number)
{
	VLI product;
	int *temp;
	temp=new int [digits+1];
	for(int i=0;i<digits+1;i++)
	{
		temp[i]=0;
	}
	int x=0;
	int carry=0;
	int n=0;
	product.digits=digits+number.digits;
	product.integer=new int [product.digits+1];
	for(int i=0;i<(product.digits+1);i++)
	{
		product.integer[i]=0;
	}
	int **multipication;
	int rows=number.digits;
	int columns=number.digits+digits;
	multipication=new int *[rows];
	for(int i=0;i<rows;i++)
	{
		multipication[i]=new int[columns];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			multipication[i][j]=0;
		}
	}
	int l;
	int size=columns;
	for(int i=number.digits-1;i>-1;i--)
	{
		carry=0;
		for(int j=digits-1,k=digits;j>-1;j--,k--)
		{
			x=integer[i]*number.integer[j]+carry;
            carry=x/10;
			n=x%10;
			temp[k]=n;
		}
		l=0;
		for(int m=size-1,n=digits;n>-1;m--,n--)
			multipication[l][m]=temp[n];
		l++;
		size--;
	}
	int sum=0;
	int carry1=0;
	int k;
	int y=product.digits;
	for( k=number.digits;k>0;k--,y--)
	{
		sum=0;
		for(int l=rows-1;l>-1;l--)
		{
			sum=sum+multipication[l][k]+carry1;
		     carry1=0;
		}
		carry1=sum/10;
		sum=sum%10;
		product.integer[y]=sum;
	}
	for(int l=rows-1;l>-1;l--)
	{
		sum=sum+multipication[l][0];
	}
	carry1=sum/10;
	sum=sum%10;
	product.integer[y]=sum;
	product.integer[y-1]=carry1;
	return product;

}int* resize(int* Array,int size )//resizes array
{
	int *temp;
	size=size+3;
	temp=new int [size];
	for(int i=0;i<size;i++)
	{
		temp[i]=0;
	}
	 for(int j=0;j<size-3;j++)
	 {
		 Array[j]=temp[j];
	 }
	 return Array;
}
VLI VLI::operator-(VLI number)//subtraction overloaded
{
	if(digits>number.digits)
	{
		number.refinenumber(digits);//resizing the array
	}
	else if(digits<number.digits)
	{
		this->refinenumber(number.digits);
	}
	VLI difference;
	difference.digits=digits;
	difference.integer=new int[difference.digits+1];
	int borrow;
	int x;
	int n;
	for(int i=digits;i>0;i--)
	{
		if(integer[i]>=number.integer[i])
		{
			difference.integer[i]=integer[i]-number.integer[i];
		}
		else
		{
			difference.integer[i]=(integer[i]+10)-number.integer[i];
		     integer[i-1]=integer[i-1]-1;
		}
		
	}
		difference.integer[0]=integer[0]-number.integer[0];
	return difference;
}
bool VLI :: operator <= (const VLI &number)
{
	bool check = false;
	if(digits<number.digits)
		return true;
	else if(digits>number.digits)
		return false;
	else{	
		for(int i=0; i<digits; i++)
		{
			if(integer[i]<=number.integer[i]){
				check = true;
				break;
			}
		}

	}
	if(check==true)
		return true;
}
bool VLI :: operator >= (const VLI &number)
{
	bool check = false;
	if(digits>number.digits)
		return true;
	else if(digits<number.digits)
		return false;
	else{	
		for(int i=0; i<digits; i++)
		{
			if(integer[i]>=number.integer[i]){
				check = true;
				break;
			}
		}

	}
	if(check==true)
		return true;
}
bool VLI :: operator != (const VLI &number)
{
	bool check = false;
	if(digits>number.digits)
		return true;
	else if(digits<number.digits)
		return true;
	else{	
		for(int i=0; i<digits; i++)
		{
			if(integer[i]!=number.integer[i]){
				return true;
			}
		}
		return false;

	}
	if(check==true)
		return false;
}
bool VLI :: operator > (const VLI &number)
{
	bool check = false;
	if(digits>number.digits)
		return true;
	else if(digits<number.digits)
		return false;
	else{	
		for(int i=0; i<digits; i++)
		{
			if(integer[i]>number.integer[i]){
				check = true;
				break;
			}
		}

	}
	if(check==true)
		return true;
}
bool VLI :: operator == (const VLI &number)
{
	bool check = false;
	if(digits>number.digits)
		return false;
	else if(digits<number.digits)
		return false;
	else{	
		for(int i=0; i<digits; i++)
		{
			if(integer[i]==number.integer[i]){
				continue;
			}
			return false;
		}
		return true;

	}
	if(check==true)
		return true;
}
bool VLI :: operator < (const VLI &number)
{
	bool check = false;
	if(digits<number.digits)
		return true;
	else if(digits>number.digits)
		return false;
	else{	
		for(int i=0; i<digits; i++)
		{
			if(integer[i]<number.integer[i]){
				check = true;
				break;
			}
		}

	}
	if(check==true)
		return true;
}