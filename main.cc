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
void partitionForMedianPivot(int a[], int l, int r, int &i, int &j);
void medianPartitionQuickSort(int a[], int l, int r);


/************************  M A I N   F U N C T I O N  **********************/

int main()
{

    int arraySize;
    struct timeval before, after;
    double timing;

    // ask the user for the size of the array

    cout << "Please enter the size of the array." << endl;

    cin >> arraySize;

    // allocate a dynamic array of the appropriate size

    int* arr = NULL;  // Pointer to an int, initialized to NULL.

    arr = new int[arraySize];   // Dynamic array allocation use arraySize input
                                // by user.
   
    // input all the elements of the array from the
    // cin (I will use redirection from a file for the test)

     srand (time(NULL));    //initializes random seed
    
    randomizeArray(arr, arraySize); // randomly generates numbers to populate.
                              // Also prints display of array to compare with
                             // sorted array after.

    /*                            
    ifstream testFile;
    testFile.open("test500.txt");      // Reading in the test500 file
    while (!testFile.eof())            // and storing the numbers into array.
     {
	for (int k=0; k < arraySize; k++)  // Making sure we don't exceed 
	  testFile >> arr[k];             // array size that was input by user.
	
     }
    testFile.close();
    */
    // sort the array and time the sorting functions alone (see below);

    gettimeofday (&before, 0);
 
    quickSort(arr, 0, arraySize-1);
    // medianPartitionQuickSort(arr, 0, arraySize-1);
    
    gettimeofday (&after, 0);
    timing = (double) ((double)after.tv_sec +
             (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
             (double)before.tv_usec/(1000*1000));
    // output the sorted array;
    cout << endl;
    printArray(arr, arraySize);

    // output the timing information.
    cout << endl;
    cout << "The timing for the sorted array is: " << timing << " ." << endl;

    delete []arr;
    arr=NULL;
    return 0; // Indicate normal termination.
} // main()




/***************** A D D I T I O N A L  F U N C T I O N S ********************/
void printArray(int a[], int size)
{
    cout << endl;
    cout << "Here is the sorted array: " << endl;

    for (int i = 0; i<size; ++i)
    {
      cout << a[i] << ", ";
      
    }
}// print()



/**************** Using a randomize function to generate numbers to fill array 
                  for testing purposes*********************************/
void randomizeArray (int a[], int size)
{
    srand((unsigned)time(0));

    for (int i=0; i<size; ++i)
      // Using RAND_MAX, a constant in cstdlib guaranteed at to be at least
      // 32767 for generating random numbers. 
      a[i]=(rand()%RAND_MAX);   


    /*Printing merely to compare with sorted array after tests run*/
    cout << "Here is a randomly generated integer array based upon size entered by user: " << endl;

    for (int i = 0; i<size; ++i)
    {
      cout << a[i] << ", ";
      
    }
    
}//randomizeArray()


//Quick Sort has average complexity best case O(n log2 n) and worst case
// is O(n^2).
void quickSort(int a[], int first, int last)
{
  //This is the code used in the slides

    if (last <= first)   //base case arrays <= 1 in length are sorted
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

void partitionForMedianPivot(int a[], int l, int r, int &i, int &j) 
{ 
    i = l-1, j = r; 
    int p = l-1, q = r; 
    int v = a[r]; 
  
    while (true) 
    { 
        // From left, find the first element greater than 
        // or equal to v. This loop will definitely terminate 
        // as v is last element 
        while (a[++i] < v); 
  
        // From right, find the first element smaller than or 
        // equal to v 
        while (v < a[--j]) 
            if (j == l) 
                break; 
  
        // If i and j cross, then we are done 
        if (i >= j) break; 
  
        // Swap, so that smaller goes on left greater goes on right 
        swap(a[i], a[j]); 
  
        // Move all same left occurrence of pivot to beginning of 
        // array and keep count using p
       if (a[i] == v) 
         { 
            p++; 
            swap(a[p], a[i]); 
         } 
  
        // Move all same right occurrence of pivot to end of array 
        // and keep count using q 
        if (a[j] == v) 
        { 
            q--; 
            swap(a[j], a[q]); 
        } 
    } 
  
    // Move pivot element to its correct index 
    swap(a[i], a[r]); 
  
    // Move all left same occurrences from beginning 
    // to adjacent to arr[i] 
    j = i-1; 
    for (int k = l; k < p; k++, j--) 
        swap(a[k], a[j]); 
  
    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    i = i+1; 
    for (int k = r-1; k > q; k--, i++) 
        swap(a[i], a[k]); 
 

	
} //partitionForMedianPivot()


void medianPartitionQuickSort(int a[], int l, int r) 
//This version is referred to as the Dutch National Flag algorithm

{ 
   if (r <= l) return; 
  
    int i, j; 
  
    // Note that i and j are passed as reference 
    partitionForMedianPivot(a, l, r, i, j); 
  
    // Recur 
    medianPartitionQuickSort(a, l, j); 
    medianPartitionQuickSort(a, i, r); 
} 
/*
Test outputs for timing:
Below are some speed test outputs using the regular quicksort function
Test 1 uses the test500.txt:

The timing for the sorted array is: 0.000101089 .

Test 2 of quicksort using 5,000 randomly generated numbers:

The timing for the sorted array is: 0.00108099 .

Test 3 of quicksort using 50,000 randomly generated numbers:

The timing for the sorted array is: 0.00818706 .

And test 4 using quicksort and 500,000 randomy generated numbers:

The timing for the sorted array is: 0.096792 .
-----------------------------------------------------------------

Switching over to the median of 3 pivot version of the quicksort:
Test 1 uses test500.txt:

The timing for the sorted array is: 0.000123978 .

Test 2 uses median of 3 qs and 5,000 randomly generated numbers:

The timing for the sorted array is: 0.000972033 .

Test 3 uses median of 3 qs and 50,000 randomly generated numbers:

The timing for the sorted array is: 0.00912499 .

Test 4 uses median of 3 qs and 500,000 randomly generated numbers:

The timing for the sorted array is: 0.104763 .

Comparing the two the standard quicksort appears to be more efficient than 
the median pivot version of the quick sort.



*/
