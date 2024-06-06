#include <stdio.h>

void bubble_sort(int a[], int size);

int main(void){
int size = 6;
int arr [size];
int i = 0;

printf("Masukkan %d angka:\n", size);
    for(i = 0; i < size; i++) {
        printf("Elemen %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

printf ("before:\n");
for(i = 0 ; i<6; i++) printf("%d ", arr[i]);
printf("\n"); 

bubble_sort (arr, 6);

printf("after:\n");
for(i=0; i < 6 ;i ++) printf("%d ", arr[i]);
printf("\n");

return 0;
}

void bubble_sort(int a[], int size) {
int switched = 1;
int hold = 0;
int i=0;
int j = 0;

size -= 1;

for( i = 0 ; i < size && switched; i++) {
switched = 0;
for ( j = 0; j < size -i; j++)
if (a[j] > a[j + 1]) {
switched = 1;
hold=a[j];
a[j] = a[j + 1];
a[j+1] = hold;
}
}
}