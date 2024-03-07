#include <stdio.h>

int main(void)
{
    /* Pointer = a 'variable-like' references that holds a MEMORY ADDRESS to another variable, array, etc.
    Some tasks are performed more easily with pointers.
    * = indirection operator (value at address) */

    int age = 21;
    int *pAge = &age;       // Alamatnya disimpen
    *pAge = 3;              // isi dari alamat yang sudah disimpan akan diganti

    printf("Address of age          : %p\n", &age);
    printf("Value of age            : %d\n", age);

    printf("Value of pAge           : %p\n", pAge);
    printf("Value at stored address : %d\n", *pAge);

    printf("Size of age             : %d bytes\n", sizeof(age));
    printf("Size of pAge            : %d bytes\n", sizeof(pAge));

    return 0;
}