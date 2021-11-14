/*This is a basic calculator program that would allow
a user to create an equation with a chosen Arthemitic operator
and two numbers*/

/*These preprocessors are necessary to define the application's functions*/
#include <stdio.h>
#include <stdlib.h>

/*Disables pragma warning code 4996 for functions such as scanf*/
#pragma warning(disable : 4996)


/*This is where the main function starts*/
int main(void)
{
	FILE* log; // Creates a data type name log
	log = fopen("log.txt", "a+"); //This tells the application to create or append file log.txt

	char choice; //Declares data type of choice variable to be char
	int num1, num2, num4; //Declares the data type of num1, num2, and num4 as int
	float num3 = 0; //Declares the num3 as float to which the variable will be valued at 0 when not in use

	
	/*Start of do-while loop*/
	do
	{
		//Program will ask the user to choose an operator
		printf("Please choose one of these operators: +, -, *, /, d (integer division) or x (exit):\n");
		scanf("%c", &choice);
		
	
		/*These if statements will be used to notify the user of chosen operator*/
		if (choice == '+') //Addition
		{
			printf("The addition operator has been chosen\n");//Addition printf output
		}

		else if (choice == '-')//Subtract
		{
			printf("The subtraction operator has been chosen\n");//Subtraction printf output
		}

		else if (choice == '*')//Multiplication
		{
			printf("The multiplication operator has been chosen\n");//Multiplication printf output
		}

		else if (choice == '/')//Division
		{
			printf("The division operator has been chosen\n");//Division printf output
		}
		else if (choice == 'd')//Integer division
		{
			printf("The integer divsion operator has been chosen\n");//Integer division printf output
		}
		else if (choice == 'x') //Exit
		{
			printf("\nExiting the program...\n");//Exits program
			exit(0);
		}

		/*After operator has been chosen, the program will then ask for the firstand second number*/
			printf("\nPlease choose your first integer\n"); //Printf output for first integer
			scanf("%i", &num1); //Associates user input to num1
		
			printf("Please choose your second integer\n"); //Printf output for second integer
			scanf("%i", &num2); //Associates user input to num2

		/*Once first and second number has been chosen, the program will then output equation with chosen operator*/
		if (choice == '+') //If statement for +
		{
			num3 = num1 + num2; //Addition operation
			printf("This is your equation: %i %c %i = \n", num1, choice, num2); //Printf output to verify equation
			printf("The answer is: %f\n", num3);//Printf to give answer to user
		}
		else if (choice == '-')//If statement for -
		{
			num3 = num1 - num2;//Subtraction operation
			printf("This is your equation: %i %c %i = \n", num1, choice, num2);//Printf output to verify equation
			printf("The answer is: %f\n", num3);//Printf to give answer to user
		}
		else if (choice == '*')//If statement for *
		{
			num3 = num1 * num2;//Multiplication operation
			printf("This is your equation: %i %c %i = \n", num1, choice, num2);//Printf output to verify equation
			printf("The answer is: %f\n", num3);//Printf to give answer to user
		}
		else if (choice == '/')//If statement for
		{
			num3 = (double) num1 / (double) num2;//Division operation with double decimal location
			printf("This is your equation: %i %c %i = \n", num1, choice, num2);//Printf output to verify equation
			printf("The answer is: %f\n", num3);//Printf to give answer to user
		}
		else if (choice == 'd') //If statement for d
		{
			num4 = num1 / num2;//Integer division operation
			printf("This is your equation: %i %c %i = \n", num1, choice, num2);//Printf output to verify equation
			printf("The answer is: %i\n", num4);//Printf to give answer to user
		}

		/*This part of the application is used to finish the log.txt file*/
		if (choice == '+' || choice == '-' || choice == '*' || choice == '/')//If statement for +, -, *, and / operators
		{
			fprintf(log, "The result of %i %c %i = %f\n", num1, choice, num2, num3);//Printf output to log.txt file
			fclose(log);//closes log.txt file
		}
		else if (choice == 'd')//If statement for d operator
		{
			fprintf(log, "The result of %i %c %i = %i\n", num1, choice, num2, num4);//printf output to log.txt file
			fclose(log);//closes log.txt file

		}
		break; //Breaks do loop
	} while (choice == NULL); //This is to complete the do loop
}