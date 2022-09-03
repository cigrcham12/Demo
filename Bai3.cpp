#include<iostream>
using namespace std;


// 3. Sắp xếp dãy n số nguyên, thực bằng các phương pháp: Selection, Insert, Bubble, Quick sort, merge sort
    // Selection Sort
    void SelectionSort(int *array, const int n){
        for(int i = 0; i < n; i++){
            int min_positive = i;
            for (int j = i + 1; j < n; j++){
                if(*(array + min_positive) > *(array + j))
                    min_positive = j;
            }
            if(i != min_positive){
                swap(*(array + min_positive), *(array + i));
            }
        }        
    }
   // Insert Sort
    void InsertSort(int *array, const int n){
        for(int i = 1; i < n; i++){
            int key = *(array + i);
            int j = i - 1;
            
            while (j >= 0 && *(array + j) > key)
            {
                *(array + j + 1) = *(array + j);
                j--;
            }
            *(array + j) = key;
            
        }
    }  
    // Bubble Sort
    void BubbleSort(int *array, const int n){
        bool haveSwap = false;
        for(int i = 0; i < n - 1; i++){
            haveSwap = false;
            for(int j = 0; j < n - i - 1; j++){
                if(*(array + j) > *(array + j + 1)){
                    swap(*(array + j), *(array + j + 1));
                    haveSwap = true;
                }
            }
            if (!haveSwap)
            {
                break;
            }
        }
    }
    // Quick Sort
    void QuickSort(int *array, int left, int right){
        if(array == nullptr || right - left == 0){
            return;
        }
        else if(left >= right){
            return;
        }
        else{
            int pivot = *(array + left);
            int i = left, j = right;
            while (i <= j)
            {
                while (*(array + i) < pivot)
                {
                   i++;
                }
                while(*(array + j) > pivot){
                    j--;
                }
                if(i <= j){
                    swap(*(array + i), *(array + j));
                    i++;
                    j--;
                }
            }
            if(left < j){
                QuickSort(array, left, j);
            }
            if(right > i){
                QuickSort(array, i, right);
            }
        }
    }
    // Merge Sort
    void MergeSort(int array[], int left, int right){
        if(left < right){
            int middle = (left + right - 1) / 2;

            MergeSort(array, left, middle);
            MergeSort(array, middle + 1, right);

            merge(array, left, middle, right);
        }
    }
    void merge(int array[], int left, int middle, int right){
        int n1 = middle - left + 1;
        int n2 = right - middle;
    
        int Left_array[n1], Right_array[n2];
        for(int i = 0; i < n1; i++)
            Left_array[i] = array[left + i];
        for(int i = 0; i < n2; i++)
            Right_array[i] = array[middle + i + 1];
        
        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2){
            if(Left_array[i] <= Right_array[j]){
                array[k] = Left_array[i];
                i++;
            }
            else{
                array[k] = Right_array[j];
                j++;
            }
            k++;
        } 

        while (i < n1){
            array[k] = Left_array[i];
            i++;
            k++;
        }

        while(j < n2){
            array[k] = Right_array[j];
            j++;
            k++;
        }
          
    }
    // Print Array
    void print_Array(int *array, int n){
    for(int i = 0; i < n; i++)
        cout << *(array + i) << "   ";
    cout << endl;
}


int main(int argc, char const *argv[])
{
    int array[] = {3, 4, 5, 6, 3, 3234, 324, -435, 4123, 654, -1234, 5432, 123, 9, 5, 6, 3, 5, 4};
    int length = sizeof(array) / sizeof(int);
    print_Array(array, length);
    SelectionSort(array, length);
    InsertSort(array, length);
    QuickSort(array, 0, length);
    BubbleSort(array, length);
    MergeSort(array, 0, length - 1);
    print_Array(array, length);
    cout << calulator5(5.4, 4);
    return 0;
}