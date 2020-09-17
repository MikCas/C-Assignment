#include<stdio.h>
#include<string.h>

int i;
int j;
int hashColumns;//number of columns of the hashtable
int hashSpace;//number of rows of the hashtable
int length;
int total = 0;//adds all ascii values of hash


int hashfunction(char *key, int rows, float modulus);//initialisation of function above main
int search(char *arr[], int rows, int columns);
int showAll(char *arr[], int rows, int columns);


int main (){

    int hashSpace;//number of rows of the hashtable
    int hashColumns;//number of columns of the hashtable
    int input;
    float mod;
    //insert((char **)hash, hashSpace, hashColumns, mod);
    char key[20];//this is the variable which will hold the unique value of the function
    char value[20];
    char delete[20];
    char search[20];


    printf("Please input the number of rows of the hashtable\n");
    scanf("%d", &hashSpace);
    //requesting user input to obtain the amount of rows

    printf("Please input the number of columns of the hashtable\n");
    scanf("%d", &hashColumns);
    //requesting user input to obtain the amount of columns

    char *hash[hashSpace][hashColumns];//the hash table as a 2d array with rows and columns defined as hashSpace and hashColumns

    printf("The hashtable will have dimensions %d by %d\n", hashSpace, hashColumns);
    //Here a table is created which will have the specified dimension

    for(i = 0; i < hashSpace; i++){
        for(j = 0; j < hashColumns; j++){
            hash[i][j] = '\0';
        }
    }
    //initialising all elements as null


    do{

        printf("\nMenu\n");
        printf("1. add\n");
        printf("2. delete\n");
        printf("3. search\n");
        printf("4. show all\n");
        printf("5. exit\n");
        //This is the interface of the Menu


        printf("input the function you want to do\n");
        scanf("%d", &input);
        //program asks user for input on menu

        switch(input){
            case 1:

                //insert((char *)hash, hashSpace, hashColumns, mod);


                printf("Enter the key you want to enter\n");
                scanf("%s", key);
                //hashfunction(key, hashSpace, mod);//the function is given th address to the key
                length = strlen(key);

                for(i = 0; i <= length ; i++){
                    total = total + (int)key[i];
                }
                //by using type casting the ascii value of each character is found in a string
                mod= total%hashSpace;
                int x = mod;
                printf(" value is %d\n", x);
                //the hash function will consist of splitting the name into ascii code and taking the modulus of 20

                /*
                  if(hash != '\0'){
                    printf("Element [%d][0] is full \n", (int)mod);
                  }
             */

                hash[x][0] = strdup(key);
                printf("%s is in element [%d][0] of the hash table\n", hash[x][0] , x);



                //add values of key value pair

                for(i = 1; i < hashColumns; i++){//since i = 0 is the first element thus the key
                    printf("Please enter the value of the key-value pair you want\n");
                    scanf("%s", value);
                    hash[(int)mod][i] = strdup(value);
                    printf("%s is the value of the key %s stored in element [%d][%d]\n",value, key, (int)mod, i);
                }

                break;

            case 2:


                printf("Enter which key you want to delete");
                scanf("%s", delete);

                for(i = 0; i < hashSpace; i++){
                    if(strcmp(delete, hash[i][0])){
                        for(j = 0; j < hashColumns; j++){
                            hash[i][j] = '\0';
                        }
                        break;

                        //delete values as well
                    }

                }
                break;

            case 3:


                printf("Enter the key you want to search for\n");
                scanf("%s", &search);

                for(i = 0; i < hashSpace; i++){
                    if(strcmp(search, hash[i][0]) == 0){//if both strings are equal a zero will be returned
                        printf("This key is in row %d of the hash table\n", i);
                        break;
                    }

                    else{
                        printf("No results match\n");
                        break;
                    }

                }


                //search((char **)hash, hashSpace, hashColumns);
                break;

            case 4:

                printf("Show\n");

                for(i = 0; i < hashSpace; i++){
                    for(j = 0; j < hashColumns; j++){
                        printf("%s\t", hash[i][j]);
                    }
                    printf("\n");
                }

                //showAll((char **)hash, hashSpace, hashColumns);
                break;

            default:

                printf("Invalid input");

                break;

        }

    }while(input != 5);

    return  0;
}



int hashfunction(char *key, int rows, float modulus){//The hash function in the form of the hashfunction which accepts the key as a parameter
    int length;
    int total = 0;//adds all ascii values of hash


    length = strlen(key);

    for(i = 0; i <= length ; i++){
        total = total + (int)key[i];
    }
    //by using type casting the ascii value of each character is found in a string
    modulus = total%rows;
    printf("%d\n", (int)modulus);
//the hash function will consist of splitting the name into ascii code and taking the modulus of 20
    return 0;
}




int delete(char *arr[], int rows, int columns){
    char delete[20];



    printf("Enter which key you want to delete");
    scanf("%s", delete);

    for(i = 0; i < rows; i++){
        if(strcmp(delete, arr[i])){
            for(j = 0; j < columns; j++){
                arr[i][j] = '\0';
            }
            break;

            //delete values as well
        }

    }

    return 0;
}

int search(char *arr[], int rows, int columns){
    int i;
    char search[20];

    printf("Enter the key you want to search for\n");
    scanf("%s", &search);

    for(i = 0; i < rows; i++){
        if(strcmp(search, arr[i]) == 0){//if both strings are equal a zero will be returned
            printf("This key is in the hash table\n");
            break;
        }

        else{
            printf("No results match\n");
            break;
        }

    }

    return 0;

    //use fgets in add
}

int showAll(char *arr[], int rows, int columns){
    int i;
    int j;
    printf("Show\n");

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            printf("%s\t", &arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
