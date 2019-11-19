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
void printArray(int a[], int size);
void randomizeArray (int a[], int size);
void quickSort(int a[], int first, int last);
<<<<<<< Updated upstream
bool isSorted(int a[], int size);

=======
void radixSort(int a[], int n);
void countSort(int a[], int n, int exp);
void isSorted(int a[], int size);
int max(int a[], int n);
>>>>>>> Stashed changes
/************************  M A I N   F U N C T I O N  **********************/

int main()
{
    //initialize variables
    int arraySize;
    struct timeval before, after;
<<<<<<< Updated upstream
    double timing;
=======
    double timing, timingQuick, timingRadix;
>>>>>>> Stashed changes

    //ask the user for the size of the array
    cout << "Please enter the size of the array." << endl;
    cin >> arraySize;

<<<<<<< Updated upstream
    //allocate a dynamic array of the appropriate size
    int* arr=NULL;
    arr = new int[arraySize];
   
    //input all the elements of the array from the
    //cin (I will use redirection from a file for the test)
    //inputArray(arr, arraySize);

    srand (time(NULL));                              //initializes random seed
    randomizeArray(arr, arraySize);                  //randomly generates numbers to populate
    gettimeofday (&before, 0);                       //set beginning time
    
    //sort array
    quickSort(arr, 0, arraySize-1);
    
    gettimeofday (&after, 0);                        //set ending time
=======
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
>>>>>>> Stashed changes
    timing = (double) ((double)after.tv_sec +
             (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
	     (double)before.tv_usec/(1000*1000));    //calculate total time

<<<<<<< Updated upstream
    //output the sorted array;
    cout << endl;
    cout << "Here is the sorted array: " << endl;
    printArray(arr, arraySize);

    //test if the array is sorted, just in case
    cout << "\n" << "\n";
    if (isSorted(arr, arraySize))
        cout << "Sorted." << endl;
    else
        cout << "Not sorted." << endl;

    //output the timing information.
    cout << "\n" << "\n";
    cout << "It took " << timing << " seconds to sort the array." << endl;

    delete []arr;
    arr=NULL;
    return 0;
}//main()
=======
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
>>>>>>> Stashed changes




/***************** A D D I T I O N A L  F U N C T I O N S ********************/
void printArray(int a[], int size)
{
    for (int i = 0; i<size; ++i)
    {
      cout << a[i] << ", ";                          //print element
    }
}//printArray()



//Using a randomize function to generate numbers to fill array
void randomizeArray (int a[], int size)
{
    srand((unsigned)time(0));

    //Using RAND_MAX, a constant in cstdlib guaranteed to be at
    //least32767 for generating random numbers. 
    for (int i=0; i<size; ++i)
        a[i]=(rand()%RAND_MAX);   
}//randomizeArray()


//Quick Sort has average complexity best case O(n log2 n) and worst case
// is O(n^2).
void quickSort(int a[], int first, int last)
{
    if (last <= first)                       //check if size is larger than zero
        return;
    int pivot = a[first];
    int i = first + 1, j = last;             //Initialize traversing variables
     
    while (i < j)                            //loop until index i and j converge
    {
         while (a[i] < pivot && i<j)
	     i++;                     // finding an object at least as large
         while (a[j] > pivot)             // as a[first].
             j--;
         if (i < j)
	   swap(a[i++], a[j--]);
    }

    if (a[j] > pivot)
        j--;
    swap (a[j], a[first]);
    quickSort(a, first, j-1);
    quickSort(a, j+1, last);
}// quickSort()

<<<<<<< Updated upstream
bool isSorted(int a[],int size)
=======
void radixSort(int a[], int n)
{
    int m = max(a, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(a, n, exp);
    return;
}// radixSort()

void countSort(int a[], int n, int exp)
>>>>>>> Stashed changes
{
    for (int i=0; i<size-1; i++)
    {
        if (a[i] > a[i+1])
            return false;
    }
    return true;
}
<<<<<<< Updated upstream

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
=======
>>>>>>> Stashed changes
