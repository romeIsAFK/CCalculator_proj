/*This is a basic calculator that will allow the user to choose
an operator to which the program will then solve*/

/*These preprocessors are necessary to define the application's functions*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STRING_SIZE 30 //Definition of STRING_SIZE with 30
#pragma warning(disable : 4996) //Disables the scanf warning code 4996


/* Structures */

struct information //Struct name
{
	char fullname[STRING_SIZE]; //Struct variables with array size of STRING_SIZE
	char role[STRING_SIZE]; //Struct variable with array size of STRING_SIZE 
};

/* Unions */

union role // Union name
{
	bool graduated; //Union variables with 
	int year;
}info;

/*Start of main function*/
int main()
{
	char choice, q1, q2, q3; //Declares variable of program
	int n1, n2, n3; //Declares variable of program
	float n4; //Declares variable of program

	FILE* log; //Declares variable log as file data type
	log = fopen("log.txt", "a+"); //Defines log to open a log.txt file and to either append or create

	struct information creds; //Calls struct information and applies the call to creds variable

	int basicmath1(int num1, int num2, int operatorchoice); //Calls basicmath1 function
	float basicmath2(float num1, float num2); //Calls basicmath2 function

	printf("Hello! Welcome!\n"); //Welcome message to user
	printf("Please enter your full name: "); //Output to have user enter full name
	fgets(creds.fullname, 29, stdin); //Uses fgets to apply value to struct information using creds
	creds.fullname[strlen(creds.fullname) - 1] = '\0'; //This subtracts the '\n' at the end of a value entered by fgets (line 47) and applies a '\0' instead

	printf("\nHello, %s.\nAre you a teacher, student, or other?\nT = Teacher S = Student O = Other: ", creds.fullname); //Outputs messages to user to ask about their role
	q1 = getchar(); //Uses getchar to apply a single character value to q1

	while (q1 != 'T' && q1 != 't' && q1 != 'S' && q1 != 's' && q1 != 'O' && q1 != 'o') //While loop that is enabled if q1 does not match legal inputs
	{
		printf("Incorrect input given for role type. Please choose the right option: T = Teacher S = Student O = Other: "); //Outputs message to user to re-enter input for q1
		scanf_s(" %c", &q1);//Reapplies input to q1 within while loop
	}

	if (q1 == 'T' || q1 == 't') //Start of if statement
	{
		strcpy(creds.role, "Teacher"); //Copies string to information structure through creds and applies string to role variable
		getchar(); //Stops program from progressing into line 101 (While loop)
	}
	else if (q1 == 'S' || q1 == 's') //Starts if q1 input is 's'
	{
		strcpy(creds.role, "Student"); //Copies string to information structure through creds and applies string to role variable
		getchar(); //Stops program from progressing into line 101 (While loop)

		printf("ROLE: Student detected.\nHave you graduated highschool? [Y/N]"); //Asks student if highschool has been graduated
		q3 = getchar(); //Applies character input to q3 variable

		if (q3 == 'y' || q3 == 'Y') //Nested if statement if q3 equals 'y'
		{
			info.graduated == true; //Bool statement that changes role union graduated variable to true
		}
		else
		{
			printf("Please enter your expected graduation year for highschool: "); //Outputs question to user
			getchar(); //Stops program from progressing into line 101 (While loop)
			scanf_s("%i", &info.year); //Applies user input to union role year variable
		}
	}
	else if (q1 == 'O' || q1 == 'o') //Else if statement that starts if q1 equals 'O'
	{
		printf("Please enter your role: "); //Outputs to user to enter input for role variab;e
		getchar();//Stops program from progressing into line 101 (While loop)
		fgets(creds.role, 29, stdin); //Uses fgets to apply value to struct information using creds
		creds.role[strlen(creds.role) - 1] = '\0'; //This subtracts the '\n' at the end of a value entered by fgets (line 47) and applies a '\0' instead

	}
	else //Start of else statement
	{
		printf("\nIllegal input received for role\nExiting program."); //Outputs to user that program will exit
		exit(0); //Exits the program with code 0
	}

	printf("\nSTART OF PROGRAM\n");
	printf("\n+, -, *, /, d (integer division), a (average of 2 to 20 numbers), x (Exits the program).\nPlease choose an option: "); //Asks user to associate operator to choice variable
	choice = getchar(); // Associates one character to choice variable. Getchar() was used instead of scanf_s because it allows for only one character to be inputted to choice variable 

	while (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != 'd' && choice != 'a' && choice != 'A' && choice != 'x') //While loop to deter program from breaking if the incorrect operator was chosen for choice variable
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
			exit(0);//Exits the program with code 0
		}


		printf("Please choose the second integer\n"); //Informs user to input second integer to n2
		if (scanf_s("%i", &n2) != 1) //Associates user input to n2 variable, while loop that deters users from entering a non-integer value
		{
			printf("\nThat is not a legal integer...\n\nExiting the program.\n"); //Warning
			exit(0); //Exits the program with code 0
		}


		printf("\nThis is your equation to be calculated: %i %c %i\n\nIs this the right equation? [Y/N]:", n1, choice, n2); //Informs user of what the equation looks like before calculation
		getchar();//Allows the program to stop and wait for user to input y or n to q2
		scanf_s("%c", &q2); //Associates user input to q2 variable

		while (q2 != 'y' && q2 != 'Y' && q2 != 'n' && q2 != 'N') //Start of another while loop, this loop will only start if q2 does not equal the legal char value
		{
			printf("\nPlease choose again\n\nIs %i %c %i the right equation? [Y/N]:", n1, choice, n2); //Outputs message to user if q2 does not equal the legal char value
			scanf_s(" %c", &q2); //Asks the user to input the correct char value to q2
		}

		if (q2 == 'y' || q2 == 'Y') //Start of if statement if q2 equals 'y' or 'Y'
		{
			if (choice == '+') //Start of + equation if choice equals '+'
			{
				int toint = 1; //New variable declared and is associated to the number 1 value
				n3 = basicmath1(n1, n2, toint); //Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3); //Outputs the answer

				fprintf(log, "\nNAME: %s ROLE: %s \n", creds.fullname, creds.role);
				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == '-') //Start of - equation if choice equals '-'
			{
				int toint = 2; //New variable declared and is associated to the number 2 value
				n3 = basicmath1(n1, n2, toint); //Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3); //Outputs the answer

				fprintf(log, "\nNAME: %s ROLE: %s \n", creds.fullname, creds.role);
				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == '*')//Start of * equation if choice equals '*'
			{
				int toint = 3; //New variable declared and is associated to the number 3 value
				n3 = basicmath1(n1, n2, toint);//Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3);//Outputs the answer

				fprintf(log, "\nNAME: %s ROLE: %s \n", creds.fullname, creds.role);
				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3);//Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == '/')//Start of / equation if choice equals '/'
			{
				n4 = basicmath2(n1, n2);//Calls basicmath2 function, applies n1 and n2 to its arguments and outputs its return to n4 variable
				printf("\nThis is your answer: %.2f\n", n4); //Outputs the answer

				fprintf(log, "\nNAME: %s ROLE: %s \n", creds.fullname, creds.role);
				fprintf(log, "The result of %i %c %i is %.2f.\n", n1, choice, n2, n4); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
			else if (choice == 'd') //Start of d equation if choice equals 'd'
			{
				int toint = 4; //New variable declared and is associated to the number 5 value
				n3 = basicmath1(n1, n2, toint); //Calls basicmath1 function and applies n1, n2, and toint to its arguments and outputs its return to n3 variable
				printf("\nThis is your answer: %i\n", n3); //Outputs the answer

				fprintf(log, "\nNAME: %s ROLE: %s \n", creds.fullname, creds.role);
				fprintf(log, "The result of %i %c %i is %i.\n", n1, choice, n2, n3); //Outputs the answer to the log.txt file
				fclose(log); //Closes the log.txt file
			}
		}
		else if (q2 == 'n' || q2 == 'N') //Else if statement if q2 equals 'n' or 'N' the program will exit
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

		fprintf(log, "\nNAME: %s ROLE: %s ", creds.fullname, creds.role);
		fprintf(log, "\nAverage operation was chosen.\n\Elements in array: "); //Program introduces chosen operator to user in log.txt

		for (i = 0; i < a; ++i) //For loop that goes through each element in numarr array
		{
			fprintf(log, "%.2f ", numarr[i]); //Print outputs each element in array to log.txt
		}
		fprintf(log, "\nThis is the average of the %i elements = %.2f\n", a, avg); //Outputs the answer to log.txt
		fclose(log); //Closes log.txt

	}
	else if (choice == 'x' || choice == 'X') //Else if statement if user chooses 'x' or 'X'
	{
		fprintf(log, "\n%s has chosen to exit the program.\n", creds.fullname); //Outputs to log.txtr
		fclose(log); //Closes log.txt

		printf("\nYou have chosen to exit the program\n\nExiting the program...\n"); //Outputs the user choice in command line
		exit(0); //Exits the program with code 0
	}


	return 0; //Returns 0 to int main function
}




/* Secondary Functions */
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