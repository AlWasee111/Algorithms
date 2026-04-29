//Time complexity O(n * k) where k is number of digits of the largest number

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void RadixSort(vector<int>& array);

int main()
{
	vector<int> array{ 560, 310, 455, 670, 298, 129, 739, 833, 922 };

	cout << "Before sorting: ";
	for (double i : array)
		cout << i << " ";
	cout << endl;

	RadixSort(array);

	cout << "After sorting: ";
	for (double i : array)
		cout << i << " ";
}

void RadixSort(vector<int>& array)
{
	int maximum = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		maximum = max(maximum, array[i]);
	}

	vector<vector<int>> bins(10);
	int divisor = 1;

	while (maximum / divisor != 0)
	{
		bins.assign(10, vector<int>());
		for (int i = 0; i < array.size(); i++)
		{
			int binNum = (array[i] / divisor) % 10;
			bins[binNum].push_back(array[i]);
		}

		array.resize(0);
		for (int i = 0; i < 10; i++)
		{
			if (!bins[i].empty())
			{
				for (int j = 0; j < bins[i].size(); j++)
					array.push_back(bins[i][j]);
			}
		}

		divisor *= 10;
	}
}