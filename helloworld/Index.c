#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    printf ("Hello World!\n");

    /*int age = 12;
    char name [30] = "oshe";
    float av = 87.38;
    float clav = 67.97;
    printf("Oshe's age is %d.", age);
    printf ("His other name is %c. \n", name);
    printf ("He got an average of %f.", av);
    printf ("The class average is %f.",clav); 

    int len; 
    int brth;
    printf("Please input a length and breadth below: \n");
    printf ("Length");
    scanf("%d", &len);
    printf ("Breadth");
    scanf ("%d", &brth);
    printf("Your numbers are: %d, %d",len, brth);

    char fname [30] = "Oshebeyo";
    printf ("My name is: %s", fname);*/

    /*char fullname [100];
    printf ("Please enter your name");
    scanf ("%s", fullname);
    printf ("Name: %s", fullname);
    if (scanf("%s", &fullname)!=1);*/

    /*int avg1;
    printf ("Please enter your average: "); 
    scanf ("%d", &avg1);
    printf ("Your average is: %d.", avg1);*/

   // while (getchar()!= '\n')
  //  {
        /* code */
    //};

    /*int avg2;
    printf("Enter another average: ");
    scanf("%d", avg2);
    printf ("Your second average is: %d.", avg2);*/

    /*char name1[30] = "Craig";
    char name2[30] = "Ramsey";
    char name3[30] = "Craig";

    int lengthOfString = strlen (name1);
    printf ("The number of characters in your name is: %s", lengthOfString );

    if (strcmp(name1, name2) == 0){

    }*/

    int num1;
    int num2;
    printf("Please enter your 1st number;");
    scanf ("%d", &num1);
    printf("Please enter your 2nd number;");
    scanf ("%d", &num2);

    if (num1 == num2)
    {
        printf("A and B are the same");
    }
    else{
        printf("A and B are not the same \n ");

        if (num1 > num2)
        {
            printf("A is greater than B");
        }
        else{
            printf("A is less than B");
        }
    }


   /*int main() {
    int value;
    int min = 1, max = 100;
    printf("Enter an integer between %d and %d: ", min, max);
    while (scanf("%d", &value) != 1 || value < min || value > max) {
        printf("Invalid input. Please enter an integer between %d and %d: ", min, max);
        while (getchar() != '\n');  // Clear the input buffer
    }
    printf("You entered a valid integer: %d\n", value);
    return 0;*/
//}


   /* int grade;
    int min = 1, max = 100;
    printf("Input your percentage");
    while (scanf("%d", &grade) != 1 || grade < min || grade > max )
    {
        while (getchar() != '\n');
    }
    
    scanf("%d", &grade);
    switch (grade){
        case 90 ... 100:
        printf ("You got an A*");
        break;

        case 80 ... 89:
        printf ("You got an A");
        break;

        case 70 ... 79:
        printf ("You got a B");
        break;

        case 60 ... 69:
        printf ("You got a C");
        break;

        case 50 ... 59:
        printf ("You got a D");
        break;

        default:
        printf ("You got an F");
        

    }
*/
    

    



 return 0;

}

