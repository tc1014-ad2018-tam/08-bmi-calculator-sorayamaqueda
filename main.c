/*
 * This program is to help the user calculate their Body Mass Index (BMI). The BMI is obtained by dividing the Weight of
 * a person (measured in kilograms) by its Height (measured in meters) to the square.
 * For this program, the user must able to introduce such values in any possible measure unit (pounds, feet, inches) and
 * still get back their BMI. Finally tell the user will know where within the BMI classification, according to the WHO,
 * does hers or his BMI fits in.
 *
 * According to the World Health Organization, according to your BMI you will find yourself in:
 *  -UNDERWEIGHT if BMI<18.50
 *  -NORMAL RANGE if BMI=18.50 && BMI<24.99
 *  -OVERWEIGHT if BMI>=25.00
 *  -OBESE if BMI>=30.00
 *
 * The equivalences are:
 *  - 1 feet = 0.3048 meters
 *  - 1 inch = 0.0245 meters
 *  - 1 pound = 0.453 kilograms
 *
 * Problem Analysis.
 * Problem: Calculate the BMI of the user regardless of the measurement unit that they use.
 *
 * Input: User's height, user's weight.
 *
 * Process/Calculations: Convert the units if there are not in kilograms and meters. Then divide the weight by the
 * height elevated to the square. Determine in which category the user falls in.
 *
 * Output: User's BMI and category it fits.
 *
 * Author: Soraya Lizeth Maqueda Gutiérrez
 * Date: 12.09.2018
 * Contact: soraya_maqueda@hotmail.com
 */

#include <stdio.h>
#include <math.h>

/* This function is to show the user the different options that they have to introduce their measurements.
 * The option 0 exits the program.
 * The option 1 takes the user to the function to perform the calculation in imperial units.
 * The option 2 takes the user to the function to perform the calculation in universal units.*/
//Menu Function. Here I obtain the nature of the measurements that the uses is going to introduce.
void menu () {
    printf("\nSpecify the units in which your measurements are given. Or enter 0 to exit.\n");
    printf("\n0. Exit\n");
    printf("\n1. Imperial (pounds and feet and inches)\n");
    printf("\n2. Universal (kilograms and meters)\n");
    printf("\nState your choosing:\n");
}

//Function for calculating the user's BMI
double bmi (double h, double w) {
    return h / pow (w,2);
}

//Function for determining the user's category
void category (double bmi) {
    printf("\nYour BMI is: %lf\n", bmi);
    printf("\nAccording to the WHO, your category is:\n");

    if (bmi<18.50) {
       printf("\nUnderweight\n");
    } else {
        if (bmi >= 18.50 && bmi < 24.99) {
            printf("\nNormal Range\n");
        } else {
            if (bmi >= 25 && bmi < 30) {
                printf("\nOverweight\n");
            } else {
                if (bmi > 30) {
                    printf("\nObese\n");
                }
            }
        }
    }
}

//Function for converting from Imperial Unit System to Universal Metric System
double imperial (double *h, double *w){
    double ft;
    double in;
    double lbs;
    double b;

    printf("Tell me your weight:");
    scanf("%lf", &lbs);
    printf("Tell me the feet:");
    scanf("%lf", &ft);
    printf("Tell me the inches:");
    scanf("%lf", &in);

    *w = lbs * 0.453;
    *h = ((ft * 0.3048)+(in * 0.0245));
    b = bmi(*h,*w);
    category(b);
}

//Function for getting the user's measurements in Universal System
void universal() {
    double m;
    double kg;

    printf("Tell me your height:\n");
    scanf("%lf", &m);
    printf("Tell me your weight;\n");
    scanf("%lf", &kg);
    category(bmi(m,kg));
}


int main() {
    int option;
    double h;
    double w;

    printf("Chose an option from the menu");

    do {
        menu();
        scanf("%i", &option);

        if (option != 0) {
            switch (option) {
                case 1:
                    imperial(&h, &w);
                    category(bmi(h, w));
                    break;
                case 2:
                    universal(&h, &w);
                    category(bmi(h, w));
                    break;
                default:
                    printf("You did not introduced a valid option. Please chose an option from the menu.");
            }
        }
    } while (option != 0);

    return 0;
}
