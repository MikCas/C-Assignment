#include<stdio.h>
#include <string.h>

char textFile[20];//variable will hold the text file containg program
FILE * fPointer;//pointer to the file
char readLine[150]; //this will hold the text of the file

int main(){
    printf("Please input the text file you want to read\n");
    scanf("%s", textFile);
    //user here inputs the text file the user wants to be read

    fPointer = fopen(textFile,"r"); //"r" is used here since the file is only going to be read
    //the file is opened

    if(fPointer){
        //if the pointer points to somewhere other than null

        while(fgets(readLine, 150, fPointer)){
            //iterate line by line until the end of the file is reached
            //each line is stored in the array readLine

            if (strstr(readLine, "#include<stdio.h>" )) {
                //if "#include<stdio.h>" is found in the file then say that this is a c program
                printf("This is a c program\n");
                break;

                /*
                The program only needs to check the first line since #include<stdio.h>
                is written on the first line, so break is used to stop further iterations of each line
                */
            }

            else if(strstr(readLine, "<html>")){
                //if the first html string is found "<html" do another while loop to check for the other HTML string on another line
                while(fgets(readLine, 150, fPointer)){
                    //while iterating through the text file again check if the second html string is in a line inisde the text file

                    if(strstr(readLine, "</html>")){
                        //if the second string is found print that this is an html file

                        printf("This is an HTML program\n");
                        //the user here is prompted that this program is an html program

                    }

                }
            }

            else{
                printf("This is another type of file apart from C or HTML\n");
                //user is promted that this program is another type of file
            }
        }

        fclose(fPointer);//data is reallocated back to the heap after use

    }

    else{
        printf("This file does not exist\n");
        //if fPointer points to nothing then it is empty and so the file the user entered does not exist
    }

    return 0;
}
