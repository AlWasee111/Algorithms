#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BucketSort(vector<double>& array);
void HelperInsertionSort(vector<double>& array, int value);

int main()
{
	vector<double> array{ 0.74, 0.61, 0.53, 0.12, 0.34, 0.45, 0.04, 0.27 };

	cout << "Before sorting: ";
	for (double i : array)
		cout << i << " ";
	cout << endl;

	BucketSort(array);

	cout << "After sorting: ";
	for (double i : array)
		cout << i << " ";
}

void BucketSort(vector<double>& array)
{
	int size = array.size();

	vector<vector<double>> buckets(size);

	for (int i = 0; i < size; i++)
	{
		int bucketNumber = (int)(size * array[i]);
		buckets[bucketNumber].push_back(array[i]);
		HelperInsertionSort(buckets[bucketNumber], array[i]);
	}

	array.resize(0);

	for (int i = 0; i < size; i++)
	{
		if (!buckets[i].empty())
		{
			for (int j = 0; j < buckets[i].size(); j++)
				array.push_back(buckets[i][j]);
		}
	}

}

void HelperInsertionSort(vector<double>& array, double value)
{
	int valuePos = -1;

	for (int i = array.size() - 2; i >= 0; i--)
	{
		if (array[i] > value)
			valuePos = i;
	}

	if (valuePos != -1)
	{
		for (int i = array.size() - 1; i > valuePos; i--)
		{
			int temp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = temp;
		}
		array[valuePos] = value;
	}
}