#include <stdio.h>
#include "menu.h"

int main() {
    int input;

        switch (input) {

            case 1:

                MakeHash();
                break;

            case 2:
                addHash();

                break;

            case 3:
                searcHash();



                break;

            case 4:
                deleteHash();
                break;

            case 5:
                displayHash();

                break;

            case 6:

                break;

            case 7:
                printf("Exit");
                break;

            default:
                printf("Invalid input");


        }

        while (input != 7);
    }








