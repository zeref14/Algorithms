#include<iostream>
using namespace std;

int dms(int n,int a[]);
int main(int argc, char const *argv[])
{
	int n;//Size of the sequence
	cin>>n;
	int *a=new int [n];//The required sequence

	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<dms(n,a)<<endl;

	return 0;
}

int dms(int n,int a[])
{
	int incl=a[0];
	int excl=0;

	
	for(int i=1;i<n;i++)
	{
		int temp=incl;
		incl=max(incl,excl+a[i-1]);
		excl=temp;
	}
	return incl;

}