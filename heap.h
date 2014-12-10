#include <cstdlib>
#include <iostream>

using namespace std;

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
for(int i=(array_size/2);i>=1;i--)
{
min_heapify(temp,array_size,i);
}
for(int i=1;i<array_size+1;i++)
{
*(array+i-1) = temp[i];
}
return true;
}
