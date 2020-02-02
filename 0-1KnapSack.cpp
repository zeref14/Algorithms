#include <iostream>
using namespace std;

int knapsack(int n,int w[],int p[],int W);
int main(int argc, char const *argv[])
{
	int n,W;
	cin>>n; //Number of weigths
	

	int *w=new int[n]; //Array of weigths in sorted order
	int *p=new int[n];//Array of price

	for(int i=0;i<n;i++)
		cin>>p[i];
	for(int i=0;i<n;i++)
		cin>>w[i];

	cin>>W;// Max capacity of Knapsack
	

	cout<<knapsack(n,w,p,W)<<endl;

	return 0;
}


int knapsack(int n,int w[],int p[],int W)
{
	int T[n+1][W+1];

	for(int i=0;i<=n;i++)
		T[i][0]=0;

	for(int i=0;i<=W;i++)
		T[0][i]=0;
	

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(j<w[i])
			{
				T[i][j]=T[i-1][j-1];

			}
			else
			{
				T[i][j]=max(T[i-1][j-1],p[i]+T[i-1][j-w[i]]);
			}
		}
	}

	int i=n,j=W;
	while(1)
	{
		
		if(i==0 || j==0)
			break;

		if(T[i][j]==T[i-1][j])
		{
			i=i-1;
			j=j-1;
		}
		else
		{
			cout<<p[i]<<" ";
			i=i-1;
			j=j-w[i];

		}
	}

	cout<<endl;

	return T[n][W];
}