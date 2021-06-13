/*
//BRUTEFORCE approach -:
Here we will be a third array of size equal to the sum of both the given arrays and you will first fill all the elements of first array to new array and then the elements of the second array now sort the newly formed array and then and fill its value to the main two arrays. 
*/

/*
//S-OPTIMAL -:
    1- Here we will take a pointer on the first element of first array and compare it with the first element of second array and if it is greater then that we swap it nad sort the second array again we keep on doing this untill we reach the last element of the first array.
*/
/*
Gap algorithm -:  
    1- First we will calculate a gap by addeing the size of both the arrays and dividing it by 2.

    2-so now we will take two pointers on the gap equal to the gap value.

    3- Whenever you find that the value at the first pointer is greater then the value at  second swap else leave it.

    4- When you reach the last element of the second array you stop.

    5- Now you will half the gap valu and repete the process again untill you reach a situation where gap's value become 1 it means your array is sorted.

    6- Whenever the value of gap is not a whole number take the celing means if 7/2 then 4 will be gap.b
*/

// Swap method

#include <iostream>
#include <algorithm>
using namespace std;

// Utility function to print contents of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to in-place merge two sorted arrays X[] and Y[]
// invariant: `X[]` and `Y[]` are sorted at any point
void merge(int X[], int Y[], int m, int n)
{
    // Consider each element `X[i]` of array `X` and ignore the element if it is
    // already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);
            int first = Y[0];

            // move `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for (k = 1; k < n && Y[k] < first; k++)
            {
                Y[k - 1] = Y[k];
            }

            Y[k - 1] = first;
        }
    }
}

int main()
{
    int X[] = {1, 4, 7, 8, 10};
    int Y[] = {2, 3, 9};

    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    merge(X, Y, m, n);

    cout << "X: ";
    printArray(X, m);
    cout << "Y: ";
    printArray(Y, n);

    return 0;
}

//Gap method
#include <bits/stdc++.h>
using namespace std;

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int *arr1, int *arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}

// Driver code
int main()
{
    int a1[] = {10, 27, 38, 43, 82};
    int a2[] = {3, 9};
    int n = sizeof(a1) / sizeof(int);
    int m = sizeof(a2) / sizeof(int);

    // Function Call
    merge(a1, a2, n, m);

    printf("First Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a1[i]);

    printf("\nSecond Array: ");
    for (int i = 0; i < m; i++)
        printf("%d ", a2[i]);
    printf("\n");
    return 0;
}