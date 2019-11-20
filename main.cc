/*****************************************************************************
  Authors:       Brandi McWilliams, Jordan Lewis
  Class:         C243 Data Structures
  File name:     main.cc
  Last updated:  November 20, 2019
  Description:   Inputs array from console and uses the
                 quicksort algorithm to sort the array
                 present the time taken to complete.
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
using namespace std;

/****************  F U N C T I O N  P R O T O T Y P E S  ******************/
void printArray(int a[], int size);
void quickSort(int a[], int first, int last);
bool isSorted(int a[], int size);

/************************  M A I N   F U N C T I O N  **********************/

int main()
{

    int arraySize;
    struct timeval before, after;
    double timing;

    // ask the user for the size of the array
    cout << "Please enter the size of the array." << endl;
    cin >> arraySize;

    // Dynamically allocate array with size=arraySize
    int* arr = NULL;
    arr = new int[arraySize];
        
    // input all the elements of the array from the
    // cin (I will use redirection from a file for the test)
    for (int i=0; i<arraySize; i++)
        cin >> arr[i];

    // Initialize random seed
    srand (time(NULL));
                
    // quicksort the array and time the sorting
    gettimeofday (&before, 0);
    quickSort(arr, 0, arraySize-1);
    gettimeofday (&after, 0);
    timing = (double) ((double)after.tv_sec +
             (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
             (double)before.tv_usec/(1000*1000));
    
    //Uncomment following two lines to print array
    //cout << endl;
    //printArray(arr, arraySize);

    // Check if the array is sorted and output timing information.
    cout << endl;
    if (isSorted(arr, arraySize))
        cout << "The array is correctly sorted." << endl;
    else
        cout << "The array did not sort correctly." << endl;
    cout << endl;
    cout << "The timing for the quicksorted array is: " 
         << timing << " seconds." << endl;

    arr = NULL;
    return 0;
} // main()

/***************** A D D I T I O N A L  F U N C T I O N S ********************/
// prints array
void printArray(int a[], int size)
{
    for (int i = 0; i<size; ++i)
        cout << a[i] << ", ";
}// print()

// Quick Sort average complexity best=O(n log2 n)
// and worst=O(n^2).
void quickSort(int a[], int first, int last)
{
    if (last <= first)              //array is empty
        return;

    int pivot = a[first];
    int i = first+1, j = last;

    while (i < j)
    {
        while (a[i] < pivot && i<j)
	    i++;
        while (a[j] > pivot)
	    j--;
        if (i < j)
	    swap(a[i++], a[j--]);
    }
    if (a[j] > pivot)
	j--;

    swap(a[j], a[first]);  
    quickSort(a, first, j-1);
    quickSort(a, j+1, last);
}// quickSort()

bool isSorted(int a[], int size)
{
    for (int i = 0; i<size-1; i++)
        if (a[i] > a[i+1])          //If any element is larger than next
            return false;           //Return false
    return true;
}// isSorted()

