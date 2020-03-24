#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
long long merge(int arr[],int start,int mid,int end)
{
	int i=start,j=mid,k=0;
	int temp[(end-start)+1];
	long long count=0;
	while(i<mid &&j<=end)
	{
		if (arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}else{
			count+=mid-i;

			temp[k++]=arr[j++];

		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end){
		temp[k++]=arr[j++];
	}

	for (int i = start, k=0; i <= end; ++i,++k)
	{
		arr[i]=temp[k];
	}
	return count;
}
int merge_sort(int arr[], int start, int end) 
{ 
    int count=0;
	if (end>start)
	{
		int mid=(start+end)/2;
        
		count+=merge_sort(arr,start,mid);
		count+=merge_sort(arr,mid+1,end);
		count+=merge(arr,start,mid+1,end);

	}
	return count;
} 
long long solve(int A[], int n)
{
	long long ans=merge_sort(A,0,n-1);
	return ans;
}
int main()
{
	int a[]={3,7,5,4,8,6,2,1};
	cout<<solve(a,8);
	return 0;
}