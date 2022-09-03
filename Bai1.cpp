#include<iostream>
using namespace std;



// 1. Tìm Min, Max của dãy n số nguyên, thực 
    // Find max
    int find_max(int *array, int n){

    int max = *array;
    for(int i = 1; i < n; i++)
    {
        if(max < *(array + i))
        {
            max = *(array + i);
        }
    }
    return max;
}
    // Find min
    int find_min(int *array, int n){

    int min = *array;
    for(int i = 1; i < n; i++)
    {
        if(min > *(array + i))
        {
            min = *(array + i);
        }
    }
    return min;
}
int main(int argc, char const *argv[])
{
    int array[] = {3, 4, 5, 3, 2, 5, 134, 324};
    cout << find_max(array, sizeof(array) / sizeof(int)) << endl;
    cout << find_min(array, sizeof(array) / sizeof(int)) << endl;
    return 0;
}
