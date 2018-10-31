#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void heapify(int root, int a[], int n)
{
	int large = root;
	int left = 2*root +1;
	int right = 2*root+2;
	
	if(left<n && right<n)
	{
		if(a[right] > a[left])
			large = right;
		else
			large = left;
	}
	
	if(a[large] < a[root])
		large = root;		
		
	if(large != root)
	{
		swap(a[large],a[root]);
		heapify(large,a,n);
	}
}


void createHeap(int a[], int n)
{
	int k =n/2-1;
	while(k != -1)
	{
		heapify(k,a,n);
		k--;
	}
}

void Heapsort(int a[], int n)
{
	int b[n];
	int element;
	int root = 0;
	createHeap(a,n);
	for(int i=n-1; i>=0; i--)
	{
		b[i] = a[root];
		swap(a[root],a[i]);
		heapify(root,a,i-1);
		createHeap(a,i);
	}

	cout<<"\nAfter Sorting: ";
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[] = {9,17,14,43,10,91,8,5,7,6,14,1,3,2,4};
	int size = sizeof(a)/sizeof(int);
	
	cout<<"Before Sorting: ";
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";

	Heapsort(a, 15);

}

