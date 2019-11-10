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

using namespace std;



/****************  F U N C T I O N  P R O T O T Y P E S  ******************/
void printArray(int arrayA[], int size);
void randomizeArray (int arrayA[], int size);
void quickSort(int a[], int first, int last);


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

         
    // sort the array and time the sorting functions alone (see below);

    gettimeofday (&before, 0);
    //int arrayFirst = arr[0];
    //int arrayLast = arr[arraySize-1];
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    gettimeofday (&after, 0);
    timing = (double) ((double)after.tv_sec +
             (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
             (double)before.tv_usec/(1000*1000));
    // output the sorted array;

    printArray(arr, arraySize);

    // output the timing information.

    cout << "The timing for the sorted array is: " << timing << " ." << endl;

    delete []arr;
    arr=NULL;
    return 0; // Indicate normal termination.
} // main()




/***************** A D D I T I O N A L  F U N C T I O N S ********************/
void printArray(int arrayA[], int size)
{
    cout << endl;
    cout << "Here is the sorted array: " << endl;

    for (int i = 0; i<size; ++i)
    {
      cout << arrayA[i] << ", ";
      
    }
}// print()



/**************** Using a randomize function to generate numbers to fill array 
                  for testing purposes*********************************/
void randomizeArray (int arrayA[], int size)
{
    srand((unsigned)time(0));

    for (int i=0; i<size; ++i)
      // Using RAND_MAX, a constant in cstdlib guaranteed at to be at least
      // 32767 for generating random numbers. 
      arrayA[i]=(rand()%RAND_MAX-1);   


    /*Printing merely to compare with sorted array after tests run*/
    cout << "Here is a randomly generated integer array based upon size entered by user: " << endl;

    for (int i = 0; i<size; ++i)
    {
      cout << arrayA[i] << ", ";
      
    }
    
}//randomizeArray()


//Quick Sort has average complexity best case O(n log2 n) and worst case
// is O(n^2).
void quickSort(int a[], int first, int last)
{
    if (last <= first)
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
      {
	j--;
        swap(a[j], a[first]);
      }
  quickSort(a, first, j-1);
  quickSort(a, j+1, last);

}// quickSort()




/*Including the code for Binary Insertion Sort just in case.
  Will need to add to prototypes if decide to use it!
 
//Binary Insertion Sort best case is: O(n log2 n).

void binaryInsertionSort (int arrayA[], int size)
{
    for (int p = 1; p<size; ++p)
      {
        bool found;
        int k;
        binarySearch(a, a[p], 0, p-1, found, k); //possibly binary_search as in                                                    CSTL library...
        int temp = a[p];
        for (int i = p-1; i>=k; --i)
	a[i+1]=a[i];
      a[k] = temp;
    }


}//binaryInsertionSort()
*/
