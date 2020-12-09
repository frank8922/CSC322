
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define SIZE 128
#define LOG_SIZE 1

//Typedefs
typedef char String[SIZE];
typedef enum {mammal,insect,bird,fish,error} animalType;

typedef struct 
{
  String name;
  double size;
  animalType type; 
}speciesRecord;

typedef speciesRecord *speciesLog;

//Function Prototypes
int inputRecord(speciesRecord *record);
speciesRecord newRecord();
void * Malloc(size_t Size);
void printLog(speciesLog log,int size);
int addNewSpecies(speciesLog log);
animalType getType(String type);
char* printType(animalType type);


int main(void)
{
    speciesLog logbook = Malloc(sizeof(speciesRecord));
    int index = 0;
    int size = LOG_SIZE;
    do
    {
      if(index == size)
      {
        size *= 2;
        logbook = realloc(logbook, size * sizeof(speciesRecord));
      }
      logbook[index] = newRecord();
    } while (strcmp(logbook[index++].name,"exit") != 0);
    size = index-1;
    printLog(logbook,size);
    free(logbook);
    

    return(EXIT_SUCCESS);
}

speciesRecord newRecord()
{
  String input;
  speciesRecord record; 
  printf("Enter animal information('exit' to exit)\n");
  printf("What is the name : ");
  scanf("%s",input);
  if(!strcmp(input,"exit"))
  {
      strcpy(record.name,input);
      record.size = EOF;
      record.type = error;
      return record;
  }
  else
  {
    strcpy(record.name,input);
    printf("What is the size : ");
    scanf("%lf",&record.size);
    printf("What is the type : ");
    scanf("%s",input);
    record.type = getType(input); 
    printf("%s\thas size\t%.2lf\tand is a\t%s\n",record.name,record.size,printType(record.type));
  }
  
  
  return record;
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

void printLog(speciesLog log, int size)
{
  printf("The following new species were found:\n");
  for(int i = 0; i < size; i++)
  {
    printf("%s\thas size\t%.2lf\tand is a\t%s\n",log[i].name,log[i].size,printType(log[i].type));
  }
}