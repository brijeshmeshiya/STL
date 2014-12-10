#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class heap
{
private:
int insertionpoint;
int size;
public :
int *array;
heap();
void createarray(int );
void insert(int );
};

heap :: heap()
{
array = NULL;
insertionpoint=0;
size=0;
}

void heap :: createarray(int passed_size)
{
size = passed_size;
if(size>0)
{
free(array);
insertionpoint=0;
array = (int  *) malloc(size*sizeof(int));
for(int i=0;i<size;i++)
{
*(array+i)=0;
}
return ;
}
return ;
}

void heap :: insert(int element)
{
if(insertionpoint<size)
{
*(array+insertionpoint) = element;
insertionpoint++;
}
else
{
// Use array doubling method to allocate more space and then copying previous array into new one
int *temp;
temp = (int *) malloc (size*2*sizeof(int));
for(int i=0;i<size;i++)
{
*(temp+i) = *(array+i);
}
array = temp;
size=size*2;
if(insertionpoint<size)
{
*(array+insertionpoint) = element;
insertionpoint++;
}
}
}


// function to check that this library is accessible or not
void check()
{
cout<<"heep.h = OK"<<endl;
return ;
}

// convert passed index to maximum and its ancestor
bool max_heapify(int *array,int array_size,int element_index)	// Element with starting index = 1
{
if(element_index>array_size)
{
return false;
}
else
{
int maximum=*(array+element_index);
int side = 0 ;	// side = 1 => left || side = 2 => right
if(element_index*2<=array_size && *(array+element_index*2)>maximum)
{
maximum = *(array+element_index*2);
side = 1;
}
if(element_index*2+1<=array_size && *(array+element_index*2+1)>maximum)
{
side = 2;
maximum = *(array+element_index*2+1);
}
if(side!=0)
{
int temp;
temp = *(array+element_index*2+side-1);
*(array+element_index*2+side-1) = *(array+element_index);
*(array+element_index) = temp;
max_heapify(array,array_size,element_index*2+side-1);
}
return true;
}
}

//convert normal array to max heap with starting index = 0
bool max_heap(int *array,int size)
{
int temp[size+1];
for(int i=1;i<size+1;i++)	// converting to index = 1 
{
temp[i]=*(array+i-1);
}
for(int i=(size/2)+1;i>=1;i--)	// Converting to max heap
{
max_heapify(temp,size,i);
}
for(int i=1;i<size+1;i++)	// Copying array and converting back to index = 0
{
*(array+i-1)=temp[i];
}
return true;
}

// function lazy min heap convert array to min heap using max_heapify function
bool lazy_min_heap(int *array,int size)
{
int temp[size+1];
for(int i=1;i<size+1;i++)       // converting to index = 1 
{
temp[i]=-*(array+i-1);
}
for(int i=(size/2)+1;i>=1;i--)  // Converting to max heap
{
max_heapify(temp,size,i);
}
for(int i=1;i<size+1;i++)       // Copying array and converting back to index = 0
{
*(array+i-1)=-temp[i];
}
return true;
}

bool min_heapify(int *array,int array_size,int element_index)	// min_heapify function with index = 1
{
if(element_index>array_size)
{
return false;
}
else
{
int minimum = *(array+element_index);
int side = 0;
if(element_index*2<=array_size && *(array+element_index*2)<minimum)
{
side=1;
minimum = *(array+element_index*2);
}
if(element_index*2+1<=array_size && *(array+element_index*2+1)<minimum)
{
side=2;
minimum = *(array+element_index*2+1);
}
if(side!=0)
{
int temp;
temp = *(array+element_index*2+side-1);
*(array+element_index*2+side-1) = *(array+element_index);
*(array+element_index) = temp;
min_heapify(array,array_size,element_index*2+side-1);
}
return true;
}
}

// convert array (index = 0) to min heap (index = 0)
bool min_heap(int *array,int array_size)
{
int temp[array_size+1];
for(int i=1;i<array_size+1;i++)
{
temp[i] = *(array+i-1);
}
for(int i=(array_size/2)+1;i>=1;i--)
{
min_heapify(temp,array_size,i);
}
for(int i=1;i<array_size+1;i++)
{
*(array+i-1) = temp[i];
}
return true;
}

// Print heap 
void print_heap(int *array,int array_size)
{
int level = 0;
while(array_size>pow(2,level))
{
level++;
}
int counter=0,before=0,after=0;
for(int i=0;i<level;i++)
{
after =  (before -pow(2,(level-i-1))*3 ) * 2-3;
before = pow(2,(level-i-1))*3;
//after = before;
for(int j=0;j<pow(2,i);j++)
{
int k=0;
if(j==0)
{
while(k<before)
{
cout<<" ";
k++;
}
}
if(counter>=array_size)
	break;
cout<<setw(3)<<*(array+counter);
counter++;
k=0;
while(k<after)
{
cout<<" ";
k++;
}
}
cout<<endl;
}
return ; 
}

// sort using max_heap property

void sort_heap_max(int *array,int array_size)
{
if(array_size>0)
{
max_heap(array,array_size);
int temp_size = array_size;
int temp[array_size+1];
for(int i=0;i<array_size;i++)
{
temp[i+1] = *(array+i);
}
for(int j=array_size;j>=2;j--)
{
int tmp = temp[j];
temp[j] = temp[1];
temp[1] = tmp;
max_heapify(temp,j-1,1);
}
for(int i=0;i<array_size;i++)
{
*(array+i) = temp[i+1];
}
}
return ;
}

// This function sorts an array using min_heapify()

void sort_heap_min(int *array,int array_size)
{
if(array_size>0)
{
min_heap(array,array_size);
int temp[array_size+1];
for(int i=0;i<array_size;i++)
{
temp[i+1] = *(array+i);
}
for(int j=array_size;j>=2;j--)
{
int tmp = temp[j];
temp[j] = temp[1];
temp[1] = tmp;
min_heapify(temp,j-1,1);
}
for(int i=0;i<array_size;i++)
{
*(array+i) = temp[i+1];
}
}
return ;
}

