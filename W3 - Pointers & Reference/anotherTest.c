// C program to swap two values 
// without passing pointer to 
// swap function. 
#include <stdio.h> 

void swap(int* a, int* b) 
{ 
int temp; 
temp = *a; 
*a = *b; 
*b = temp; 
} 

// Driver code 
int main() 
{ 
int a = 10, b = 20; 
printf("Values before swap function are: %d, %d\n", 
		a, b); 
swap(&a, &b); 
printf("Values after swap function are: %d, %d", 
		a, b); 
return 0; 
}
