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
class node{
	public:
		int data;
		node* left;
		node* right;

		node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};
void print_at_level_k(node* root,int k,vector<int> &ans){

	// edge case
	if(root == NULL){
		return;
	}
	// base case
	if(k == 0){
		ans.push_back(root->data);
		return;
	}
	//recursive case
	print_at_level_k(root->left,k-1,ans);
	print_at_level_k(root->right,k-1,ans);
	return;
}
// this function returns the distance of target node from itself(root)
int printNodesatDistanceK_helper(node* root,node* target,int k,vector<int> &ans){

	// base case
	if(root == NULL){
		// if we've reached NULL and we couldn't find target, we'll return -1 
		return -1;
	}
	if(root == target){
		// print all nodes from target at level k (descendents path)
		print_at_level_k(root,k,ans);
		return 0;
	}
	// recursive case
	int lcDistance = printNodesatDistanceK_helper(root->left,target,k,ans);
	if(lcDistance != -1){
		// tagert node is in left subtree of curr. node

		// 2 cases
		// print the current node
		if(lcDistance + 1 == k){
			ans.push_back(root->data);
		}
		// print node in right subtree
		else{
			print_at_level_k(root->right,k-lcDistance-2,ans);
		}
		return 1+lcDistance;
	}
	int rcDistance = printNodesatDistanceK_helper(root->right,target,k,ans);
	if(rcDistance != -1){
		// tagert node is in right subtree of curr. node

		// 2 cases
		// print the current node
		if(rcDistance + 1 == k){
			ans.push_back(root->data);
		}
		// print node in left subtree
		else{
			print_at_level_k(root->left,k-rcDistance-2,ans);
		}
		return 1+rcDistance;
	}
	// we have't found target node
	return -1;	
}
vector<int> nodesAtDistanceK(node *root, node *target, int k){
    //return a SORTED vector of the nodes
    vector<int> ans;
    printNodesatDistanceK_helper(root,target,k,ans);
    sort(ans.begin(),ans.end());
    return ans;    
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right->left = new node(9);
	root->left->right->right->right = new node(10);

	vector<int> ans = nodesAtDistanceK(root,root->left->right,2);
	for(auto x:ans){
		cout<<x<<" ";
	}
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}