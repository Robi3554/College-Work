#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int arr[N];


void swap(int* x, int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSort(int arr[], int n){

    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

}

int binarySearch(int arr[], int key, int *i){
    int rc=-1;
    int low=0;
    int high=N-1;
    int mid;
    *i=0;
    while(low<=high && rc==-1){
        mid = (low+high)/2;
        (*i)++;

        if (key < arr[mid])

            high = mid-1;

        else if (key > arr[mid])

            low = mid+1;

        else{
            rc=mid;

            printf("\nA fost gasit numarul pe pozitia %d !",rc);

            return rc;
        }

    }

    printf("\nNumarul cautat nu s-a gasit");

    return rc;

}

int linearSearch(int arr[], int x, int i)
{
    for (i=0; i < N; i++)
        if (arr[i] == x)
        {
            printf("\nA fost gasit numarul pe pozitia %d !",i);
            return i;
        }

    printf("\nNumarul cautat nu s-a gasit");

    return i;

}

int main(void)
{

    int i,x, j, flag_end, nr;

    srand(time(NULL));

    for(i=0; i<N; i++){

        flag_end = 1;

        while(flag_end){

            flag_end = 0;

            nr = rand()%1000;

            for(j = 0; j < i; j++)

                if(arr[j] == nr)

                    flag_end = 1;

            if (!flag_end){

                arr[i] = nr;

                break;

            }

        }

    }

    for(i=0; i<N; i++) printf("[%d] ",arr[i]);

    printf("\n Numar cautat: ");

    scanf("%d", &x);

    printf("\nAlgoritmul a facut %d pasi\n\n", linearSearch(arr,x,i)+1);

    bubbleSort(arr,N);

    for(i=0; i<N; i++)

        printf("[%d] ",arr[i]);

    binarySearch(arr,x,&i);

    printf("\nAlgoritmul a facut %d pasi\n\n", i);

    return 0;



}
