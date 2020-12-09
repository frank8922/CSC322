//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

void ReadIntByPointer(int *IntPointer);
//-----------------------------------------------------------------------------
int main(void) {

    int AnInt; //holds value
    int *PointAtInt; //address

    AnInt = 27;
    printf("AnInt = %d\n\n",AnInt);
    printf("anInT Mem address: %p\n",&AnInt);
    printf("PointAtInt address %p\n",PointAtInt);
    PointAtInt = &AnInt; //point to anInt
    ReadIntByPointer(PointAtInt);
    printf("AnInt = %d\n\n",AnInt);

    printf("anInT Mem address: %p\n",&AnInt);
    printf("PointAtInt address %p",PointAtInt);
    ReadIntByPointer(&AnInt);
    printf("AnInt = %d\n\n",AnInt);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void ReadIntByPointer(int *IntPointer) {

    printf("Enter integer to assign by pointer   : ");
    scanf("%d",IntPointer);
    printf("Mem address Intptr: %p\n",IntPointer);

}
//-----------------------------------------------------------------------------
