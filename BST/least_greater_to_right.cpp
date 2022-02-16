#include <bits/stdc++.h>
using namespace std;


vector<int> nextGreaterIndex(vector<pair<int, int> >& temp)
{
	int n = temp.size();
	
	vector<int> res(n, -1);
	stack<int> stack;
	for (int i = 0; i < n; i++) {
		
		if (stack.empty() || temp[i].second < stack.top())
			stack.push(temp[i].second); 
		
		else {
			while (!stack.empty()
				&& temp[i].second > stack.top()) {
				res[stack.top()] = temp[i].second;
				stack.pop();
			}
			
			stack.push(temp[i].second);
		}
	}
	return res;
}



vector<int> replaceByLeastGreaterUsingStack(int arr[],	int n)
{
	
	vector<pair<int, int> > temp;
	for (int i = 0; i < n; i++) {
		temp.push_back({ arr[i], i });
	}
	sort(temp.begin(), temp.end());
	
	
	vector<int> indexes = nextGreaterIndex(temp);
	
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		
		if (indexes[temp[i].second] != -1)
			res[temp[i].second]= arr[indexes[temp[i].second]];
	}
	
	
	
	return res;
}

int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
				43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr) / sizeof(int);
	auto res = replaceByLeastGreaterUsingStack(arr, n);
	cout << "Least Greater elements on the right side are "
		<< endl;
	for (int i : res)
		cout << i << ' ';
	cout << endl;
	return 0;
} 
