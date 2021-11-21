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
void housing (int *arr, int n, int k)
{
	int i = 0;
	int j = 0;
	int window_sum = 0;

	while (i < n or j < n)
	{

		//window expansion
		if (window_sum < k)
		{
			window_sum += arr[j];
			j++;
		}
		// window contraction
		if (window_sum > k)
		{
			window_sum -= arr[i];
			i++;
		}
		// when window contains subarray with sum k
		if (window_sum == k and i < j)
		{
			cout << i << " " << j - 1 << endl;
			window_sum += arr[j];
			j++;
		}
	}

}
void housingPrateek(int *arr, int n, int k)
{
	int i = 0;
	int j = 0;
	int cs = 0;

	while (j < n)
	{
		// Keep expanding the window
		cs += arr[j];
		j++;

		// remove elements until cs>k and i<j
		while (cs > k and i < j)
		{
			cs -= arr[i];
			i++;
		}
		// check if cs is equal to k
		if (cs == k)
		{
			// print that window
			cout << i << " " << j - 1 << endl;
		}
	}
	return;
}
void housingNegative(int *arr, int n, int k)
{
	unordered_map<int, int> PsFreq; // PS-Freq mapping
	vector<int> Ps(n, INT_MIN); // This vector (Prefix Sum till any index) is needed if we want to print indices also
	PsFreq[0] = 1; // Initial prefix sum is always 0
	vector<pair<int, int>> index;
	int count = 0;
	int sum = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
		Ps[i] = sum;
		int need = sum - k;
		count += PsFreq[need];
		if (PsFreq[need] != 0)
		{
			int j = PsFreq[need];
			auto beg = Ps.begin();
			while (j--)
			{
				auto found = std::find(beg, Ps.end(), need);
				auto start = found - Ps.begin();
				start++;
				if (found == Ps.end())
					start = 0;
				index.push_back({start, i});
				found++;
				beg = found;
			}
		}
		PsFreq[sum]++;
	}

	cout << "Count: " << count << endl;
	for (auto x : index)
	{
		cout << "[" << x.first << ", " << x.second << "]" << endl;
	}

}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
	int negplots[] = {1, -3, -2, 1, 4, -1, 3, -2, 1, 1};
	int n = sizeof(plots) / sizeof(int);
	int k = 8;
	int kn = 3;
	//housing(plots, n, k);
	//cout << "---------------" << endl;
	//housingPrateek(plots, n, k);
	housingNegative(negplots, n, kn);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
