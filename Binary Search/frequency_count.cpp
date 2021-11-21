// Problem Link -
/* By Sushant Khattar */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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
int lower_bound(vector<int>&arr,int key){

	int s=0;
	int e=arr.size()-1;
    int lb=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==key){
			lb=mid;
			// again search in left half of array to find lower bound
			e=mid-1;
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return lb;
}
int upper_bound(vector<int>&arr,int key){

	int s=0;
	int e=arr.size()-1;
    int ub=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==key){
			ub=mid;
			// again search in right half of array to find upper bound
			s=mid+1;
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ub;
}
int frequency_count(vector<int>&arr,int key){

	int lb=lower_bound(arr,key);
	int ub=upper_bound(arr,key);
	 
	return ub-lb+1;
}
int frequency_count_stl(vector<int>&arr,int key){
	
	// using STL functions:
	// lower_bound(returns iterator to 1st element >= key)
	// upper_bound(returns iterator to 1st element > key)

	return upper_bound(arr.begin(),arr.end(),key)-lower_bound(arr.begin(),arr.end(),key);
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	vector<int> arr{0,0,0,1,1,1,1,2,2,2,2,2,3,4,4,4};
	cout<<frequency_count(arr,2)<<endl;
	cout<<frequency_count_stl(arr,2);
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}