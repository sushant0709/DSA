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

node* buildTree(){

	int d;
	cin>>d;

	if(d == -1){
		// node is null (no node exists)
		return NULL;
	}
	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}
// recursive approach
int max_level = 0;
void leftViewUtil(vector<int>& vec, node* root, int level)
{
    // base case
    if (root == NULL)
        return;
 
    // If this is the first node of its level
    if (max_level < level) {
        vec.push_back(root->data);
        max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(vec, root->left, level + 1);
    leftViewUtil(vec, root->right, level + 1);
}
// iterative approach using q
void printLeftView(node* root,vector<int> &ans){

	queue<node*> q;

	// push the root
	q.push(root);

	// push null as we've completed one level by pushing the root
	q.push(NULL);
	// print root as it will always come in left view
    ans.push_back(root->data);
	node* n;
	while(!q.empty()){
		n = q.front();
		if(n != NULL){
			if(n->left!=NULL)
				q.push(n->left);
			if(n->right!=NULL)
				q.push(n->right);
			// pop current node
			q.pop();
		}
		else{
			// if we have NULL as current node,we add another NULL because all children of
			// present level has been added, so we push another NULL at end
			
			if(q.size()>1)  // if we have last NULL we don't push to break the while loop
				q.push(NULL);
			// pop current node
				q.pop();
			// print the immediate node in q just after popping NULL, also check that q is not empty(check necessary for last node of last level)
			if(!q.empty())
				ans.push_back(q.front()->data);
		}	
	}	
}
vector<int> leftView(node* root){
	vector<int> ans;
	printLeftView(root,ans);
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
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    vector<int> ans;
    ans = leftView(root);
    for(auto x:ans){
    	cout<<x<<" ";
    }
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}