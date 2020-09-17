#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct arrayElement {
    struct node *nodeElement;
    int count;
};
//a structure called hash is created which will have the nodeElement of each element in the array

struct node {
    char key[20];
    char value[20];
    struct node *next;
};
//a node structre is added containing the key and values and also a pointer node structure for the next node

struct node *generateNode(char keyPar[20], char valuePar[20]);
int hashFunction(char keyPar[20], int rowsPar, float indexPar, int indexHoldPar);
void insertElement(struct arrayElement * hashPar, char keyPar[20], char valuePar[20], int rowsPar, float indexPar, int indexHoldPar);
void showAllC(struct arrayElement * hashPar, int rowsPar);
void searchC(struct arrayElement *hashPar, char keyPar[20], int rowsPar, float indexPar, int indexHoldPar);
void saveHashC(FILE *fPointerPar,struct arrayElement *hashPar, int rowsPar) ;
void deleteElementC(struct arrayElement *hashPar, char keyPar[20], int rowsPar, float indexPar, int indexHoldPar);
void loadHash (FILE *fPointerPar);



int main(){
    int indexHold;
    float index;//variable used to hold the value of the ascii key mod
    char key[20];
    char value[20];
    int input;
    int rows;
    //vasriable used to hold the number of elements in the hash table
    int i;
    int j;
    FILE *fPointer;//a pointer the file
    struct node *useNode;


    printf("Enter the number of elements inisde the hashtable\n");
    scanf("%d", &rows);
    //user enters the number of rows in the hash table

    struct arrayElement *hash; //a 1d array is used to hold the index hash with each element having a node nodeElement of a linked list


    hash = (struct arrayElement *)calloc(rows, sizeof(struct arrayElement));
    //memory is allocated for each row of the hash table

    for(int i; i < rows; i++){
        hash[i].count = 0;
    }
    //the count member of the structure is initialised to 0 for all elements of the array

    do{
        printf("Menu\n");
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
                insertElement(hash, key, value, rows, index, indexHold);
                break;

            case 2:
                deleteElementC(hash, key, rows, index, indexHold);
                break;

            case 3:
                searchC(hash, key, rows, index, indexHold);
                break;

            case 4:
                showAllC(hash, rows);
                break;

            case 5:
                loadHash (fPointer);
                break;

            case 6:
                saveHashC(fPointer, hash, rows);
                break;

            case 7:
                printf("End of program");
                break;

            default:
                printf("Invalid input");
                break;
        }

    }while(input != 7);

    return 0;
}

//function of type struct node and so this function points to a key, value and the next node
struct node *generateNode(char keyPar[20], char valuePar[20]){
    struct node *useNode;
    //a new node is created with parameters as the key and value of each element in the hash table

    useNode = (struct node *)malloc(sizeof(struct node));
    //memory is allocated to the new new node

    strcpy(useNode->key, keyPar);
    //the value of key is read to the new node

    strcpy(useNode->value, valuePar);
    //the value of key value pair is read to the new node

    useNode->next = NULL;
    //the new node of the linked list is pointing to NULL as it is at the end of the list

    return useNode;
}

int hashFunction(char keyPar[20], int rowsPar, float indexPar, int indexHoldPar){//The hash function in the form of the hashFunction which accepts the key as a parameter
    int i;//counter
    int length;//holds the length of the user inputted key
    int total = 0;//adds all ascii values of hash

    length = strlen(keyPar);
    //length is initialised to the length of the key

    for(i = 0; i <= length ; i++){
        total = total + (int)keyPar[i];
    }
    //by using type casting the ascii value of each character is found in a string

    indexPar = total%rowsPar;
    indexHoldPar = (int)indexPar;
    //the hash function will consist of splitting the name into ascii code and taking the modulus of the total

    printf("The index is %d\n", indexHoldPar);
    //the index is printed after computing the hash function

    return indexHoldPar;
}

void insertElement(struct arrayElement * hashPar, char keyPar[20], char valuePar[20], int rowsPar, float indexPar, int indexHoldPar){

    int tempIndex;//variable used to hold index during function call

    printf("Enter the key you want to input\n");
    scanf("%s", keyPar);
    //user prompted to enter desired key

    printf("Enter the corresponding value of the key\n");
    scanf("%s", valuePar);
    //the user inputs the value corresponding to the key

    tempIndex = hashFunction(keyPar, rowsPar, indexPar, indexHoldPar);
    //the value of the key is hashed and a hash index is obtained. This value is contained within

    struct node *useNode = generateNode(keyPar, valuePar);
    //a new node is created using the node structure defined before

    if(hashPar[tempIndex].nodeElement == NULL){
        //if hash[indexPar].nodeElement is empty do the following

        hashPar[tempIndex].nodeElement = useNode;
        //the nodeElement node is now pointing to the new node while the new node is pointing to null

        printf("First element of the index is %s\n", hashPar[tempIndex].nodeElement);
        //make the first element of the linked corresponding to the hash index point to the new node

        hashPar[tempIndex].count = 1;
        //counter is set to 1 of the corresponding linked list sine only 1 element is placed

        printf("This is node number %d of element %d in the hash table\n", hashPar[tempIndex].count, tempIndex);
        //showing the user in which element the key is in

    }
        //here we are checking that if the element has no nodes yet we then add the header node

    else{


        useNode->next = hashPar[tempIndex].nodeElement;
        //the information of the old node is added to the new node, so the new node points to the old one

        hashPar[tempIndex].nodeElement = useNode;
        //the current element of the linked list is set to a new pointer

        hashPar[tempIndex].count++;
        //the counter is updated since a new node is added to the list

        printf("Count is now %d\n",hashPar[tempIndex].count);
        //This user is shown the number of nodes in the linkes list

        printf("This is node number %d of element %d in the hash table\n", hashPar[tempIndex].count, tempIndex);


    }

    return;
}

void showAll(struct arrayElement *hashPar, int rowsPar){
    int i;//counter
    int j;
    struct node *useNode;//a new node declared

    for (i = 0; i < rowsPar; i++){

        if(hashPar[i].count == 0){
            continue;
        }//checking if the i element of the hash table has a node, if count is equal to 0 then there is no node

        useNode = hashPar[i].nodeElement;
        //the newly createed node is set to point to the first element of the hash table


        printf("\nIndex %d of the hashtable:\n",i);
        printf("key:\tvalue\n");
        //Shows the current element of the hash table along with the key and value of each corresponding node in the element


        for(j = 1; j <= hashPar[i].count; j++){

            printf("%s\t", useNode->key);
            printf("%s\n", useNode->value);

            useNode = useNode->next;
        }
        //each node after the first element of the array is passed through displaying the key and value of each node

    }

    return;
}

void search(struct arrayElement *hashPar, char keyPar[20], int rowsPar, float indexPar, int indexHoldPar){

    int i;//counter
    int tempIndex;//used to hold the return value of the hash function


    printf("Please input the key you want to search for\n");
    scanf("%s", keyPar);
    //user enters key to search

    tempIndex = hashFunction(keyPar, rowsPar, indexPar, indexHoldPar);
    //the return value of the hash function is put in tempIndex

    int flag = 0;
    //flag used to make sure that search is correct

    struct node *useNode;
    //a node is created

    useNode = hashPar[tempIndex].nodeElement;
    //the node is set to point to the first node in the array element


    if(useNode == NULL){
        printf("No results match in the hash table\n");
    }
        //if the array element has no nodes then print that there are no matches

    else{
        for(i = 1; i <= hashPar[tempIndex].count; i++){
            //go through each node since there are "count" number of nodes

            if(strcmp(useNode->key, keyPar) == 0){
                //if the key at that node is the same as the inputted, the node is found
                printf("The key is in the hash table\n");
                printf("key   :%s\n", useNode->key);
                printf("value :%s\n", useNode->value);
                //details of the node is shown to the user
                flag = 1;
                //flga is set equal to 1 to show that the search worked
            }
            useNode = useNode->next;
            //after the if statement the next node is checked so as to check all nodes for the key
        }
    }
    if(flag == 0){//making sure that flag is 0 so as to see if the results match
        printf("No results match in the hash table\n");
    }

    return;
}

void deleteElement(struct arrayElement *hashPar, char keyPar[20], int rowsPar, float indexPar, int indexHoldPar){
    int i;//counter
    int tempIndex;//used to hold the return value of the hash function


    printf("Please input the key you want to delete\n");
    scanf("%s", keyPar);
    tempIndex = hashFunction(keyPar, rowsPar, indexPar, indexHoldPar);
    //the return value of the hash function is put in tempIndex

    int flag = 0;//flag used to make sure key is deleted
    //the user is prompted to enter the desired key to delete

    struct node *useNode, *temp;
    //structure useNode created to pass information to hash nodeElement
    //temp node created to hold information during deletion

    useNode = hashPar[tempIndex].nodeElement;//useNode holds the data of the header of the tempIndex element
    if(useNode == NULL){
        printf("No results match in the hash table\n");
        return;
        //if useNode is empty say that no results match since there are no nodes in the element
    }

    else{
        temp = useNode;
        //making temp equal to the header of the element


        for(i = 1; i <= hashPar[tempIndex].count; i++){
            //going node by node foe each "count" times since there are "count" nodes in the linked list
            if(strcmp(useNode->key, keyPar) == 0){
                //if the key in useNode and the key inputted by the user are equal
                flag = 1;//flag is set to 1 since the node will be deleted
                if(useNode == hashPar[tempIndex].nodeElement){
                    //if seNode is equal to the header of the element
                    hashPar[tempIndex].nodeElement = useNode->next;
                    //the header of the element is equal to the node being pointed to by useNode so useNode is deleted
                    useNode->next = NULL;
                    //now useNode is pointing to nothing and is pointed to by nothing so it is deleted
                }

                else{
                    temp->next = useNode->next;
                    //the node pointed to by useNode is now pointed to by temp and temp
                    hashPar[tempIndex].count--;
                    //the counter is reduced by one so a node is removed by the list
                    free(useNode);
                    break;
                }
            }
            temp = useNode;
            //temp is set to useNode again
            useNode = useNode->next;
            //useNode is pointing to the following element so as to following nodes of the linked list
        }
    }


    if (flag){
        printf("Data deleted successfully from Hash Table\n");
        //if flag is 1 and so if deletion happened
    }


    else{
        printf("No results match in the hash table\n");
        //if flag is 0 no deletion occured
    }

    return;
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

void saveHash(FILE *fPointerPar,struct arrayElement *hashPar, int rowsPar) {
    int i;
    int j;

    struct node *useNodePar;

    printf("Saving hash table to disk\n");
    //All the keys and their corresponding values will be saved in the HashTable.txt text file

    fPointerPar = fopen("HashTable.txt", "w");
    //the file here is created, and a pointer is pointing to it


    for (i = 0; i < rowsPar; i++) {

        if (hashPar[i].count == 0) {
            continue;
        }//checking if the i element of the hash table has a node, if count is equal to 0 then there is no node

        useNodePar = hashPar[i].nodeElement;
        //the newly createed node is set to point to the first element of the hash table


        fprintf(fPointerPar, "\nIndex %d of the hashtable:\n", i);
        fprintf(fPointerPar, "key:\tvalue\n");
        //Shows the current element of the hash table along with the key and value of each corresponding node in the element


        for (j = 1; j <= hashPar[i].count; j++) {

            fprintf(fPointerPar, "%s\t", useNodePar->key);
            fprintf(fPointerPar, "%s\n", useNodePar->value);

            useNodePar = useNodePar->next;
        }
    }
    return;
}
