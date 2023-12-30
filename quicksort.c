#include <stdio.h>
void swap(int* a, int* b){
int temp = *a;
*a = *b;
*b = temp;
}
int logic_exec(int array[], int low, int high){
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}
void recurse(int array[], int low, int high){
     if (low < high) {
        int pivotIndex = logic_exec(array, low, high);
        recurse(array, low, pivotIndex - 1);
        recurse(array, pivotIndex + 1, high);
    }
}
void quciksort(int array[], int length){
recurse(array, 0, length - 1);

}
int main(int argc, char const *argv[])
{
    int array[] = {5,2,3,4,6,7,9,1,8};
    int length = 9;
    quciksort(array, length);
    for (int i = 0; i < length; i++)
    {
        printf("\n%d", array[i]);
    }
    
    return 0;
}
