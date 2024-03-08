#include <stdio.h>

typedef struct item{
    int value;
    int times;

} item;

void swap(item* a, item* b)
{
    item temp = *a;
    *a = *b;
    *b = temp;
    a->times++;
    b->times++;
}

int sumArray(item array[], int size){
    int sum = 0;
    for (int i = 0; i<size;i++){
        sum += array[i].times;
    }
    return sum;
}
void bubbleSort(item array[], int size){
    int swapped;
    for (int i = 0; i<size-1;i++){
        swapped = 0;
        for (int j = 0; j<size-i-1;j++){
            if (array[j].value>array[j+1].value){
                swap(&array[j],&array[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        break;
    }
   
   for (int i = 0; i<size;i++){
    printf("%d: %d\n",array[i].value,array[i].times);
    }
    printf("Total: %d\n", sumArray(array,9)/2);
}

void selectionSort(item array[], int size){
    int min;

    for (int i=0; i< size-1; i++){
        min = i;
        for (int j = i+1; j<size; j++){
            if (array[j].value < array[min].value)
                min = j;
        }
        if(min != i)
        swap(&array[i],&array[min]);
    }
   
   //print
   for (int i = 0; i<size;i++){
    printf("%d: %d\n",array[i].value,array[i].times);
    }
    printf("Total: %d\n", sumArray(array,9)/2);
} 

int main(){
    item array1A[] = {97,0,16,0,45,0,63,0,13,0,22,0,7,0,58,0,72,0};
    item array2A[] = {90,0,80,0,70,0,60,0,50,0,40,0,30,0,20,0,10};
    item array1B[] = {97,0,16,0,45,0,63,0,13,0,22,0,7,0,58,0,72,0};
    item array2B[] = {90,0,80,0,70,0,60,0,50,0,40,0,30,0,20,0,10};

    //size = 9
    printf("Array 1 Bubble Sort:\n");
    bubbleSort(array1B, 9);

    printf("Array 2 Bubble Sort:\n");
    bubbleSort(array2B, 9);

    printf("Array 1 Selection Sort:\n");
    selectionSort(array1A, 9);

    printf("Array 2 Selection Sort:\n");
    selectionSort(array2A, 9);
}