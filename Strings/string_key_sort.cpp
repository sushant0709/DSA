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
string extractKeyfromString(string str, int key)
{
	char *token = strtok((char*)str.c_str(), " ");

	while (key > 1)
	{
		token = strtok(NULL, " ");
		key--;
	}
	return (string)token;
}
int stringToNum(string s)
{
	int ans = 0;
	int power = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		ans += (s.at(i) - '0') * power;
		power *= 10;
	}
	return ans;
}
bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
	return stringToNum(s1.second) < stringToNum(s2.second);
}
bool lexoCompare(pair<string, string> s1, pair<string, string> s2)
{
	return s1.second < s2.second;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	cin >> n;
	cin.get();  // to ignore'\n'
	vector<string> v;
	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);  // includes white spaces
		v.push_back(s);
	}
	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	vector<pair<string, string>> vp;

	// 1. Extract keys for the string and store it in the vector of pairs
	for (int i = 0; i < n; i++)
	{
		vp.push_back({v[i], extractKeyfromString(v[i], key)});
	}

	// 2. Sorting
	if (ordering == "numeric")
	{
		sort(vp.begin(), vp.end(), numericCompare);
	}
	else
	{
		sort(vp.begin(), vp.end(), lexoCompare);
	}

	// 3. Reversal
	if (reversal == "true")
	{
		reverse(vp.begin(), vp.end());
	}

	// 4. Output
	for (int i = 0; i < n; i++)
	{
		cout << vp[i].first << endl;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
