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
bool isSafe(int mat[][9],int i,int j,int no,int n){

	// row and column check
	for(int k=0;k<n;k++){
		if(mat[i][k] == no || mat[k][j] == no){
			return false;
		}
	}

	// subgrid check
	int root_n = sqrt(n);
	// starting x and y of subgrid to which i and j belong
	int sx = (i/root_n)*root_n;
	int sy = (j/root_n)*root_n;

	for(int x=sx;x<sx+root_n;x++){
		for(int y=sy;y<sy+root_n;y++){
			if(mat[x][y] == no){
				return false;
			}
		}
	}
	return true;
}
bool solveSudoku(int mat[][9],int n,int i,int j){

	// base case
	if(i==n){
		// we've solved all rows
		// print the matrix and return true

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	// recursive cases

	// if we reach end of column
	if(j==n){
		return solveSudoku(mat,n,i+1,0);
	}

	// if no. is already present in question
	if(mat[i][j]!=0){
		return solveSudoku(mat,n,i,j+1);
	}
	
	// we try every no at current cell
	for(int no=1;no<=n;no++)
	{
		if(isSafe(mat,i,j,no,n)){
			// place the no. at current cell and call next cells

			mat[i][j] = no;

			bool subProblem = solveSudoku(mat,n,i,j+1);
			// if remaining sub-problem gives true, then return true to parent call
			// else continue trying remaining nos.
			if(subProblem){
				return true;
			}
		}
	}
	// backtracking --> put 0 at current cell, which was present originally before solving sub-problem
	mat[i][j] = 0;
	return false;
}


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n=9;
	int mat[9][9] =
	{{5,3,0,0,7,0,0,0,0},
	 {6,0,0,1,9,5,0,0,0},
	 {0,9,8,0,0,0,0,6,0},
	 {8,0,0,0,6,0,0,0,3},
	 {4,0,0,8,0,3,0,0,1},
	 {7,0,0,0,2,0,0,0,6},
	 {0,6,0,0,0,0,2,8,0},
	 {0,0,0,4,1,9,0,0,5},
	 {0,0,0,0,8,0,0,7,9}};

	 if(!solveSudoku(mat,n,0,0)){
	 	cout<<"No Solution exists!!!"<<endl;
	 }

	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}