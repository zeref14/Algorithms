#include<iostream>
#include<string>
using namespace std;

int dlcs(int n,int m,string a,string b);
int main(int argc, char const *argv[])
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int n=a.length();
	int m=b.length();
	cout<<dlcs(n,m,a,b)<<endl;
	return 0;
}

int dlcs(int n,int m,string a,string b)
{
	int T[n+1][m+1];
	int maximum=0;
	int x,y;
	for(int i=0;i<=n;i++)
		T[i][0]=0;
	for(int j=0;j<=m;j++)
		T[0][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			if(a.at(i-1)==b.at(j-1))
			{
				T[i][j]=T[i-1][j-1]+1;
				if(T[i][j]>maximum)
					x=i,y=j;
				maximum=max(maximum,T[i][j]);
			}
			else
				T[i][j]=0;
		}
	}
	for(int i=0;i<maximum;i++)
		cout<<b.at(y-maximum+i);
	cout<<endl;


	return maximum;
}