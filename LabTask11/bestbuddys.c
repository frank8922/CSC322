#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Program specifications
    * Each persons name must be stored in node of linked list
    * Each node of linked list must contain (only) 
    * - the persons name. 
    * - a pointer to node for best buddy.
    * - a pointer to the next node in list.
    * Before program completes it must explicitly free the malloced memory.
*/

//Constants
#define SIZE 128

//Typedefs
typedef char String[SIZE];

/*
    Struct to hold node of linked list
    holds pointers to next buddy (also a node)
    and holds pointers to next element in linked list (also a node)
*/
typedef struct Node 
{
    String name; 
    struct Node *bestbuddy;
    struct Node *next;
}Node;

typedef Node *NodePtr; //typedef for a node pointer

//Functions prototypes
void printbuddies(NodePtr head);
NodePtr inputInfo();
void * Malloc(size_t Size); 
void inputBestBuddy(NodePtr head);
void Free(NodePtr head);

int main(void)
{
    NodePtr head = NULL; //Head of linked list, initalized to NULL;
    head = inputInfo(); //Call to input new users to linked list
    inputBestBuddy(head); //Call to input buddy to linked list
    printbuddies(head); //Prints all the buddies
    Free(head); //Frees all the allocated memory locations
    return(EXIT_SUCCESS);
}

void * Malloc(size_t Size) {

    void * Memory;

    if ((Memory = malloc(Size)) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    } else {
        return(Memory);
    }
}

/*
    Function to input new users to the list
*/
NodePtr inputInfo() 
{
    NodePtr head = NULL; //temp var to hold head of linked list
    NodePtr person; //temp var to hold new person to be added to linked list
    int empty = 1; //sential variable to end loop
    while(empty != 0)
    {
        person = Malloc(sizeof(Node)); //allocate space for new person
        printf("Enter nation name : ");
        scanf("%s",person->name); //get user input
        if(strcmp(person->name,"")) //check if user input blank i.e they pressed CTRL-D
        {
            person->next = head; //assign the next location in list to old postion of head
            head = person; //assign newly added person to old postion of head 
        }
        else //when user input is blank (i.e they pressed CTRL-D)
        {
            free(person); //free up previously allocated memory for person
            person = NULL; //assign location to null
            empty = 0; //set sential to zero to exit loop
        }
    }
    printf("\n");
    
    return head; //return the head of the linked list with all the people
}

/*
    Function to add best buddy to each node in linked list
    takes the head of linked list as parameter
*/
void inputBestBuddy(NodePtr head)
{
    NodePtr bestbuddy; //temp var to hold the buddy

    while(head != NULL) //while the linked list isn't empty
    {
        bestbuddy = Malloc(sizeof(NodePtr)); //allocate space for the buddy
        head->bestbuddy = bestbuddy; //set the heads buddy to the newly allocated buddy
        printf("Enter best ally name for %s : ", head->name);
        scanf("%s",head->bestbuddy->name); //get the input and assign it to the newly created budddy
        head = head->next; //move the linked list forward by one node
    }

    return;
}

/*
    Function to free all allocated memory
    takes the head of the linked list as parameter
*/
void Free(NodePtr head) 
{
    NodePtr freePtr; //temp var to hold the node to be freed
    
    while(head != NULL) //While list contains elements
    {
        freePtr = head; //assign the head of the list to temp var
        head = head->next; //move list forward by one node
        free(freePtr->bestbuddy); //free the best buddy first
        free(freePtr); //free the node in the list
        freePtr = head; //temp var now holds next element
    }
    return;
}

/*
    prints out all the buddies of each element in the linked list
    takes the head of the linked list to be printed
*/
void printbuddies(NodePtr head)
{
    while(head != NULL) //while the list contains entries
    {
        printf("The best ally of %s is %s\n",head->name,head->bestbuddy->name);
        head = head->next; //move list forward by one node
    }
}