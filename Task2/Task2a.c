#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{

    char key[20];
    char value[20];

} element;
//structure of an element created where each element points to a key and a value


int hashfunction(char *keyPar, int rowsPar, int hashIndexPar);
int add(element ***hashPar, int rowsPar, int columnsPar, int usedPar, int sizePar, char *KeyPar, char *ValuePar, int hashIndexPar);
int showAll(element ***hashPar, int rowsPar, int columnsPar);
int deleteElement(element ***hashPar, int rowsPar, int columnsPar);
int search(element ***hashPar, int rowsPar, int columnsPar);
void saveHash(FILE *fPointerPar, element ***hashPar, int rowsPar, int columnsPar);
void loadHash(FILE *fPointerPar);

int main(){
    int input;//variable used to obtain user input
    int rows;//variable which holds rows of hashtable
    int columns;//variable which holds columns of hashtable
    int i;//counters
    int j;
    int hashIndex;
    char Key[20];//buffer variable used to hold the value of the key before placing it in the dyanmic array
    char Value[20];//buffer variabel used to hold the value of the key-value pair value before placing it in the dyanmic array
    //hash space is fully parameterizable
    //number of collisions dependant on user input of hash spaces
    int used = 0;;//variable to keep track of used spaces in the hash table
    int size;//variable to hold the size of the 2d array

    FILE *fPointer;//pointer used to point to file




    printf("Enter the amount of rows you want initially\n");
    scanf("%d",&rows);
    //input validation

    printf("\nEnter the amount of columns you want initially\n");
    scanf("%d",&columns);
    //input validation

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
        printf("\t7. exit\n");
        //This is the interface of the Menu


        printf("\ninput the function you want to do\n");
        scanf("%d", &input);
        //program asks user for input on menu

        switch(input){
            case 1:
                add(hash, rows, columns, used, size, Key, Value, hashIndex);
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
                loadHash(fPointer);
                break;

            case 6:
                saveHash(fPointer, hash, rows, columns);
                break;

            case 7:
                printf("End of program");
                break;
        }

    }while(input != 7);





    free(hash);//the memory allcoated to hash is sent back to the computer after the program ends

    return 0;
}


int hashfunction(char *keyPar, int rows, int hashIndexPar){//The hash function in the form of the hashfunction which accepts the key as a parameter
    int length;
    int total = 0;//adds all ascii values of hash
    int i;


    length = strlen(keyPar);

    for(i = 0; i <= length ; i++){
        total = total + (int)keyPar[i];
    }
    //by using type casting the ascii value of each character is found in a string
    hashIndexPar = total%rows;
    printf("%d\n", hashIndexPar);
//the hash function will consist of splitting the name into ascii code and taking the modulus of 20
    return hashIndexPar;
}

int add(element ***hashPar, int rowsPar, int columnsPar, int usedPar, int sizePar, char * keyPar, char *valuePar, int hashIndexPar){
    int hashBuffer;//holds the value of the returned hash table index

    if(usedPar == sizePar){
        printf("Hash table is full");
    }

    else{

        printf("Please enter the key you want to add\n");
        scanf("%s", keyPar);

        hashBuffer = hashfunction( keyPar, rowsPar, hashIndexPar);

        if(strstr(hashPar[hashBuffer][0]->key, "NULL") != 0){

            strcpy(hashPar[hashBuffer][0]->key,  keyPar);
            printf("%s is in element [%d][0] of the hashtable\n", hashPar[hashBuffer][0]->key, hashBuffer);

            if(columnsPar == 0){
                printf("No columns available to input values");
            }//this is just in case the user writes 0 columns
            else {

                printf("add the %d value/s of the corresponding key\n", columnsPar - 1);
                //the number of corresponding values are added in each element after the key element of the row

                for (int i = 1; i < columnsPar; i++) {//since i = 0 contains the value of the key it cannot be used to hold the key value pair
                    scanf("%s", valuePar);
                    strcpy(hashPar[hashBuffer][i]->value, valuePar);
                    printf("%s is in element [%d][%d] of the hashtable\n", hashPar[hashBuffer][i]->value, hashBuffer, i);

                }
            }
        }


        else{
            printf("A key is already in element [%d][0]\n", hashIndexPar);
            printf("So this key will be put in the next available memory location\n");

            for(int i = 0;  i < rowsPar; i++){
                if(strstr(hashPar[i][0]->key, "NULL") == 0){
                    strcpy(hashPar[i][0]->key, keyPar);
                    printf("The key is now in element [%d][0] of the hash table", i);
                    printf("add the %d value/s of the corresponding key\n", columnsPar - 1);

                    for(int j = 1; j < columnsPar; j++){//since i = 0 contains the value of the key it cannot be used to hold the key value pair
                        scanf("%s", valuePar);
                        strcpy(hashPar[i][j]->value, valuePar);
                        printf("%s is in element [%d][%d] of the hashtable\n", hashPar[hashBuffer][0]->value, i, j);

                    }
                }
            }
        }
    }
    return 0;
}

int deleteElement(element ***hashPar, int rowsPar, int columnsPar){
    char deleteInput[20];

    printf("Enter which key you want to delete");
    scanf("%s", deleteInput);

    for(int i = 0; i < rowsPar; i++){
        if(strcmp(hashPar[i][0]->key, deleteInput) == 0){
            for(int j = 0; j < columnsPar; j++){
                strcpy(hashPar[i][j]->key, "NULL");
                strcpy(hashPar[i][j]->value, "NULL");
            }
            break;

            //delete values as well
        }

    }

    return 0;
}

int search(element ***hashPar, int rowsPar, int columnsPar){
    int i;
    char search[20];

    printf("Enter the key you want to search for\n");
    scanf("%s", search);

    for(int i = 0; i < rowsPar; i++){
        if(strcmp(search, hashPar[i][0]->key) == 0){//if both strings are equal a zero will be returned
            printf("This key is in element [%d][0] of the hashtable\n", i);
        }

        else{
            printf("No results match\n");
            break;
        }

    }

    return 0;
}



int showAll(element ***hashPar, int rowsPar, int columnsPar){
    int i;
    int j;
    printf("Show\n");

    for(i = 0; i < rowsPar; i++){
        for(j = 0; j < columnsPar; j++){
            if(j == 0){

                printf("%s\t",hashPar[i][j]->key);

            }
            else{

                printf("%s\t", hashPar[i][j]->value);

            }

        }
        printf("\n");
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
