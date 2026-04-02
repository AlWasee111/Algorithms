//Time complexity: O(n + k) where k is the range of numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void CountingSort(vector<int>& array);

int main()
{
	vector<int> array = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	cout << "Before sort: ";
	for (int i : array)
		cout << i << " ";
	cout << endl;

	CountingSort(array);

	cout << "After sort: ";
	for (int i : array)
		cout << i << " ";
}

void CountingSort(vector<int>& array)
{
	int k = array[0];

	for (int i = 1; i < array.size(); i++)
	{
		k = max(k, array[i]);
	}

	vector<int> counter (k + 1, 0);

	for (int i = 0; i < array.size(); i++)
	{
		counter[array[i]]++;
	}

	array.resize(0);
	for (int i = 0; i < counter.size(); i++)
	{
		for (int j = 0; j < counter[i]; j++)
		{
			array.push_back(i);
		}
	}
} 