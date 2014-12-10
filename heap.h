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
