#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define SIZE 128
#define LOG_SIZE 1
#define EXIT 0
#define SUCCESS 1

//Typedefs
typedef char String[SIZE];
typedef enum {mammal,insect,bird,fish,error} animalType;

typedef struct 
{
  String name;
  double size;
  animalType type; 
}speciesRecord;

typedef speciesRecord speciesLog;

int size = LOG_SIZE;

//Function Prototypes
int inputRecord(speciesRecord *record);
void * Malloc(size_t Size);
void printLog(speciesLog *log);
void addNewSpecies(speciesLog *log);
animalType getType(String type);
char* printType(animalType type);

int main(void)
{
  speciesLog *log = (speciesLog *)Malloc(size * sizeof(speciesRecord));
  addNewSpecies(log);
  printLog(log);
  free(log);
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


int inputRecord(speciesRecord *record)
{
  String input;
  printf("Enter animal information('exit' to exit)\n");
  printf("What is the name : ");
  scanf("%s",input);
  if(strcmp(input,"exit"))
  {
    strcpy(record->name,input);
  }
  else
  {
    return EXIT;
  }
  printf("What is the size : ");
  scanf("%lf",&record->size);
  printf("What is the type : ");
  scanf("%s",input);
  record->type = getType(input);
  return SUCCESS;
}

animalType getType(String type)
{
    if (!strcmp(type,"mammal")) {
        return(mammal);
    }
    if (!strcmp(type,"insect")) {
        return(insect);
    }
    if (!strcmp(type,"bird")) {
        return(bird);
    }
    if (!strcmp(type,"fish")) {
        return(fish);
    }
    return(error);
}

void addNewSpecies(speciesLog *log)
{
  int index = 0;
  do
  {
    if (index > 0)
    {
      size++;
      log = (speciesLog *)realloc(log,size * sizeof(speciesRecord));
    }
  } while (inputRecord(&log[index++]));
  
  return;
}

char* printType(animalType type)
{
  switch (type)
  {
  case mammal:
    return("mammal");
    break;
  case insect:
    return("insect");
  case bird:
    return("bird");
  case fish:
    return("fish");
  default:
    return("Error");
    break;
  }
}

void printLog(speciesLog *log)
{
  printf("The following new species were found:\n");
  for(int i = 0; i < size-1; i++)
  {
    printf("%s\thas size\t%.2lf\tand is a %s\n",log[i].name,log[i].size,printType(log[i].type));
  }
}