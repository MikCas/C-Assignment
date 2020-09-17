#include<stdio.h>
#include <ctype.h>
#include <string.h>//so as to be able to use strstr()


int replace(char *readLinePar, char *findPar, char *replacePar, int lengthPar);
int replaceWord(char *readLinePar, char storeWordPar[], char *replacePar, int lengthPar);
//since we are dealing with 3 strings we are going to need 3 pointers to each string


int main(){

    char textFile[20];//where the user will input the text file they want to read
    FILE *fPointer;//the pointer the file
    char readLine[150];//this array will hold the text of the file
    int letterCount = 0;//used to keep track of letters in the line
    int lineLength;//used to hold the length of the line
    int i;//counter for loop
    int j;
    int k;
    int input;//used to get input on whether to autocorrect or not
    char firstWord[15];//
    char storeWord[15];//used to hold the long word without spaces

    printf("This program will arrange any typing errors the user has\n");

    printf("\nPlease input the text file you want to read\n");
    scanf("%s", textFile);
    //the user here will enter which file they want to read

    fPointer = fopen(textFile, "a+");//the file is set to a+ as we want to read and append the file
    //the file here is opened and is set to be read


    while(fgets(readLine, 150, fPointer)){//until the file has not yet reached the end of file
        //fgets(readLine, 150, fPointer);//read each character which fPointer is accessing into readLiner
        //all the characters of the file pointed to by fPointer are put read into the string readLine

        lineLength = strlen(readLine);
        //the length of the current line is calculated

        printf("Current line: ");
        puts(readLine);

        if (strstr(readLine, " ,")){//function used so as to find the required string within the the read string
            printf("A comma has a space before it\n");

            replace(readLine, " ,", ",", lineLength);

            printf("Error has been corrected");
            puts(readLine);
        }

        else if(strstr(readLine, " .")){
            printf("A fullstop has a space before it\n");

            replace(readLine, " ,", ",", lineLength);

            printf("Error has been corrected");
            puts(readLine);
        }

        else if(strstr(readLine, "  ")){
            printf("There is more than one space present\n");


            replace(readLine, "  ", " ", lineLength);
            //error is corrected but the loop iterates

            printf("Error has been corrected\n");
        }
            //the above three conditions check if the line has a a space and comma, space and fullstop or multiple spaces

        else{
            printf("No error is found involving a space, comma or multiple spaces in this line\n");
        }

        for(i = 0; i < lineLength; i++){

            if(isalpha(readLine[i])){

                letterCount++;

                storeWord[i] = readLine[i];
                //each character is being stored in an array character by character until all the 12 characters are stored

            }
            //if the ith element in readLine is a letter then increment letterCount

            if(letterCount > 11){//words which are 12 characters are rare so only words which are 11 characters or less are taken into account
                printf("stored wors is %s\n", storeWord);
                printf("A word which has no space is found\n");
                printf("Would you like to change the word (1 = yes/ 0 = no)\n");
                scanf("%d", &input);

                if(input == 1){

                    printf("Input the first word");
                    scanf("%s", firstWord);

                    replaceWord(readLine, storeWord, firstWord, lineLength);


                }

                else if(input == 0){
                    printf("The word will not be changed");
                }
            }
            //if the amount of consecutive letters without a space is equal to twelve, the user can change the word

        }

    }

    fclose(fPointer);

    return 0;

}



int replace(char *readLinePar, char *findPar, char *replacePar, int lengthPar){
    int i,j, length;
    //i and j are used as counters while length is used to hold the number of characters in a line

//while(readLinePar != '\0'){
//keep on going until the end of the line

    for(i = 0; i < lengthPar; i++){
//for each character in the line
        if(readLinePar[i] == findPar[0]){
//if the ith character in the line is the same as the first character in the string to replace
            if(readLinePar[i+1] == findPar[1]){
                //if the folowing character in the line is equal to the second character in the string to replace

                printf("The old line is %s\n", readLinePar);

                readLinePar[i] = replacePar[0];
                //the old word is printed and the ith character of the line is replaced with the character to replace it

                for(j = i + 1; j < lengthPar; j++){
                    readLinePar[j] = readLinePar[j + 1];
                }
                /*
                 the following characters are then replaced with the next character after them since
                 the error is 2 letters long and the replacement is only one character
                */
                printf("The replaced word is %s\n", readLinePar);
                //put this string back in the file.

            }
        }
    }


    return 0;
}

int replaceWord(char *readLinePar, char storeWordPar[], char *replacePar, int lengthPar){
    int i,j;
    //i and j are used as counters while length is used to hold the number of characters in a line
    int countLine = 0;
    //used to keep track of characters, this is so as to know how long the character is

//while(readLinePar != '\0'){
//keep on going until the end of the line

    for(i = 0; i < lengthPar ; i++){
//for each character in the line
        if(readLinePar[i] == storeWordPar[i]){
            //if the ith character in the line is the same as the first character in the string to replaced
            countLine++;
            //count will get incremented eachtime the character in readLine is equal to
        }

        if(countLine == strlen(storeWordPar)){
            //when the length of the long word is equal to the countLine, we know that i is equal to the last word of the long word
            for(j = i - strlen(storeWordPar); j < lengthPar; i++){

                readLinePar[j] = replacePar[0];

            }

        }
    }

    printf("The replaced word is %s", readLinePar);
    return 0;
}
