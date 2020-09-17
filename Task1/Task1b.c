#include<stdio.h>

void checkout(float priceTotalPar, float discountedPricePar, float weightTotalPar, float shippingPricePar);
void bill(float artichokesWeightPar, float onionsWeightPar, float carrotsWeightPar, float artichokesPricePar, float onionsPricePar, float carrotsPricePar, float priceTotalPar, float weightTotalPar, float discountedPricePar, float shippingCostPar);
//fucntions being intitialised before the main so as to be able to call them


int main(){
    char input;
    //used for user input to use the menu

    float artichokes;
    float onions;
    float carrots;
    //used to keep count of the number of each of artichokes, onions and carrots sold

    float weightTotal = 0;
    float priceTotal;
    //weightTotal and priceTotal are used to help in determining the final bill since they contain the weight and price values of each menu item together


    float artichokesPrice = 0;
    float onionsPrice = 0;
    float carrotsPrice = 0;
    //'vegetable'Price is used to hold the price of each vegetable individually

    float artichokesWeight;
    float onionsWeight;
    float carrotsWeight;
    //'vegetable'Weight is used to hold the cumulative weight of each vegetable individually

    float discountedPrice; //used to  hold the discounted price
    float shippingPrice; //used to hold the price of shipping



    do {
        printf("\nMenu\n");
        printf("\na: artichokes (2.05/kg) \n");
        printf("\nb: onions (1.15/kg) \n");
        printf("\nc: carrots (1.09/kg) \n");
        printf("\nq: checkout\n");
        printf("\nInput:");
        //menu display when the program is run

        scanf(" %c", &input);
        //user input to obtain a the wanted function the user wants to do

        switch(input) {
            case 'a':

                printf("Enter the amount of atrichokes you want in kg\n");

                scanf("%f", &artichokes);

                weightTotal = artichokes + weightTotal;
                priceTotal = 2.05 * artichokes + priceTotal;

                printf("\nTotal price is %.2f\n", priceTotal);
                printf("\nTotal weight is %.2f\n", weightTotal);

                artichokesPrice = artichokesPrice + 2.05*artichokes;
                //the individual amount spent on each vegetable is calculated using current amount spent plus amount bought multiplied by the price of a single vegetable

                artichokesWeight = artichokesWeight + artichokes;

                break;

            case 'b':

                printf("Enter the amount of onions you want in kg\n\n");
                scanf("%f", &onions);

                weightTotal = onions + weightTotal;
                priceTotal = 1.15* onions + priceTotal;

                printf("\nTotal price is %.2f\n", priceTotal);
                printf("\nTotal weight is %.2f\n", weightTotal);

                onionsPrice = onionsPrice + 1.15*onions;
                //the individual amount spent on each vegetable is calculated using current amount spent plus amount bought multiplied by the price of a single vegetable

                onionsWeight = onionsWeight + onions;
                break;

            case 'c':

                printf("Enter the amount of carrots you want in kg\n");
                scanf("%f", &carrots);

                weightTotal = carrots + weightTotal;
                priceTotal = 1.09 * carrots + priceTotal;

                printf("\nTotal price is %.2f\n", priceTotal);
                printf("\nTotal weight is %.2f\n", weightTotal);

                carrotsPrice = carrotsPrice + 1.09*carrots;
                //the individual amount spent on each vegetable is calculated using current amount spent plus amount bought multiplied by the price of a single vegetable

                carrotsWeight = carrotsWeight + carrots;
                break;

            case 'q':

                checkout(priceTotal, discountedPrice, weightTotal, shippingPrice);
                bill(artichokesWeight, onionsWeight, carrotsWeight, artichokesPrice, onionsPrice, carrotsPrice,
                     priceTotal, weightTotal, discountedPrice, shippingPrice);
                break;

            default:
                //user verification since the print statement is given each time a character other then the other cases is given

                printf("\nInvalid Input\n");
                break;
        }

        /*the user sees from the menu the option they want to use and from that the switch
        statement works.
        When choosing a vegetable the number of kg wanted is chosen and the weight
        and total price are updated, this is done in the amount Vegetables function
        */
    }while('q' != input);
    /*A menu  here is created using the do-while loop and the switch statement inside.
    The do-while loop is used so that the menu will run once for sure.
    */

    return 0;
}



void checkout(float priceTotalPar, float discountedPricePar, float weightTotalPar, float shippingPricePar){

    if(priceTotalPar >= 100){
        //this is checking if the user bought 100 euros or more worth of items

        priceTotalPar = (95*priceTotalPar)/100;
        //if the condition is true 5 percent fo the total price is removed

        discountedPricePar = priceTotalPar;
        //the discounted price is equal to the total price now

        printf("Due to spending more than a 100 euros you have a discount of 5%%\n");
        printf("Your disocunted price is %.2f\n", priceTotalPar);

//the program checks if the user exceeds 100 eureos to give the user a discount
    }

//shipping costs are going to be checked after
//if the weight is less than or equal to 5kg add 6.50 euros to the total price
    if (weightTotalPar <= 5){

        priceTotalPar = priceTotalPar + 6.50;

        shippingPricePar = 6.50;

        printf("Due to having less than or equal to 5kg, 6.50 euros is added to your total price\n");
        printf("Total price: %.2f euros\n", priceTotalPar);
        printf("Total Weight: %.2fkg\n", weightTotalPar);

    }
        //if the weight is greater than 5kg but less than 20 kg ad 14 euros to the total price
    else if(5 < weightTotalPar && weightTotalPar < 20){

        priceTotalPar = priceTotalPar + 14;

        shippingPricePar = 14;

        printf("Due to having more than 5kg but less than 20kg, 14 euros is added to your total price\n");
        printf("Total price: %.2f euros\n", priceTotalPar);
        printf("Total Weight: %.2fkg\n", weightTotalPar);

    }
        //if the weight is greater or equal to 20 euros add 14 euros and add 50 cents for each kg the user has
    else if(weightTotalPar >= 20){

        priceTotalPar = priceTotalPar + 14 + weightTotalPar*0.5;

        shippingPricePar = 14 + weightTotalPar*0.5;

        printf("Due to having more than or equal to 20kg, 14 euros and half of the amount of kg in euros is added to your total price\n");
        printf("Total price: %.2f euros\n", priceTotalPar);
        printf("Total Weight: %.2fkg\n", weightTotalPar);
    }

    return;
}
//This function takes care of the discount and also shipping costs


void bill(float artichokesWeightPar, float onionsWeightPar, float carrotsWeightPar, float artichokesPricePar,
          float onionsPricePar, float carrotsPricePar, float priceTotalPar, float weightTotalPar, float discountedPricePar, float shippingCostPar){

    FILE *fPointer;
    //file pointer created to point to file

    fPointer = fopen("bill.txt", "w");
    //file here is opened, the only operation the file is going to undertake is write

    fprintf(fPointer, "The bill");
    fprintf(fPointer, "Amount of Artichokes bought: %.2fkg\n", artichokesWeightPar);
    fprintf(fPointer, "Amount of Onions bought: %.2fkg\n", onionsWeightPar);
    fprintf(fPointer, "Amount of Carrots bought: %.2fkg\n", carrotsWeightPar);
    fprintf(fPointer, "Price of Artichokes: %.2f \n", artichokesPricePar );
    fprintf(fPointer, "Price of Onions: %.2f \n", onionsPricePar);
    fprintf(fPointer, "Price of Carrots: %.2f \n", carrotsPricePar);
    fprintf(fPointer, "Total price: %.2f", priceTotalPar);
    fprintf(fPointer, "Total weight: %.2fkg", weightTotalPar);
    fprintf(fPointer, "Discounted price: %.2f", discountedPricePar);
    fprintf(fPointer, "Shipping cost: %.2f", shippingCostPar);
    //all the information of the bill is written in the file and so it is seen as a bill

    printf("File is changed");
    //tells the user that the bill file is updated

    fclose(fPointer);
    //memory used by file is returned to computer

    return;
}
//This function makes a bill in the form of a text document which the user can see after buying
