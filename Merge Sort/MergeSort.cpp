#include <iostream>
#include <vector>
void MergeSort(std::vector<int>& array);
void Merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& array);

int main()
{
	std::vector<int> array;
	for (int i = 1; i < 11; i++)
		array.push_back(i);

	MergeSort(array);

	for (int i : array)
		std::cout << i << " ";
}

void MergeSort(std::vector<int>& array)
{
	if (array.size() <= 1)
		return;

	int middle = array.size() / 2;
	int leftSize = middle;
	int rightSize = array.size() - middle;

	std::vector<int> leftArray;
	std::vector<int> rightArray;

	for (int i = 0; i < array.size(); i++)
	{
		if (i < leftSize)
			leftArray.push_back(array[i]);
		else
			rightArray.push_back(array[i]);
	}

	MergeSort(leftArray);
	MergeSort(rightArray);
	Merge(leftArray, rightArray, array);
}

void Merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& array)
{
	int arrayIdx = 0, leftIdx = 0, rightIdx = 0;
	while (leftIdx < leftArray.size() && rightIdx < rightArray.size())
	{
		if (leftArray[leftIdx] < rightArray[rightIdx])
		{
			array[arrayIdx++] = leftArray[leftIdx++];
		}
		else
		{
			array[arrayIdx++] = rightArray[rightIdx++];
		}
	}

	while (leftIdx < leftArray.size())
		array[arrayIdx++] = leftArray[leftIdx++];

	while (rightIdx < rightArray.size())
		array[arrayIdx++] = rightArray[rightIdx++];
}