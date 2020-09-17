#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stdio.h>

FILE *fPointer;
struct arrayElement {
    struct node *nodeElement;
    int count;
};


struct node {
    char key[20];
    char value[20];
    struct node *next;
};

typedef struct{

    char key[20];
    char value[20];

} element;

int input;
int rows;
int columns;
int i;
int j;
int hashIndex;
char key[20];
char value[20];
int used = 0;
int size;
int myIndex;
int indexHold;
element ***hash;
struct arrayElement *hashP;



int hashfunction(char *keyPar, int rowsPar, int hashIndexPar);
int add(element ***hashPar, int rowsPar, int columnsPar, int usedPar, int sizePar, char *userKeyPar, char *userValuePar, int hashIndexPar);
int showAll(element ***hashPar, int rowsPar, int columnsPar);
int deleteElement(element ***hashPar, int rowsPar, int columnsPar);
int search(element ***hashPar, int rowsPar, int columnsPar);
void saveHash(FILE *fPointerPar, element ***hashPar, int rowsPar, int columnsPar);
void loadHash(FILE *fPointerPar);
struct node *generateNode(char keyPar[20], char valuePar[20]);
int hashFunction(char keyPar[20], int rowsPar, float indexPar, int indexHoldPar);
void insertElement(struct arrayElement * hashPar, char keyPar[20], char valuePar[20], int rowsPar, float indexPar, int indexHoldPar);
void showAllC(struct arrayElement * hashPar, int rowsPar);
void searchC(struct arrayElement *hashPar, char keyPar[20], int rowsPar, float indexPar, int indexHoldPar);
void saveHashC(FILE *fPointerPar,struct arrayElement *hashPar, int rowsPar) ;
void deleteElementC(struct arrayElement *hashPar, char keyPar[20], int rowsPar, float indexPar, int indexHoldPar);
void loadHash (FILE *fPointerPar);


#endif