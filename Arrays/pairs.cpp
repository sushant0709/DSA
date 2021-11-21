#include <bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
vector<int> pairSum(vector<int> arr, int S)
{

	vector<int> ans;
	// We'll store the array element one by one if its compliment is not there in the set
	// Initially, the set is empty
	unordered_set<int> isPresent;

	for (int i = 0; i < arr.size(); i++)
	{
		if (isPresent.find(S - arr[i]) == isPresent.end())
		{
			// If compliment of element not found in set,then insert current element
			isPresent.insert(arr[i]);
		}
		else
		{
			// We found the compliment of the element
			auto itr = std::find(arr.begin(), arr.end(), S - arr[i]);  // This is done if we need the index of the elements of the Pair
			ans.push_back(std::distance(arr.begin(), itr));
			ans.push_back(i);
		}
	}
	return ans;
}
int main() {
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr{10, 5, 2, 3, -6, 9, 11};
	auto ans = pairSum(arr, 4);
	std::copy(ans.begin(),
	          ans.end(),
	          std::ostream_iterator<int>(std::cout, " "));
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}