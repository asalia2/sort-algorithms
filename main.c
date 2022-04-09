/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#define siz 2500000
#define  size_a 1000
#define size_b 10000
#define size_c 100000
#define size_d 1000000
#define size_e 5000000
static int temp_1[siz];
static int temp_2[siz];
static int temp_3[size_e];

static int arr_a[size_a];
static int arr_b[size_b];
static int arr_c[size_c];
static int arr_d[size_d];
static int arr_e[size_e];

void merge_sort(int arr[],int first,int last);
void merge(int arr[], int first, int mid, int last);
void sorted();
void reversed();
void random();
void tim_merg();

void Radix_sort(int arr[], int numb);
void radix(int arr[], int numb, int exp);
int get_max(int arr[], int numb);
void tim_radix();

void Heap_sort(int arr[],int numb);
void heapify(int arr[],int numb,int i);
void swap(int *x,int *y);
void tim_heap();

void Insertion_sort(int arr[],int numb);
void tim_insertion();


int main(){

    char in[2];
    int choice=1;

    printf(" --- Welcome ---\n");
    do{

    printf("----------------------------\n");
    printf(" Enter the order you want to sort: \n");
    printf("1. Sorted\n");
    printf("2.Reversed\n");
    printf("3.Random\n");
    printf("4.To Exit \n");
    printf("===================================\n");
    printf("pleas chose one of option \n");
    scanf("%s",&in);
    choice=atoi(in);
    printf("\n");

    switch(choice){
    case 1:
    printf("                                    --- SORTED --- \n");
    printf("===================================================================================\n");
    printf("=    sort/n      =    1000    =   10000    =   100000   =   1000000  =   5000000  =\n");
    printf("===================================================================================\n");
    printf("=   Merge sort   =");
    sorted();
    tim_merg();
    printf("\n===================================================================================\n");
    printf("=   Radix sort   =");
    sorted();
    tim_radix();
    printf("\n===================================================================================\n");
    printf("=   Heap sort    =");
    sorted();
    tim_heap();
    printf("\n===================================================================================\n");
    printf("= Insertion sort =");
    sorted();
    tim_insertion();
    printf("\n===================================================================================\n");



        break;
    case 2:

        printf("                                    --- REVERSED --- \n");
        printf("===================================================================================\n");
        printf("=    sort/n      =    1000    =   10000    =   100000   =   1000000  =   5000000  =\n");
        printf("===================================================================================\n");
        printf("=   Merge sort   =");
        reversed();
        tim_merg();
        printf("\n===================================================================================\n");
        printf("=   Radix sort   =");
        reversed();
        tim_radix();
        printf("\n===================================================================================\n");
        printf("=   Heap sort    =");
        reversed();
        tim_heap();
        printf("\n===================================================================================\n");
        printf("= Insertion sort =");
        reversed();
        tim_insertion();
        printf("\n===================================================================================\n");
        break;
    case 3:
                printf("                                    --- RANDOM --- \n");
        printf("===================================================================================\n");
        printf("=    sort/n      =    1000    =   10000    =   100000   =   1000000  =   5000000  =\n");
        printf("===================================================================================\n");
        printf("=   Merge sort   =");
        random();
        tim_merg();
        printf("\n===================================================================================\n");
        printf("=   Radix sort   =");
        random();
        tim_radix();
        printf("\n===================================================================================\n");
        printf("=   Heap sort    =");
        random();
        tim_heap();
        printf("\n===================================================================================\n");
        printf("= Insertion sort =");
        random();
        tim_insertion();
        printf("\n===================================================================================\n");
        break;
    case 4:
         printf(" Thank you ...\n");
        break;
    default:
        printf("The number you entered dose not exist!!!\n ");
        break;

    }

    }while(choice!=4);

	return 0;
}

void sorted(){

    for(int i=0;i<size_a;i++)
        arr_a[i]=i;

    for(int i=0;i<size_b;i++)
        arr_b[i]=i;

    for(int i=0;i<size_c;i++)
        arr_c[i]=i;

    for(int i=0;i<size_d;i++)
        arr_d[i]=i;

      for(int i=0;i<size_e;i++)
        arr_e[i]=i;

}

void reversed(){

    int k=size_a;
    for(int i=0;i<size_a;i++){
        arr_a[i]=k;
        k--;
    }

    k=size_b;
    for(int i=0;i<size_b;i++){
        arr_b[i]=k;
        k--;
    }

    k=size_c;
    for(int i=0;i<size_c;i++){
        arr_c[i]=k;
        k--;
    }

    k=size_d;
    for(int i=0;i<size_d;i++){
        arr_d[i]=k;
        k--;
    }

     k=size_e;
    for(int i=0;i<size_e;i++){
        arr_e[i]=k;
        k--;
    }
}

void random(){

    for(int i=0;i<size_a;i++)
        arr_a[i]=rand();
    for(int i=0;i<size_b;i++)
        arr_b[i]=rand();

    for(int i=0;i<size_c;i++)
        arr_c[i]=rand();

    for(int i=0;i<size_d;i++)
        arr_d[i]=rand();

      for(int i=0;i<size_e;i++)
        arr_e[i]=rand();
}

// Merge sort:

void tim_merg(){

    double sort_time = 0.0;
    clock_t start = clock();

    merge_sort(arr_a,0,size_a-1);
    clock_t end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("    %.3f   =",sort_time);

	//10,000
    sort_time = 0.0;
    start = clock();

    merge_sort(arr_b,0,size_b-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);

	//100,000
    sort_time = 0.0;
    start = clock();

    merge_sort(arr_c,0,size_c-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);


	//1,000,000
	sort_time = 0.0;
    start = clock();

    merge_sort(arr_d,0,size_d-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("    %.3f   =",sort_time);

	//5,000,000
    sort_time = 0.0;
    start = clock();

    merge_sort(arr_e,0,size_e-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);
}

void merge_sort(int arr[],int first,int last){
	if (first<last) {
        int mid=first+(last-first)/2;

		merge_sort(arr,first,mid);
		merge_sort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
}

void merge(int arr[], int first, int mid, int last){

	int i, j, k;
	int n1= mid-first+1;
	int n2= last-mid;

	for (i = 0; i < n1; i++)
        temp_1[i] = arr[first + i];

	for (j = 0; j < n2; j++)
          temp_2[j] = arr[mid + 1 + j];

	i=j=0;
	k=first;
	while (i<n1 && j<n2){
		if (temp_1[i]< temp_2[j]) {
			arr[k]= temp_1[i];
			i++;
		}
		else {
			arr[k]= temp_2[j];
			j++;
		}
		k++;
	}

	while (i<n1) {
		arr[k] =  temp_1[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k]= temp_2[j];
		j++;
		k++;
	}
}

//Radix sort:

void tim_radix(){

    //1,000
  double sort_time = 0.0;
    clock_t start = clock();

    Radix_sort(arr_a,size_a-1);
    clock_t end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);

	//10,000
    sort_time = 0.0;
    start = clock();

    Radix_sort(arr_b,size_b-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);

	//100,000
    sort_time = 0.0;
    start = clock();

   Radix_sort(arr_c,size_c-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);


	//1,000,000
	sort_time = 0.0;
    start = clock();

    Radix_sort(arr_d,size_d-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("    %.3f   =",sort_time);

	//5,000,000
    sort_time = 0.0;
    start = clock();

    Radix_sort(arr_e,size_e-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("   %.3f    =",sort_time);
}

void Radix_sort(int arr[],int numb){
    int max = get_max(arr, numb);

    int exp;
    for (exp = 1; max / exp > 0; exp *= 10)
        radix(arr, numb, exp);
}

void radix(int arr[], int numb, int exp){

    int i,temp[10]={0};

    for (i = 0; i < numb; i++)
        temp[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        temp[i]+= temp[i-1];

    for (i = numb-1;i >=0;i--) {
        temp_3[temp[(arr[i]/exp)%10]-1]=arr[i];
        temp[(arr[i]/exp)%10]--;
    }

    for (i = 0; i < numb; i++)
        arr[i] = temp_3[i];
}

int get_max(int arr[], int numb){
    int max = arr[0];
    for (int i = 1; i < numb; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Heap sort:

void tim_heap(){

    //1,000
  double sort_time = 0.0;
    clock_t start = clock();

    Heap_sort(arr_a,size_a-1);
    clock_t end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);

	//10,000
    sort_time = 0.0;
    start = clock();

    Heap_sort(arr_b,size_b-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);

	//100,000
    sort_time = 0.0;
    start = clock();

   Heap_sort(arr_c,size_c-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);


	//1,000,000
	sort_time = 0.0;
    start = clock();

    Heap_sort(arr_d,size_d-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);

	//5,000,000
    sort_time = 0.0;
    start = clock();

    Heap_sort(arr_e,size_e-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);
}

void swap(int *x,int *y){
    int temp =*x;
    *x =*y;
    *y =temp;
  }

void heapify(int arr[],int numb,int i) {

    int max = i;
    int left_child= 2*i+1;
    int right_child=2*i+2;

    if(left_child< numb &&arr[left_child]> arr[max])
      max = left_child;

    if(right_child < numb && arr[right_child] > arr[max])
      max =right_child;

    if(max !=i) {
      swap(&arr[i],&arr[max]);
      heapify(arr,numb,max);
    }
  }

void Heap_sort(int arr[],int numb){

    for (int i=(numb/2-1);i>=0;i--)// 2/numb-1 : level order of tree
      heapify(arr,numb,i);

    for(int i=numb-1;i>=0;i--){
      swap(&arr[0],&arr[i]);
      // modify max heap
      heapify(arr,i,0);
    }
  }

//Insertion sort:

void tim_insertion(){

    //1,000
  double sort_time = 0.0;
    clock_t start = clock();

    Insertion_sort(arr_a,size_a-1);
    clock_t end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);

	//10,000
    sort_time = 0.0;
    start = clock();

    Insertion_sort(arr_b,size_b-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);

	//100,000
    sort_time = 0.0;
    start = clock();

   Insertion_sort(arr_c,size_c-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);


	//1,000,000
	sort_time = 0.0;
    start = clock();

    Insertion_sort(arr_d,size_d-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);

	//5,000,000
    sort_time = 0.0;
    start = clock();

    Insertion_sort(arr_e,size_e-1);
    end = clock();
    sort_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("  %.3f  =",sort_time);
}

void Insertion_sort(int arr[],int numb){
    int i,j,temp;
    for (i = 1; i < numb; i++) {
        temp = arr[i];
        j = i - 1;

        while(j>=0&& arr[j]>temp){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
