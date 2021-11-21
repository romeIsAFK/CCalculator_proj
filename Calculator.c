/*This is a basic calculator that will allow the user to choose
an operator to which the program will then solve*/

/*These preprocessors are necessary to define the application's functions*/
#include <stdio.h>
#include <stdlib.h>


#pragma warning(disable : 4996) //Disables the scanf warning code 4996

/*Start of main function*/
int main()
{
	char choice, q1; //Declares variable of program
	int n1, n2, n3; //Declares variable of program
	float n4; //Declares variable of program

	FILE* log; //Declares variable log as file data type
	log = fopen("log.txt", "a+"); //Defines log to open a log.txt file and to either append or create

	int basicmath1(int num1, int num2, int operatorchoice); //Calls basicmath1 function
	float basicmath2(float num1, float num2); //Calls basicmath2 function



	printf("+, -, *, /, d (integer division), a (average of 2 to 20 numbers), x (Exits the program).\nPlease choose an option: "); //Asks user to associate operator to choice variable
	choice = getchar(); // Associates one character to choice variable. Getchar() was used instead of scanf_s because it allows for only one character to be inputted to choice variable 

	while (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != 'd' && choice != 'a' && choice != 'x') //While loop to deter program from breaking if the incorrect operator was chosen for choice variable
	{
		printf("\nThat option is incorrect...\n\nPlease choose again: "); //Outputs warning
		scanf_s(" %c", &choice); //New input for choice variable, this time using scanf_s function. Getchar() did not function correctly, it is in test cases.
	}

	if (choice == '+' || choice == '-' || choice == '*' || choice == '/' || choice == 'd') //First if statement, allows the program to follow a path if legal operator character was inputed to choice variable
	{
		printf("\nPLEASE NOTE: This calculator will only solve an equation using two integers...\n"); //Warning/note telling users that the basic math feature of this calculator will only calculator two integers

		printf("\nPlease choose the first integer\n"); //Informs user to input first integer to n1
		while (scanf_s("%i", &n1) != 1) //Associates user input to n1 variable, while loop that deters users from entering a non-integer value
		{
			printf("\nThat is not a legal integer...\n\nExiting the program.\n"); //Warning
			exit(-1);//Exits the program with code -1
		}


		printf("Please choose the second integer\n"); //Informs user to input second integer to n2
		if (scanf_s("%i", &n2) != 1) //Associates user input to n2 variable, while loop that deters users from entering a non-integer value
		{
			printf("\nThat is not a legal integer...\n\nExiting the program.\n"); //Warning
			exit(-1); //Exits the program with code -1
		}


		printf("\nThis is your equation to be calculated: %i %c %i\n\nIs this the right equation? [Y/N]:", n1, choice, n2); //Informs user of what the equation looks like before calculation
		getchar();//Test case! The program was not waiting for user input at the next scanf_s function... after further research this was applied to stop the program and wait for user input at the next scanf_s function
		scanf_s("%c", &q1); //Associates user input to q1 variable

		while (q1 != 'y' && q1 != 'Y' && q1 != 'n' && q1 != 'N') //Start of another while loop, this loop will only start if q1 does not equal the legal char value
		{
			printf("\nPlease choose again\n\nIs %i %c %i the right equation? [Y/N]:", n1, choice, n2); //Outputs message to user if q1 does not equal the legal char value
			scanf_s(" %c", &q1); //Asks the user to input the correct char value to q1
		}

		if (q1 == 'y' || q1 == 'Y') //Start of if statement if q1 equals 'y' or 'Y'
		{
			if (choice == '+') //Start of + equation if choice equals '+'
			{
				int toint = 1; //New variable declared and is associated to the number 1 value
				n3 = basicmath1(n1, n2, toint); //Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3); //Outputs the answer

				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == '-') //Start of - equation if choice equals '-'
			{
				int toint = 2; //New variable declared and is associated to the number 2 value
				n3 = basicmath1(n1, n2, toint); //Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3); //Outputs the answer

				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == '*')//Start of * equation if choice equals '*'
			{
				int toint = 3; //New variable declared and is associated to the number 3 value
				n3 = basicmath1(n1, n2, toint);//Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3);//Outputs the answer

				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3);//Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == '/')//Start of / equation if choice equals '/'
			{
				n4 = basicmath2(n1, n2);//Calls basicmath2 function, applies n1 and n2 to its arguments and outputs its return to n4 variable
				printf("\nThis is your answer: %.2f\n", n4); //Outputs the answer

				fprintf(log, "The result of %i %c %i is %.2f.\n", n1, choice, n2, n4); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == 'd') //Start of d equation if choice equals 'd'
			{
				int toint = 4; //New variable declared and is associated to the number 5 value
				n3 = basicmath1(n1, n2, toint); //Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3); //Outputs the answer

				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
		}
		else if (q1 == 'n' || q1 == 'N') //Else if statement if q1 equals 'n' or 'N' the program will exit
		{
			printf("\nIncorrect inputs...\n\nPlease restart the program\n"); //Warning
			exit(0); //Exits the program with code 0
		}
	}
	else if (choice == 'a' || choice == 'A') //Else if statement to start the average feature
	{

		int a, i; //Variables declared
		float numarr[20], sum = 0.0, avg; //Variables declared, numarr is set to only allow 20 elements, sum equals 0.0

		printf("\nThe average equation has been chosen.\n\nEnter the number of elements (cannot be lower than 2 and higher than 20): "); //Outsputs the directions to user
		scanf_s("%i", &a); //Associates number of elements to a variable

		while (a > 20 || a <= 1) //While loop, in case the user inputs the number of elements not within the range of 2 to 20
		{
			printf("\nPlease choose a number in the range of 2 to 20.\n\nEnter number of elements again: "); //Outputs the directions again to user
			scanf_s("%i", &a); //Associates number of elements to a variable again
		}

		for (i = 0; i < a; ++i) //Loops through elements
		{
			printf("%i. Enter number: ", i + 1); //User enters input for each element in numarr array
			scanf_s("%f", &numarr[i]); //Program associates user input to each element in array
			sum += numarr[i]; //Program adds each element in array and associates it to sum
		}

		avg = sum / a; //Sum is divided by number of elements in array to get average
		printf("\nThis is the average of the %i elements = %.2f\n", a, avg); //Outputs answer

		fprintf(log, "Average operation was chosen.\n\Elements in array: "); //Program introduces chosen operator to user in log.txt

		for (i = 0; i < a; ++i) //For loop that goes through each element in numarr array
		{
			fprintf(log, "%.2f ", numarr[i]); //Print outputs each element in array to log.txt
		}
		fprintf(log, "\nThis is the average of the %i elements = %.2f\n", a, avg); //Outputs the answer to log.txt
		fclose(log); //Closes log.txt

	}
	else if (choice == 'x' || choice == 'X') //Else if statement if user chooses 'x' or 'X'
	{
		fprintf(log, "Program was exited.\n"); //Outputs to log.txtr
		fclose(log); //Closes log.txt

		printf("\nYou have chosen to exit the program\n\nExiting the program...\n"); //Outputs the user choice in command line
		exit(0); //Exits the program with code 0
	}


	return 0; //Returns 0 to int main function
}


/*This is the function that calculates the n1 and n2 variables from int main()
and outputs it back using the return call for sum*/
int basicmath1(int num1, int num2, int operatorchoice) //Data type, name, and arguments
{

	if (operatorchoice == 1) //Operaterchoice gets its argument from toint from int main() and utilizes that to return the right equation
	{
		int sum = num1 + num2; //Calculation for addition

		return (sum); //Returns sum to int main()
	}
	else if (operatorchoice == 2) //Else if statement for subtraction
	{
		int sum = num1 - num2; //Calculation for subtraction

		return (sum); //Returns sum to int main()
	}
	else if (operatorchoice == 3) //Else if statement for multiplication
	{
		int sum = num1 * num2; //Calculation for multiplication

		return (sum); //Returns sum to int main()
	}
	else if (operatorchoice == 4) //Else if statement for division
	{
		int sum = num1 / num2; //Calculation for division

		return (sum); //Returns sum to int main()
	}

	return 0;
}

/*This function does float division
It differs from basicmath2 because it
is in float data type form*/
float basicmath2(float num1, float num2) //Data type, name, and arguments
{
	float sumfloat = num1 / num2; //Calculation for float division

	return (sumfloat); //Returns sumfloat to int main()
}
