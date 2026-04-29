//Time complexity: O(n + k) where k is the range of numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> CountingSort(vector<int>& array);

int main()
{
	vector<int> array = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	cout << "Before sort: ";
	for (int i : array)
		cout << i << " ";
	cout << endl;

	array = CountingSort(array);

	cout << "After sort: ";
	for (int i : array)
		cout << i << " ";
}

vector<int> CountingSort(vector<int>& array)
{
	vector<int> sorted(array.size(), 0);
	int k = array[0];

	for (int i = 1; i < array.size(); i++)
	{
		k = max(k, array[i]);
	}
	vector<int> counter(k + 1, 0);

	for (int i = 0; i < array.size(); i++)
	{
		counter[array[i]]++;
	}

	for (int i = 1; i < array.size(); i++)
	{
		counter[i] += counter[i - 1];
	}
	
	for (int i = array.size() - 1; i >= 0; i--)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	return sorted;
}