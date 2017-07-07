#include<bits/stdc++.h>
using namespace std;

/**-------------------------------------------------------------------
* Selection Sort
* time complexity: n^2
* memory complexity: 1
*-------------------------------------------------------------------*/
void selectionSort(int arr[], int n)
{
    int min_idx;
    for(int i=0; i<n-1; i++)
    {
        min_idx = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[i], arr[min_idx]);
    }
}
/**-------End of Selection Sort--------------------------------------*/


/**--------------------------------------------------------------------
* Insertion Sort
* time complexity: n^2
* memory complexity: 1
----------------------------------------------------------------------*/
void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
/**-------End of Insertion Sort--------------------------------------*/


/**--------------------------------------------------------------------
* Merge Sort
* time complexity
* best: n log n
* avg: n log n
* worst: n log n
* memory complexity: n
----------------------------------------------------------------------*/
void merge(int arr[], int l, int m, int r)
{
    int leftSize = m-l+1;
    int rightSize = r-m;

    int leftArr[leftSize];
    int rightArr[rightSize];

    int idx = 0;
    for(int i=l; i<=m; i++)
    {
        leftArr[idx++] = arr[i];
    }

    idx = 0;
    for(int i=m+1; i<=r; i++)
    {
        rightArr[idx++] = arr[i];
    }

    idx = l;
    int i = 0, j = 0;
    while(i<leftSize && j<rightSize)
    {
        if(leftArr[i] < rightArr[j])
        {
            arr[idx++] = leftArr[i++];
        }
        else
        {
            arr[idx++] = rightArr[j++];
        }
    }

    while(i<leftSize) arr[idx++] = leftArr[i++];
    while(j<rightSize) arr[idx++] = rightArr[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
/**-----------End of Merge Sort---------------------------------------*/


/**--------------------------------------------------------------------
* Quick Sort
* complexity
* best n log n
* avg: n log n
* worst: n^2
* memory complexity: in place
----------------------------------------------------------------------*/
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int smallerIdx = l-1;

    for(int i=l; i<r; i++)
    {
        if(arr[i] < pivot)
        {
            smallerIdx++;
            swap(arr[smallerIdx], arr[i]);
        }
    }
    swap(arr[smallerIdx+1], arr[r]);
    return smallerIdx+1;
}

void quickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pivotIdx = partition(arr, l, r);
        quickSort(arr, l, pivotIdx-1);
        quickSort(arr, pivotIdx+1, r);
    }
}
/**---------------End of Quick Sort----------------------------------*/


/**--------------------------------------------------------------------
* Function for printing array
*/
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
}
/**---------------End of Print Array ----------------------------------*/


/**--------------------------------------------------------------------
* Main function
*/
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
//    selectionSort(arr, n);
//    insertionSort(arr,n);
//    mergeSort(arr, 0, n-1);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
/**---------------End of Main Function----------------------------------*/





