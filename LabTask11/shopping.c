#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Constants
#define SIZE 128
#define TRUE 1
#define FALSE 0

//Typedefs
typedef char String[SIZE];

typedef struct item
{
    String item_name;
    double price;
    int quantity;
    double total;
}item;

typedef item *list;

//Function prototypes
void printList(list list,int size);
int addItems(list *list);
list reAllocate(list list, int size);
int compare(const void *, const void *);

int main(void)
{
    
    int size;
    list groc_list = NULL; 
    size = addItems(&groc_list);
    qsort(groc_list,size,sizeof(item),compare);
    printList(groc_list,size);
    free(groc_list);
    
    return(EXIT_SUCCESS);
}


void printList(list list, int size)
{
    int index = 0;
    double totalPrice = 0;

    for(; index < size; index++)
    {
        printf("%-10s %-10d $%-.2lf\n",list[index].item_name,list[index].quantity,list[index].total);
        totalPrice += list[index].total;
    }
    
    printf("\n-----------------------------\n");
    printf("Total \t\t\t");
    printf("$%-.2lf\n",totalPrice);
}


int addItems(list *List)
{
    int index = 0;
    int capacity = 1;
    String input; 
	list temp = NULL;
	*List = malloc(sizeof(item));
    do { 
            if(index == capacity) 
            {
				capacity *= 2;
                temp = realloc(*List, capacity * sizeof(item));
				if(temp == NULL && index > 1)
				{
					printf("ERROR: Failed to reallocate");
					exit(EXIT_FAILURE);
				}
				*List = temp;
            }
            item newItem;
            printf("Enter item information (\"exit\" to exit)\n");
            printf("item %d: ", index+1);
            fgets(input,SIZE,stdin);
            input[strlen(input)-1] = '\0';
            if(!strcmp(input,"exit"))
            {
                break;
            }
            strcpy(newItem.item_name,input);
            printf("price: ");
            scanf("%lf",&newItem.price);
            printf("quantity: ");
            scanf("%d",&newItem.quantity);
            newItem.total = newItem.price * newItem.quantity;
            fgetc(stdin);
            (*List)[index++] = newItem;
    } while(TRUE);

    printf("\n");
   return index; 
}

int compare(const void* x, const void* y)
{
    double l, r;
    l = ((item *)x)->total;
    r = ((item *)y)->total;
    return(l - r);
}
