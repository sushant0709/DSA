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
int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> isPresent;
	int i = 0;
	int j = 0;
	int start = 0;
	int maxLength = 0;
	while (j < s.length())
	{
		char ch = s[j];
		if (isPresent.find(ch) == isPresent.end())
		{
			isPresent.insert({ch, j});
			j++;
			continue;
		}
		// to update positions of charcaters already existing in map to their               // new positions
		if (isPresent[ch] < i)
		{
			isPresent[ch] = j;
			j++;
			continue;
		}
		if ((j - i) > maxLength)
		{
			maxLength = j - i;
			start = i;
		}
		int index = (isPresent.find(ch))->second;
		i = index + 1;
		isPresent[ch] = j;
		j++;
	}
	int ans = max(maxLength, j - i);
	cout << s.substr(start, ans) << endl;
	return max(maxLength, j - i);
}
string uniqueSubstringPrateek(string s)
{
	int i = 0, j = 0, window_len = 0, max_len = 0, start = 0;

	unordered_map<char, int> m;

	while (j < s.length())
	{
		char ch = s[j];
		// if current char is already present in window-> update start of window and window_len
		if (m.count(ch) && m[ch] >= i)
		{
			i = m[ch] + 1;
			window_len = j - i;
		}
		// always done-> updating m with position of current char and window_len increment
		m[ch] = j;
		window_len++;
		j++;

		if (window_len > max_len)
		{
			max_len = window_len;
			start = i;
		}
	}
	return s.substr(start, max_len);
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	string s = "abcbcfcadeee";
	string a = "prateekbhaiya";
	cout << lengthOfLongestSubstring(a) << endl;
	cout << uniqueSubstringPrateek(a) << endl;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
