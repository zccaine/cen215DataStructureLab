#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


//Insertion Sort Algorithm

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

// Char Array Insertion Sort

void insertionSortChar(char arr[], int n) 
{
    int i, j;
    char key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swapChar(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

//Selection Algorithm

void selectionSort(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void selectionSortChar(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
} 

// Bubble Sort Algorithm

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void bubbleSortChar(char arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(&arr[j], &arr[j+1]); 
} 

// Merge Sort Algorithm

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k, n1, n2; 
    n1 = m - l + 1; 
    n2 = r - m; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
 
        merge(arr, l, m, r); 
    } 
} 
 
void mergeChar(char arr[], int l, int m, int r) 
{ 
    int i, j, k, n1, n2; 
    n1 = m - l + 1; 
    n2 = r - m; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSortChar(char arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
 
        mergeSortChar(arr, l, m); 
        mergeSortChar(arr, m + 1, r); 
 
        mergeChar(arr, l, m, r); 
    } 
}


//Quick Sort Algorithm

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for(j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) { 
        int part = partition(arr, low, high); 
  
        quickSort(arr, low, part - 1); 
        quickSort(arr, part + 1, high); 
    } 
}

char partitionChar(char arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for(j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swapChar(&arr[i], &arr[j]);
        }
    }
    swapChar(&arr[i + 1], &arr[high]);
    return (i+1);
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) { 
        int part = partitionChar(arr, low, high); 
  
        quickSortChar(arr, low, part - 1); 
        quickSortChar(arr, part + 1, high); 
    } 
}

//Heap Sort Algorithm

void heapify(int arr[], int n, int i) { 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) { 
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (j=n-1; j>0; j--) { 
        swap(&arr[0], &arr[j]); 
        heapify(arr, j, 0); 
    } 
} 

void heapifyChar(char arr[], int n, int i) { 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) { 
        swapChar(&arr[i], &arr[largest]); 
        heapifyChar(arr, n, largest); 
    } 
} 
  
void heapSortChar(char arr[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapifyChar(arr, n, i); 
  
    for (j=n-1; j>0; j--) { 
        swapChar(&arr[0], &arr[j]); 
        heapifyChar(arr, j, 0); 
    } 
} 

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


int main() {

    //Selection Sort
    
    clock_t t;

    //School ID
    
    int no[] = { 2, 0, 1, 9, 5, 5, 6, 0, 4, 3 }; 
   
    //Name and Surname
    
    char name[] = "IBRAHIM DOGU KOCACIFTCI"; 
    int n = sizeof(no) / sizeof(no[0]); 
    int charSize = strlen(name);

    t = clock();
    insertionSort(no, n);
    t = clock() - t;
    printArray(no, n); 
    printf("Running Time of Insertion Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);
    
	//start = end;
    
    insertionSortChar(name, charSize);
   
    //end = clock();
    
	t = clock() - t;
    printf("%s\n", name);
    
    //printf("Running Time of Insertion Char Sort Is: %f\n", ((double)(end-start)) / CLOCKS_PER_SEC);
    
    printf("Running Time of Insertion Char Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //Selection Sort
    
    //School ID
    
    int no1[] = {2, 0, 1, 9, 5, 5, 6, 0, 4, 3 }; 
    
    //Name and Surname
    
    char name1[] = "IBRAHIM DOGU KOCACIFTCI"; 
    
    int n1 = sizeof(no1) / sizeof(no1[0]); 
    int charSize1 = strlen(name1);
    selectionSort(no1, n1);
    t = clock() - t;
    printArray(no1, n1); 
    printf("Running Time of Selection Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);
    
    selectionSortChar(name1, charSize1);
    t = clock() - t;
    printf("%s\n", name1);
    printf("Running Time of Selection Char Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);


    //Bubble Sort
  
    //School ID
    
    int no2[] = {2, 0, 1, 9, 5, 5, 6, 0, 4, 3 }; 
    
    //Name and Surname
    
    char name2[] = "IBRAHIM DOGU KOCACIFTCI";
	 
    int n2 = sizeof(no2) / sizeof(no2[0]); 
    int charSize2 = strlen(name2);

    bubbleSort(no2, n2);
    t = clock() - t;
    printArray(no2, n2); 
    printf("Running Time of Bubble Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);

    bubbleSortChar(name2, charSize2);
    t = clock() - t;
    printf("%s\n", name2);
    printf("Running Time of Bubble Char Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);

    

    //Merge Sort

    //School ID
    
    int no3[] = { 2, 0, 1, 9, 5, 5, 6, 0, 4, 3}; 
    
    //Name and Surname
    
    char name3[] = "IBRAHIM DOGU KOCACIFTCI"; 
    
    int n3 = sizeof(no3) / sizeof(no3[0]); 
    int charSize3 = strlen(name3);

    mergeSort(no3, 0, n3 - 1);
    t = clock() - t;
    printArray(no3, n3); 
    printf("Running Time of Merge Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);
    mergeSortChar(name3, 0, charSize3 - 1);
    t = clock() - t;
    printf("%s\n", name3);
    printf("Running Time of Merge Char Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);
    
    //Quick Sort

    
	//School ID
    
    int no4[] = { 2, 0, 1, 9, 5, 5, 6, 0, 4, 3 }; 
    
	
	//Name and Surname
    
    char name4[] = "IBRAHIM DOGU KOCACIFTCI"; 
    int n4 = sizeof(no4) / sizeof(no4[0]); 
    int charSize4 = strlen(name4);

    quickSort(no4, 0, n4 - 1);
    t = clock() - t;
    printArray(no4, n4); 
    printf("Running Time of Quick Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);
    quickSortChar(name4, 0, charSize4 - 1);
    t = clock() - t;
    printf("%s\n", name4);
    printf("Running Time of Quick Char Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);


    //Heap Sort

    //School ID
    
    int no5[] = { 2, 0, 1, 9, 5, 5, 6, 0, 4, 3 }; 
    
	
	//Name and Surname
    
    char name5[] = "IBRAHIM DOGU KOCACIFTCI"; 
    int n5 = sizeof(no5) / sizeof(no5[0]); 
    int charSize5 = strlen(name5);

    heapSort(no5, n5);
    t = clock() - t;
    printArray(no5, n5); 
    printf("Running Time of Heap Sort Is %f\n", ((double)t) / CLOCKS_PER_SEC);
    heapSortChar(name5, charSize5);
    t = clock() - t;
    printf("%s\n", name5);
    printf("Running Time of Heap Char Sort Is: %f\n", ((double)t) / CLOCKS_PER_SEC);


    return 0;
}