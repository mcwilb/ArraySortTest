/*****************************************************************************
  Authors:       Brandi McWilliams, Jordan Lewis
                
  Class:         C243 Data Structures
  File name:     main.cc
  Last updated:  November 10, 2019
  Description:   Main function.
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <fstream>

using namespace std;



/****************  F U N C T I O N  P R O T O T Y P E S  ******************/
void printArray(int a[], int size);
void randomizeArray (int a[], int size);
void quickSort(int a[], int first, int last);
void radixSort(int a[], int n);
void countSort(int a[], int n, int exp);
void isSorted(int a[], int size);
int max(int a[], int n);
/************************  M A I N   F U N C T I O N  **********************/

int main()
{

    int arraySize;
    struct timeval before, after;
    double timing, timingQuick, timingRadix;

    // ask the user for the size of the array
    cout << "Please enter the size of the array." << endl;
    cin >> arraySize;

    // allocate a dynamic array of the appropriate size
    int* arr = NULL;            // Pointer to an int, initialized to NULL.
    int* arr2 = NULL;
    
    arr = new int[arraySize];   // Dynamic array allocation use arraySize input
    arr2 = new int[arraySize];  // by user
        
    // input all the elements of the array from the
    // cin (I will use redirection from a file for the test)
    //for (int i=0; i<arraySize; i++)
    //    cin >> a[i];

    srand (time(NULL));              // initializes random seed
    randomizeArray(arr, arraySize);  // randomly generates numbers to populate
    arr2 = arr;
            
    /*                            
    ifstream testFile;
    testFile.open("test500.txt");         // Reading in the test500 file
    while (!testFile.eof())               // and storing the numbers into array
    {
        for (int k=0; k < arraySize; k++) // Making sure we don't exceed 
	    testFile >> arr[k];           // array size that was input by user.
    }
    testFile.close();
    */
    
    // quicksort the array and time the sorting functions alone (see below);
    gettimeofday (&before, 0);
    quickSort(arr, 0, arraySize-1);
    gettimeofday (&after, 0);
    timing = (double) ((double)after.tv_sec +
             (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
             (double)before.tv_usec/(1000*1000));
    timingQuick = timing;

    //cout << endl;
    //printArray(arr, arraySize);

    // output the timing information.
    cout << endl;
    isSorted(arr, arraySize);
    cout << endl;
    cout << "The timing for the quicksorted array is: " 
         << timing << " seconds." << endl;

    
    // radixsort and time
    gettimeofday (&before, 0);
    radixSort(arr2, arraySize);
    gettimeofday (&after, 0);
    timing = (double) ((double)after.tv_sec +
             (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
             (double)before.tv_usec/(1000*1000));
    timingRadix = timing;

    //cout << endl;
    //printArray(arr, arraySize);

    // output the timing information.
    cout << endl;
    isSorted(arr2, arraySize);
    cout << endl;
    cout << "The timing for the radixsorted array is: " 
         << timing << " seconds." << endl;
    cout << endl << endl;

    // Determine faster sort method
    if (timingQuick < timingRadix)
        cout << "The quicksort was quicker." << endl << endl;
    else
        cout << "The radixsort was quicker." << endl << endl;

    
    arr = NULL;
    arr2 = NULL;
    return 0; // Indicate normal termination.
} // main()




/***************** A D D I T I O N A L  F U N C T I O N S ********************/
// prints array
void printArray(int a[], int size)
{
    for (int i = 0; i<size; ++i)
        cout << a[i] << ", ";
}// print()


// use a random number generators to fill array
void randomizeArray (int a[], int size)
{
    srand((unsigned)time(0));

    for (int i=0; i<size; ++i)
        // Using RAND_MAX, a constant in cstdlib guaranteed at to be at least
        // 32767 for generating random numbers. 
        a[i]=(rand()%RAND_MAX);   
}// randomizeArray()


// Quick Sort has average complexity best case O(n log2 n)
// and worst case is O(n^2).
void quickSort(int a[], int first, int last)
{
    if (last <= first)           //base case arrays <= 1 in length are sorted
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

void radixSort(int a[], int n)
{
    int m = max(a, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(a, n, exp);
    return;
}// radixSort()

void countSort(int a[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i<n; i++)
        count[(a[i]/exp)%10]++;
    for (i = 1; i<10; i++)
        count[i] += count[i-1];
    for (i = n-1; i >= 0; i--)
    {
        output[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }
    for (i = 0; i<n; i++)
        a[i] = output[i];
    return;
}// countSort()

void isSorted(int a[], int size)
{
    for (int i = 0; i<size-1; i++)
        if (a[i] > a[i+1])
        {
            cout << "The array is not sorted correctly." << endl;
            return;
        }
    cout << "The array is sorted." << endl;
    return;
}// isSorted()

int max(int a[], int n)
{
    int max = 0;
    for (int i = 0; i<n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
