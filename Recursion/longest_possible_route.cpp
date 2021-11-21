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
int findLongestRoute(vector<vector<int>> v,int m,int n,int i,int j,vector<pair<int,int>> &visited){

	// base case
	if(i==m-1 and j==n-1){
		// we've reached (m,n)
		//for(auto x:visited){
		//	cout<<"{"<<x.first<<", "<<x.second<<"}"<<"-> ";
		//}
		//cout<<endl;
		return visited.size();
	}
	if(i<0 or i==m or j<0 or j==n){
		return -1;
	}
	if(v[i][j]==0){
		return -1;
	}
	
	// add current cell to path
	visited.push_back({i,j});

	// coordinates for right,left,down and top
	int x[4] = {0,0,1,-1};
	int y[4] = {1,-1,0,0};
	int ans = -1;
    for(int k=0;k<4;k++){
    	int nx = i+x[k];
    	int ny = j+y[k];

    	if(find(visited.begin(),visited.end(),make_pair(nx,ny))==visited.end()){
    		int rec_ans = findLongestRoute(v,m,n,nx,ny,visited);
    		ans = max(ans,rec_ans);
    	}
    }
    // backtracking --> after all calls from current cell,we need to remove current cell
    // from path so that we can visit it again in some longer path that may exist. 
	visited.pop_back();
  
    return ans;
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	vector<vector<int>> v = {{1,1,1},{1,1,1},{0,0,1}};
	vector<pair<int,int>> path;
	cout<<findLongestRoute(v,3,3,0,0,path);
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}