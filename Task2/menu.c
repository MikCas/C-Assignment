#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "functions.h"


int MakeHash() {
    int input;//holds the input of the user
    int rows;
    int columns;

    switch (input) {
        case 1:

            printf("A table of dimensions 2 by 2 is made");
            rows = 2;
            columns = 2;
            break;

        case 2:
            printf("A table of dimensions 2 by 2 is made");
            rows = 2;
            columns = 2;
            break;

        case 3:
            printf("A table of size 2 is made");
            rows = 2;
            break;

        default:
            printf("Invalid input");
            break;
    }
}

int addHash(){
    int input;

    switch(input){
        case 1:
            add(hash, rows, columns, used, size, key, value, hashIndex);
            break;

        case 2:
            add(hash, rows, columns, used, size, key, value, hashIndex);
            break;

        case 3:
            insertElement(hashP, key, value, rows, myIndex, indexHold);
            break;

        default:
            printf("Invalid input");
            break;

    }
}

void searcHash() {
    int input;

    switch (input) {
        case 1:
            search(hash, rows, columns);
            break;

        case 2:
            search(hash, rows, columns);
            break;

        case 3:
            searchC(hashP, key, rows, myIndex, indexHold);
            break;

        default:
            printf("Invalid input");
            break;


    }
}

void deleteHash(){
    int input;

    switch(input){
        case 1:
            deleteElement(hash, rows, columns);
            break;

        case 2:
            deleteElement(hash, rows, columns);
            break;

        case 3:
            deleteElementC(hashP, key, rows, myIndex, indexHold);
            break;

        default:
            printf("Invalid input");
            break;

    }

}

void displayHash() {

    int input;

    switch (input) {
        case 1:
            showAll(hash, rows, columns);
            break;

        case 2:
            showAll(hash, rows, columns);
            break;

        case 3:
            showAllC(hashP, rows);
            break;

        default:
            printf("Invalid input");
            break;

    }
}
