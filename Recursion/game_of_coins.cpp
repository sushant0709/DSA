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
int max_coin_advanced(vector<int> v,int s,int e,int k){

	// base case
	if((e-s+1) == k){
		return accumulate(v.begin()+s,v.begin()+s+k,0);
	}
	//if((e-s+1) == 2*k){
	//	return max(accumulate(v.begin()+s,v.begin()+s+k,0),accumulate(v.begin()+s+k,v.begin()+s+2*k,0));
	//}
	// recursive case

	// option1: user chooses k coins from sth coin
	int op1 = accumulate(v.begin()+s,v.begin()+s+k,0)+min(max_coin_advanced(v,s+k,e-k,k),max_coin_advanced(v,s+2*k,e,k));
	// option2: user chooses k coins eth coin
	int op2 = accumulate(v.begin()+e-k+1,v.begin()+e+1,0)+min(max_coin_advanced(v,s,e-2*k,k),max_coin_advanced(v,s+k,e-k,k));

	return max(op1,op2);

}
// returns the maximum value user can make from sth coin to eth coin (both included)
int max_coin(vector<int> v,int s,int e){

	// base case
	if(s==e || s==(e-1)){
		return max(v[s],v[e]);
	}
	// recursive case

	// option1: user chooses sth coin
	int op1 = v[s]+min(max_coin(v,s+1,e-1),max_coin(v,s+2,e));
	// option2: user chooses eth coin
	int op2 = v[e]+min(max_coin(v,s,e-2),max_coin(v,s+1,e-1));

	return max(op1,op2);
}
int Maxvalue(int n,vector<int> v){
	return max_coin(v,0,n-1);
}
int Maxvalue_advanced(int n,vector<int> v,int k){
	return max_coin_advanced(v,0,n-1,k);
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	vector <int> coins = {5,4,100,3,2,1};
	vector<int> coins_advanced = {10,15,20,9,2,5};
	cout<<Maxvalue(coins.size(),coins)<<endl;
	cout<<Maxvalue_advanced(coins_advanced.size(),coins_advanced,2);
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}