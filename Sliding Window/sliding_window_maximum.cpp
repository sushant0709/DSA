#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            
            // remove out_of_bound index for current sliding window
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            
            // remove all elements in deque smaller than equal to current element
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
}

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.text", "r", stdin);
	    freopen("output.text", "w", stdout);
	#endif
}

int main()
{
	file_i_o();
    vector<int> arr{3,-1,2,9,-4,5,6,7,1,10};
    vector<int> ans;
    ans=maxSlidingWindow(arr,3);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}