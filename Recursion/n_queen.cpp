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

// global variable for count of config.
int count;

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
void printboard(int board[][20],int n)
{

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isPossible(int board[][20],int n,int x,int y)
{

	// check for current column
	for(int k=0;k<x;k++){
		if(board[k][y])
			return false;
	}

	// check for left diagonal
	int i=x;
	int j=y;
	while(i>=0 and j>=0){
		if(board[i][j])
			return false;
		i--;
		j--;
	}

	// check for right diagonal
	i = x;
	j = y;
	while(i>=0 and j<n){
		if(board[i][j])
			return false;
		i--;
		j++;
	}
	return true;
}
void solve(int n, int board[][20],int i,vector<int>upperColumn,vector<int>leftDiagonal,vector<int>rightDiagonal)
{
	//base case
	if(i == n)
	{
		// we've reached end of the board
		printboard(board,n);
		::count++;
		return;
	}

	// recursive case
	// try to place queen in each column of row i until we get true signal
	for(int j=0;j<n;j++){
		//if(isPossible(board,n,i,j)){
		if(upperColumn[j]== 0 && leftDiagonal[n-1+j-i] == 0 && rightDiagonal[i+j] == 0){

			// place the queen at current pos and mark the corresponding locations in the hash arrays
   			board[i][j] = 1;
   			upperColumn[j] = 1;
   			leftDiagonal[n-1+j-i] = 1;
   			rightDiagonal[i+j] = 1;
   			// check for all cases/config. using recursion
   			solve(n,board,i+1,upperColumn,leftDiagonal,rightDiagonal);
			
			// backtracking step -> remove the queen from current pos and hash arrays and then again try for new config.
			board[i][j] = 0;
			upperColumn[j] = 0;
   			leftDiagonal[n-1+j-i] = 0;
   			rightDiagonal[i+j] = 0;
		}
		
	}
	// return to parent call once all columns are tried for row i
	return;
}

int count_all_config_n_queen(int n)
{
	::count = 0;
	int board[20][20] = {0};
	vector<int> upperColumn(n,0),leftDiagonal(2*n-1,0),rightDiagonal(2*n-1,0);	
	solve(n,board,0,upperColumn,leftDiagonal,rightDiagonal);
	return ::count;

}

bool print_one_config_n_queen(int n, int board[][20],int i)
{

	//base case
	if(i == n)
	{
		// we've reached end of the board
		printboard(board,n);
		return true;
	}

	// recursive case
	// try to place queen in each column of row i until we get true signal
	for(int j=0;j<n;j++){
		if(isPossible(board,n,i,j)){
			// place the queen at current pos
   			board[i][j] = 1;
   			bool success = print_one_config_n_queen(n,board,i+1);
			if(success){

				// return true to parent call;
				return true;
			}
			// backtracking step -> remove the queen from current pos
			board[i][j] = 0;
		}
		
	}

	// return false to parent call
	return false;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int board[20][20] = {{0}};
	//cout<<print_one_config_n_queen(4,board,0);
	cout<< count_all_config_n_queen(8);
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}