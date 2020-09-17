#include<stdio.h>

int main (){

    float tomInv = 200; //varibale containing how much tom invests
    float joanInv = 200; //variable containing how much joan invests
    int years;//variable which holds the amount of years

    printf("Tom and Joan both start off with an equal investment of 200 euros\n");
    printf("\n");

    for (years = 1; tomInv >= joanInv; years++){
    /*
     a for loop is constructed where years is the counter and it iterates each time tom's investment is greater than or equal to joan's.
     So when joan's investment is greater than toms the for loop stops iterating
    */
        tomInv = tomInv + (200*15)/100;
        //this is a mathematical representation of Tom's simple interest
        joanInv = joanInv + ((joanInv)*10)/(100);
        //this is a mathematical representation of Joan's compound interest

        printf("Joans investment in year %d is %.2f euros\n", years, joanInv);
        printf("Toms investment in year %d is %.2f euros\n", years, tomInv);
        //with each iteration the investment is displayed to show the interests with each year
        printf("\n");
    }

    printf("Joan's investment passes Tom's after %d years\n", years - 1);//years is decremented since it is incremented in the for loop after the condition is met
    //the number of years it takes for Joan's investment to overtake tom's is printed
    printf("Tom's investment after %d years is %.2f euros\n", years - 1, tomInv);
    printf("Joan's investment after %d years is %.2f euros\n", years - 1, joanInv);
    //the two values at the time were also printed
    //years is decremented in the print statements, since it is incremented again in the for loop after the condition is met

    return  0;
}
