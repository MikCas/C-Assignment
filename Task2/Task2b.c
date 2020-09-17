#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    char key[20];
    char value[20];

} element;


int hashfunction(char *keyPar, int rowsPar, int hashIndexPar);//The hash function in the form of the hashfunction which accepts the key as a parameter
int add(element ***hashPar, int rowsPar, int columnsPar, int usedPar, int sizePar, char *KeyPar, char *ValuePar, int hashIndexPar);
int showAll(element ***hashPar, int rowsPar, int columnsPar);
int deleteElement(element ***hashPar, int rowsPar, int columnsPar);
int search(element ***hashPar, int rowsPar, int columnsPar);
void loadHash (FILE *fPointerPar);
void saveHash(FILE *fPointerPar, element ***hashPar, int rowsPar, int columnsPar);


int main(){
    int input;//variable used to obtain user input
    int rows;//variable which holds rows of hashtable
    int columns;//variable which holds columns of hashtable
    int i;//counters
    int j;
    int hashIndex;
    char key[20];//buffer variable used to hold the value of the key before placing it in the dyanmic array
    char value[20];//buffer variabel used to hold the value of the key-value pair value before placing it in the dyanmic array
    //hash space is fully parameterizable
    //number of collisions dependant on user input of hash spaces
    int used = 0;;//variable to keep track of used spaces in the hash table
    int size;//variable to hold the size of the 2d array

    FILE *fPointer;




    printf("Enter the amount of rows you want initially\n");
    scanf("%d",&rows);

    printf("\nEnter the amount of columns you want initially\n");
    scanf("%d",&columns);

    printf("\nA table of %d rows and %d columns will be built\n", rows, columns );

    size = rows*columns;
    printf("\narea of hash table is %d\n", size);

    element ***hash;
// allocate the 2d array hash

    hash = (element***)calloc(rows, sizeof(element **));//memory is allocated for the amount of rows in the hashtable each with the size of a char pointer
//all elements are intiialised+ to 0
    for(i = 0; i < rows; i++){
        hash[i] = (element **)calloc(rows, sizeof(element*));//memory is allocated to each row as the amount of the columns where is memory location is the zise of char
        for(j = 0; j < columns; j++){
            hash[i][j] = (element *)calloc(columns, sizeof(element));
        }
    }

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            strcpy(hash[i][j]->key, "NULL");
            strcpy(hash[i][j]->value, "NULL");
        }
    }
//All keys and values are initialised to NULL


    do{
        printf("\n\tMenu\n");
        printf("\t1. add\n");
        printf("\t2. delete\n");
        printf("\t3. search\n");
        printf("\t4. show all\n");
        printf("\t5. load\n");
        printf("\t6. save\n");
        printf("\t5. exit\n");
        //This is the interface of the Menu


        printf("\ninput the function you want to do\n");
        scanf("%d", &input);
        //program asks user for input on menu

        switch(input){
            case 1:
                add(hash, rows, columns, used, size, key, value, hashIndex);
                used = used + columns;
                //each insertion of a key value pair means a row is being filled up so the amount of cells in each row is being added everytime
                break;

            case 2:
                deleteElement(hash, rows, columns);
                break;

            case 3:
                search(hash, rows, columns);
                break;

            case 4:
                showAll(hash, rows, columns);
                break;

            case 5:
                loadHash (fPointer);
                break;

            case 6:
                saveHash(fPointer, hash, rows, columns);
                break;

            case 7:
                printf("Exit");
                break;

            default:
                printf("Invalid input");
        }

    }while(input != 7);

//free();

    return 0;
}


int hashfunction(char *keyPar, int rowsPar, int hashIndexPar){//The hash function in the form of the hashfunction which accepts the key as a parameter
    int length;
    int total = 0;//adds all ascii values of hash
    int i;


    length = strlen(keyPar);

    for(i = 0; i <= length ; i++){
        total = total + (int)keyPar[i];
    }
    //by using type casting the ascii value of each character is found in a string
    hashIndexPar = total%rowsPar;
    printf("%d\n", hashIndexPar);
//the hash function will consist of splitting the name into ascii code and taking the modulus of 20
    return hashIndexPar;
}

int add(element ***hashPar, int rowsPar, int columnsPar, int usedPar, int sizePar, char *KeyPar, char *ValuePar, int hashIndexPar){
    int indexUse;//index used to hold the return value of the hashFunction
    int i, j;

    if(usedPar == sizePar){
        //if the amount of spcae used is equal to the total space memory reallocation will occur

        printf("Memory will be reallocated as space is full up\n");

        hashPar = (element***)realloc(hashPar, sizeof(element **)*2);//memory is reallocated for the amount of rows in the hashtable each with the size of a char pointer
        //all elements are intiialised+ to 0
        for(i = 0; i < rowsPar; i++){
            hashPar[i] = (element **)realloc(hashPar[i], sizeof(element*)*2);//memory is allocated to each row as the amount of the columns where is memory location is the zise of char
            for(j = 0; j < columnsPar; j++){
                hashPar[i][j] = (element *)realloc(hashPar[i][j], sizeof(element)*2);
            }
        }
    }

    else{

        printf("Please enter the key you want to add\n");
        scanf("%s", KeyPar);
        //user enters the key

        indexUse = hashfunction(KeyPar, rowsPar, hashIndexPar);
        //indexUse will hold the return value of the hashFunction thus it will have the index

        if(strstr(hashPar[indexUse][0]->key, "NULL") != 0){
            //if the first element of the row indicated by the index is null

            strcpy(hashPar[indexUse][0]->key, KeyPar);
            //copy the key inputted by the user to the first element of the indexed row

            printf("%s is in element [%d][0] of the hashtable\n", hashPar[indexUse][0]->key, indexUse);
            //the user is told again in which row the key is in

            printf("add the %d value/s of the corresponding key\n", columnsPar - 1);
            //the corresponding values are added to the key

            for(i = 1; i < columnsPar; i++){//since i = 0 contains the value of the key it cannot be used to hold the key value pair
                scanf("%s", ValuePar);
                strcpy(hashPar[indexUse][i]->value, ValuePar);
                printf("%s is in element [%d][%d] of the hashtable\n", hashPar[indexUse][i]->value, indexUse, i);

            }
            //the for loop iterates through each column and places the value in the element
        }


        else{
            printf("A key is already in element [%d][0]\n", indexUse);
            printf("So this key will be put in the next available memory location\n");
            //if key is already in an element it will be put in the next available memory location

            for(i = 0;  i < rowsPar; i++){
                //iterate through the first columns of each row
                if(strstr(hashPar[i][0]->key, "NULL") == 0){
                    //check if the first element of each row is empty
                    strcpy(hashPar[i][0]->key, KeyPar);
                    //copy the key inputted by the uuser if the ith element is null
                    printf("The key is now in element [%d][0] of the hash table", i);
                    //user is told in which element the key is put

                    printf("add the %d value/s of the corresponding key\n", columnsPar - 1);
                    //the values now have to be added
                    for(j = 1; j < columnsPar; j++){//since i = 0 contains the value of the key it cannot be used to hold the key value pair
                        scanf("%s", ValuePar);
                        strcpy(hashPar[i][j]->value, ValuePar);
                        //the values are copies one by one to the corresponding element
                        printf("%s is in element [%d][%d] of the hashtable\n", hashPar[(int)indexUse][0]->value, i, j);
                        //the user is told in which element each value is placed

                    }
                }
            }
        }
    }
    return 0;
}

int deleteElement(element ***hashPar, int rowsPar, int columnsPar){
    char deleteInput[20];//hols the key the user wants to delete
    int i, j;//counters

    printf("Enter which key you want to delete");
    scanf("%s", deleteInput);
    //user inputs the key to delete

    for(i = 0; i < rowsPar; i++){
        //go through each key in the table
        if(strcmp(hashPar[i][0]->key, deleteInput) == 0){
            //if a key is found equal to the key to be deleted
            for(j = 0; j < columnsPar; j++){
                strcpy(hashPar[i][j]->key, "NULL");
                strcpy(hashPar[i][j]->value, "NULL");
                //keys and values are set to null and so are deleted
            }
            break;
            //stop iteration
        }

    }

    return 0;
}

int search(element ***hashPar, int rowsPar, int columnsPar) {
    int i;//counter
    char search[20];//used to hold the key to search for

    printf("Enter the key you want to search for\n");
    scanf("%s", search);
    //user inputs key to search for

    for (i = 0; i < rowsPar; i++) {
        //iteration to go through each key
        if (strcmp(search, hashPar[i][0]->key) ==
            0) {//if both strings are equal a zero will be returned by strcmp so checking for 0
            printf("This key is in element [%d][0] of the hashtable\n", i);
            //user is told in which element the key is in
        } else {
            printf("No results match\n");
            break;
        }
        //user is told that no keys match if they dont

    }

    return 0;
}




int showAll(element ***hashPar, int rowsPar, int columnsPar){
    int i, j;//counters

    for(i = 0; i < rowsPar; i++){
        for(j = 0; j < columnsPar; j++){

            if(j == 0){
            //if j is 0 means that if we are currently in the first columns
                printf("%s\t",hashPar[i][j]->key);
                //printf the key when in the first element of a row

            }
            else{
                //print the value currently on another column other than the first
                printf("%s\t", hashPar[i][j]->value);

            }

        }
        printf("\n");
        //new line to go to the next row
    }

    return 0;
}

void loadHash (FILE *fPointerPar){
    char readLine[150];//character string created which can store 150 characters in it
    //this array will be storing values one line at a time

    printf("Loading hash table from disk\n");

    fPointerPar = fopen("HashTable.txt", "r");
    //to load the hash table we only need to read it and output the the lines

    while(fgets(readLine, 150, fPointerPar)){
        //while the file is being read line by line and has not yet reached the ends

        printf("%s\n", readLine);
        //each line will be printed conitnuouslt until the last line since while loop goes until EOF
    }
}

void saveHash(FILE *fPointerPar, element ***hashPar, int rowsPar, int columnsPar){
    int i;
    int j;

    printf("Saving hash table to disk\n");
    //All the keys and their corresponding values will be saved in the HashTable.txt text file

    fPointerPar = fopen("HashTable.txt", "w");
    //the file here is created, and a pointer is pointing to it

    fprintf(fPointerPar, "keys\tvalues\n");
    for(i = 0; i < rowsPar; i++){
        for(j = 0; j < columnsPar; j++){

            if(j == 0){//when j is 0, print the key

                fprintf(fPointerPar, "%s\t", hashPar[i][j]->key);

            }
            else{

                fprintf(fPointerPar, "%s\t", hashPar[i][j]->value);

            }
            //a table here is created to show each key and its corresponding values
        }
        fprintf(fPointerPar, "\n");
        //using somehting similar to the showAll function but with the difference that this is printinf to the file
    }
    return;
}
