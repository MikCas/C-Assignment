#include <stdio.h>
#include <stdlib.h>

int *foo(int *value){
//this function takes an intger pointer variable as a parameter and returns another integer pointer variable

    printf("add input\n");
    scanf("%d", &value);
    //the user is prompted to enter a value where each value entered is put in the address of each variable

    return value;
}

int view_stack_frame(int* valueA, int* valueB, int* valueC){
    /*
    the function takes 3 variables from the caller function and inputs them into a functions
    the function creates a table
    */

    int i;//variabel used for row counter
    int j;//variable used for columns counter

    int *ret1 = foo(valueA);
    int *ret2 = foo(valueB);
    int *ret3 = foo(valueC);
    //3 variables are created to hold the return value of the foo function each with a different parameter input

    int holdRet[3];
    holdRet[0] = ret1;
    holdRet[1] = ret2;
    holdRet[2] = ret3;
    //an array is created to hold the 3 values
    //the variables are casted as integers since the variables are initiailaised as pointers and so cannot be put inside an array


    printf("Variable address|    Variable value|\n");
    printf("----------------------------------- \n");
//the heading of the table of the stack frame

    for(i= 0; i < 3; i++){//null elements were present so 10 were removed to remove them.

        for(j = 0; j <= 1; j++){

            if(j==0){
                printf("     %p\t|", &holdRet[i]);
                //printf("\t%p\t| \t",&variables[i]);
            }

            else if(j==1){
                printf("         %d", holdRet[i]);
                //printf("\t%d\t| \t",variables[i]);

            }

        }
        printf("\n");
    }

   //the table here is created as requested in the question
    return 0;
}




int main(){
    int a;
    int b;
    int c;
    //3 variables are declared in the main which will be initialised in the functions

    view_stack_frame(&a, &b, &c);
    //addresses are inputted into the foo function so



    return 0;
}
