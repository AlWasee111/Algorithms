#include <iostream>
using namespace std;
void QuickSort(int* array, int start, int end);
int Partition(int* array, int start, int end);

int main ()
{
    int array[10] = {8, 2, 4, 7, 1, 3, 9, 6, 5};

    cout << "Before quicksort: ";
    for (int i : array)
        cout << i << " ";
    cout << endl;

    QuickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

    cout << "After quicksort: ";
    for (int i : array)
        cout << i << " ";
    cout << endl;
}

void QuickSort(int* array, int start, int end)
{
    if (end <= start) return; // Base case when the partition becomes of size 1
    
    /* Partition function puts everything less than the pivot to the left side of the 
       pivot and everything greater than the pivot to the right side of the pivot */
    int pivotPosition = Partition(array, start, end);

    QuickSort(array, start, pivotPosition - 1); //First half partition before the pivot
    QuickSort(array, pivotPosition + 1, end); //Second half partition after the pivot
}

int Partition(int* array, int start, int end)
{
    int pivot = array[end]; //Take the last element of the array as the pivot
    int i = start - 1;

    for (int j = start; j < end; j++) //Loop ends before the last element of the array
    {
        if (array[j] < pivot)
        {
            /*If element at position j is less than pivot, 
             then increment i by 1 and swap array elements at position i and j*/
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    //Take pivot to its correct position
    i++;
    int temp = array[i];
    array[i] = pivot;
    array[end] = temp;

    return i; //Return the position of the pivot
}