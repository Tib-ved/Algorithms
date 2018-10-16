#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

 
//top down min-heapify in order of O(log(n))
void min_heapify(int A[], int i, int maxHeapSize){	//resolves only the level i and its child   
	int smallest;
	int left = 2*i;	//left sub-tree
	int right = 2*i + 1;	//right sub tree
	if(left <= maxHeapSize && A[left] < A[i]){	
		smallest = left;
	}
	else smallest = i;
	if(right <= maxHeapSize && A[right] < A[smallest]){
		smallest = right;
	}
	
	if(smallest != i){
		swap(&A[smallest], &A[i]);
		min_heapify(A,smallest,maxHeapSize);
	}
}
//bottom up level by level construction in order of O(n)
void build_minheap(int A[],int maxHeapSize){
	int i;
	for(i = maxHeapSize/2; i>=1; i-- ){	
		min_heapify(A,i,maxHeapSize);
	}
}
void heapsort(int A[],int maxHeapSize){
	int i;
	int N = maxHeapSize;
	build_minheap(A,maxHeapSize);
	for(i = N; i>=2;i--){
		swap(&A[i],&A[1]);
		min_heapify(A,1,--N);
	}
}
void removify(int A[],int i,int* maxHeapSize){
	if(i > *maxHeapSize){
		printf("index out of Heap size\n");
		return;
	}
	swap(&A[i],&A[*maxHeapSize]);
	*maxHeapSize -= 1;	//decrease the length of Heap
	min_heapify(A,i,*maxHeapSize);
}
	
	
int main(){
	int i;
	int *A;
	int r;
	int maxHeapSize ;
	printf("Output Maximum heap Size\n");
	scanf("%d",&maxHeapSize);
	A = (int*)malloc(sizeof(int)*maxHeapSize);
	
	printf("Input Array: \n");
	for(i = 1;i<=maxHeapSize;i++){
		scanf("%d",&A[i]);
	}
	
	build_minheap(A,maxHeapSize);
//	heapsort(A,maxHeapSize);
	for(i = 1;i<=maxHeapSize;i++){
		printf("%d ",A[i]);
	}
	printf("Input index to remove: ");
	scanf("%d",&r);
	removify(A,r,&maxHeapSize);
	printf("New Heap: \n");
	for(i = 1;i<=maxHeapSize;i++){
		printf("%d ",A[i]);
	}
	
	return 0;
}
