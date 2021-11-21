#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){

	unordered_map<int,int> SumFreq;
	SumFreq[0]=1;
	long sum=0;
	int ans=0;	
	sum=0;
    if(arr.size()==1)
    {
        ans = (k==arr[0])?1:0;
        return ans;
    }
        
	for(int i=0;i<arr.size();i++)
	{
		sum+=arr[i];
	    int need = sum-k;
       if(SumFreq.count(need)>0)
            ans+=SumFreq[need]; 
		SumFreq[sum]+=1;
	}
	//for(auto x:SumFreq)
	//	cout<<x.first<<": "<<x.second<<"\n";
	return ans;
	
}
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main()
{
	file_i_o();
	vector<int> arr{3,-1,2,9,-4,5,6,7,1,10};
	vector<int> a{1,2,3};
	cout<<cntSubarrays(a,3);
	return 0;
}