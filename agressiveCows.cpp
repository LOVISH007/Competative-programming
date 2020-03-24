#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
bool isPossible(int gapReq,ll stallPosition[],int size,int noOfCows)
{
	int count=1;
	int prevStallPosition=0;
	for (int i = 1; i < size; ++i)
	{
		if ((stallPosition[i]-stallPosition[prevStallPosition])>=gapReq)
		{
			prevStallPosition=i;
			count++;
		}
	}
	if (count>=noOfCows)
	{
		return true;
	}else{
		return false;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;//no. of stalls
		int c;//number of cows
		cin>>n;
		cin>>c;
		ll stallPosition[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>stallPosition[i];
		}
		sort(stallPosition,stallPosition+n);
		int front=stallPosition[0];
		int end=stallPosition[n-1]-stallPosition[0];
		int mid,ans;
		while(front<=end)
		{
			mid=front+(end-front)/2;
			if (isPossible(mid,stallPosition,n,c))
			{
				ans=mid;
				front=mid+1;
			}else{
				end=mid-1;
			}
		}
		cout<<ans;
	}
	return 0;
}

