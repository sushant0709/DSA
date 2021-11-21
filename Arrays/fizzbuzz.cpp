#include <bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
vector<string> fizzbuzz(int n);
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr = {2, 3, 4, 10, 15};

	// Vector Basics
	cout << arr.size() << endl;
	cout << arr.capacity() << endl;
	arr.push_back(15);
	cout << arr.capacity() << endl;

	// String Basics
	string s = "Sushant";
	cout << s.size() << endl;
	cout << s.length() << endl;

	//FizzBuzz Problem
	vector<string> result = fizzbuzz(15);

	//Way to print vector using copy function and cout
	std::copy(  result.begin(),
	            result.end(),
	            std::ostream_iterator<string>(std::cout, ", "));
	cout << endl;
	for (string s : result)
	{
		cout << s << " ";
	}
	return 0;
}
vector<string> fizzbuzz(int n)
{
	vector<string> result;
	for (int i = 1; i <= n; i++)
	{
		if (i % 15 == 0)
		{
			result.push_back("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			result.push_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			result.push_back("Buzz");
		}
		else
		{
			result.push_back(to_string(i));
		}
	}
	return result;
}