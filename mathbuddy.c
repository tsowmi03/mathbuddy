//
//A maths companion for primary school/early high school students
//Written by Thomas Sowmi on 25/08/2022
//Refactored by Nader Awad on 25/08/2022
//

#include <stdio.h> 
#include <math.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define HIGHEST_COMMON_FACTOR "hcf"
#define LOWEST_COMMON_MULTIPLE "lcm"
#define FACTORS "factors"
#define ANGLE_SUM "angsum"
#define QUIT "quit"
#define QUADRATIC "quad"
#define SIMP_FRACTIONS "simpfrac"
#define SIMPLIFY_SURD "simpsur"
#define ADD_FRACTIONS "addf"
#define SUB_FRACTIONS "subf"
#define MUL_FRACTIONS "mulf"
#define DIV_FRACTIONS "divf"
#define INTEREST "interest"
#define HELP "help"
#define CIRCLE "circle"
#define M_PI 3.14159265358979323846

int common_factor (int num1, int num2);
int lowest_common_multiple (int num1, int num2);
void list_factors (int num1);
void angle_sum ();
void remove_newline(char input[MAX_STRING_LENGTH]);
void quadratic();
void simplify_fraction();
void add_fractions (int num1, int denom1, int num2, int denom2);
void sub_fractions (int num1, int denom1, int num2, int denom2);
void mul_fractions (int num1, int denom1, int num2, int denom2);
void div_fractions (int num1, int denom1, int num2, int denom2);
void simplify_surd();
void calculate_interest();
void circle_area(double radius);
void circle_circum(double radius);

int main (void) {
	printf ("Enter command 'help' to see a list of commands: \n");
	printf ("What would you like to do? ");
	char command [MAX_STRING_LENGTH];
	while (fgets(command, MAX_STRING_LENGTH, stdin) != NULL) {

		remove_newline(command);

		if (strcmp (command, HIGHEST_COMMON_FACTOR) == 0) {
			//first number and second number entered via user input
			int num1 = 0; 
			int num2 = 0;

			printf ("Enter your two numbers: ");
			scanf("%d %d", &num1, &num2);

			int comfact = common_factor(num1, num2);

			printf ("The highest common factor is %d\n", comfact);
			printf ("What would you like to do? ");

			strcpy (command, "TRUE"); //to check for else

		} else if (strcmp (command, LOWEST_COMMON_MULTIPLE) == 0) {

			int num1, num2 = 0;

			printf ("Enter your two numbers: ");
			scanf("%d %d", &num1, &num2);

			int lcm = lowest_common_multiple(num1, num2);

			printf ("The lowest common multiple is %d\n", lcm);
			printf ("What would you like to do? ");

			strcpy (command, "TRUE");

		} else if (strcmp(command, FACTORS) == 0) {

			int num1 = 0;
			printf ("Which number would you like the factors of? ");
			scanf ("%d", &num1);

			printf ("The factors of %d are: ", num1);

			list_factors(num1);

			printf ("What would you like to do? ");

			strcpy (command, "TRUE");

		} else if (strcmp (command, ANGLE_SUM) == 0) {
				
			angle_sum();
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, QUIT) == 0) {
				
			printf ("See you later!\n");
			return 0;

		} else if (strcmp (command, QUADRATIC) == 0) {
				
			quadratic();
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, SIMP_FRACTIONS) == 0) {
				
			int num, denom = 0;
			printf ("Enter your fraction in the form: numerator/denominator ");
			scanf ("%d/%d", &num, &denom);
			simplify_fraction(num, denom);
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, ADD_FRACTIONS) == 0) {
				
			int num1, denom1, num2, denom2 = 0;
			printf ("Enter your fractions: ");
			scanf ("%d/%d %d/%d", &num1, &denom1, &num2, &denom2);
			add_fractions(num1, denom1, num2, denom2);
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, SUB_FRACTIONS) == 0) {

			int num1, denom1, num2, denom2 = 0;
			printf ("Enter your fractions: ");
			scanf ("%d/%d %d/%d", &num1, &denom1, &num2, &denom2);
			sub_fractions(num1, denom1, num2, denom2);
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, MUL_FRACTIONS) == 0) {

			int num1, denom1, num2, denom2 = 0;
			printf ("Enter your fractions: ");
			scanf ("%d/%d %d/%d", &num1, &denom1, &num2, &denom2);
			mul_fractions(num1, denom1, num2, denom2);
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, DIV_FRACTIONS) == 0) {
				
			int num1, denom1, num2, denom2 = 0;
			printf ("Enter your fractions: ");
			scanf ("%d/%d %d/%d", &num1, &denom1, &num2, &denom2);
			div_fractions(num1, denom1, num2, denom2);
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp (command, INTEREST) == 0) {

			calculate_interest();
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");
		}

		else if (strcmp (command, HELP) == 0) {
				
			printf ("\nBelow are the commands to operate this program: \n\n");
			printf ("'hcf' to find the highest common factor\n");
			printf ("'lcm' to find the lowest common multiple\n");
			printf ("'factors' to print the factors of a number\n");
			printf ("'angsum' to find the angle sum of a polygon \n");
			printf ("'quad' to find the roots of a quadratic equation\n");
			printf ("'simpfrac' to simplify a fraction\n");
			printf ("'simpsur' to simplify a surd\n");
			printf ("'addf' to add two fractions\n");
			printf ("'subf' to subtract two fractions\n");
			printf ("'mulf' to multiply two fractions\n");
			printf ("'divf' to divide two fractions\n");
			printf ("'interest' to calculate simple or compound interest\n");
			printf ("'circle' to find the area/circumference of a circle\n");
			printf ("'quit' to quit the program\n");
			
			printf ("\nWhat would you like to do? ");
			strcpy (command, "TRUE"); 

		} else if (strcmp(command, SIMPLIFY_SURD) == 0) {
				
			simplify_surd();
			printf ("What would you like to do? ");
			strcpy (command, "TRUE");

		} else if (strcmp(command, CIRCLE) == 0) {

			char answer [20]; 
			double radius = 0;

			printf ("Enter the radius: ");
			scanf ("%lf", &radius);

			printf ("Would you like to find the area or circumference? ");
			scanf ("%s", answer);

			if (strcmp (answer, "area") == 0) {
					circle_area(radius);
			} else if (strcmp (answer, "circumference") == 0) {
				circle_circum(radius);
			} else {
				printf ("Invalid command, try again.\n");
				main();
			}
			printf ("\nWhat would you like to do? ");
			strcpy (command, "TRUE");
		}
                
	}       
	printf("Goodbye!\n");
	return 0;
}
//
//Finds the angle sum of a shape with a given number of sides
//
void angle_sum() {

	int sides = 0, sum = 0;
	printf("How many sides does your shape have? ");
	scanf ("%d", &sides);

	sum = (sides - 2)  * 180;

	printf("The angle sum of a shape with %d sides is %d degrees.\n", sides, sum);

}
//
//Finds the highest common factor between two given numbers
//
int common_factor (int num1, int num2) {

        //holds factors for first number and second number respectively
	int factors1[MAX_STRING_LENGTH] = {0}; 
	int factors2[MAX_STRING_LENGTH] = {0};

        //calculates factors of num1 and stores in factors1
	int i = 1;
	int j = 0;
	while (i <= num1) {
		if (num1 % i == 0) {
			factors1[j] = i;
			j++;
		}
		i++;
	}

         //calculates factors of num2 and stores in factors2
	i = 1;
	j = 0;
	while (i <= num2) {
		if (num2% i == 0) {
			factors2[j] = i;
			j++;
		}
		i++;
	}

	int comfact = -10; //-10 is chosen as a debugging number, we know if the program outputs -10 then we know there is a problem

	i = 0;
	j = 0;
	
	//compares one element from factors1 to every element of factors2
	//and stores in comfact, then moves to second element of factors1
	//and repeats the process
	int k = 0;
	if (num1 > num2) {
		while (factors1[i] != 0) {   
			while (factors2[j] != 0) {
				if (factors1[i] == factors2[j]) {
					comfact = factors1[i];
				}
				j++;
				k++;
			}
			i++;
			j = 0;
			k = 0;
		}
	} else { //same as above, slightly changed for if num2 > num1
		while (factors2[i] != 0) {   
			while (factors1[j] != 0) {
				if (factors2[i] == factors1[j] && factors2[i]>comfact) { 
					comfact = factors2[i];
				}
				j++;
				k++;
			}
			i++;
			j = 0;
			k = 0;
		}
	}

	return comfact;

}

// Given a raw string will remove and first newline it sees.
// The newline character wil be replaced with a null terminator ('\0')
void remove_newline(char input[MAX_STRING_LENGTH]) {

    // Find the newline or end of string
    int index = 0;
    while (input[index] != '\n' && input[index] != '\0') {
        index++;
    }
    // Goto the last position in the array and replace with '\0'
    input[index] = '\0';
}

void quadratic (){

	float a, b, c, root1, root2;

	printf ("Enter a, b and c respectively: ");
	scanf ("%f %f %f", &a, &b, &c);

	float discriminant = b * b - 4 * a * c;
	
	if (discriminant < 0) {
		printf ("No real roots.\n");
		return;
	} else if (discriminant == 0) {
		root1 = -1 * b / (2 * a);
		printf ("Two equal roots:\n Root is %.5f\n", root1);
	} else if (discriminant > 0) {
		root1 =(-1 * b + sqrt(discriminant)) / (2 * a);
		root2 =(-1 * b - sqrt(discriminant)) / (2 * a);
		printf ("Two real roots: %.5f and %.5f\n", root1, root2);
	}
}
void simplify_fraction(int num1, int num2) {

	//find the highest common factor
	int comfact = common_factor(num1, num2);

	int numerator = num1 / comfact;
	int denominator = num2 / comfact;

	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}

	printf ("%d/%d\n", numerator, denominator);
}
void add_fractions (int num1, int denom1, int num2, int denom2) {

	int numerator = num1 * denom2 + num2 * denom1;
	int denominator = denom1 * denom2;

	simplify_fraction (numerator, denominator);
}
void sub_fractions (int num1, int denom1, int num2, int denom2) {
        
	int numerator = (num1 * denom2) - (num2 * denom1);
	int denominator = denom1 * denom2;

	simplify_fraction (numerator, denominator);

}
void mul_fractions (int num1, int denom1, int num2, int denom2) {

	int numerator = num1 * num2;
	int denominator = denom1 * denom2; 

	simplify_fraction (numerator, denominator);

}

void div_fractions (int num1, int denom1, int num2, int denom2) {

	int temp = num2;
	num2 = denom2;
	denom2 = temp;

	mul_fractions (num1, denom1, num2, denom2);
}
void simplify_surd() {

	//initialise as 1 to allow division
	double surd, outside_num = 1;
	double counter = 1;

	printf ("Enter your surd in the form 'sqrt [number]': ");
	scanf ("sqrt %lf", &surd);

	while (pow(counter, 2) <= surd) {

		//find the largest square number that is a factor of the surd
		if ((fmod (surd, pow(counter, 2))) == 0) {
				outside_num = counter;
		}
		counter++;
	}
	int inside_num = (surd / pow(outside_num, 2));

	if (inside_num == 1) {
		printf ("%.0lf\n", outside_num);
	} else if (outside_num == 1) {
		printf ("Cannot be simplified.\n");
	} else {
		printf ("%.0lfsqrt%d\n", outside_num, inside_num);
	}
}
void calculate_interest () {

	char answer [10];
	double principal, time, interest = 0;
	double rate = 0;
	printf ("\nSimple or compound interest? ");
	scanf ("%s", answer);

	if (strcmp (answer, "simple") == 0) {
                
		printf ("Enter values for principal, rate and time respectviely (make sure rate and time are in the same units): ");
		scanf ("%lf %lf %lf", &principal, &rate, &time);
		
		rate = rate / 100;
		interest = principal * rate * time;
		double total = principal + interest;
		
		printf ("The interest is $%.2lf\n", interest);
		printf ("The total is $%.2lf\n\n", total);

	} else if (strcmp (answer, "compound") == 0) {
			
		printf ("Enter values for principal, rate and time respectively (make sure rate and time are in the same units): ");
		scanf ("%lf %lf %lf", &principal, &rate, &time);
		
		rate = rate / 100;
		double total = principal * pow((1 + rate), time);
		interest = total - principal;
		
		printf ("The interest is $%.2lf\n", interest);
		printf ("The total is $%.2lf\n\n", total);
			
	} else {

		printf ("\nInvalid command, try again.\n");
		calculate_interest();

	}

}
void circle_area (double radius) {

	double area = M_PI * pow(radius, 2);
	printf ("The area is %.2lf (2.d.p)\n", area);

}
void circle_circum(double radius) {

	double circumference = 2 * M_PI * radius;
	printf ("The circumference is %.2lf (2.d.p)\n", circumference);

}
int lowest_common_multiple(int num1, int num2) {

	int max = 1;

	while ((max % num1 != 0) || (max % num2 != 0)) {
		max++;
	}

	return max;

}
void list_factors (int num1) {

    int counter = 1;

    while (counter <= num1) {

        if (num1 % counter == 0) {
            printf ("%d ", counter);
        }
        counter++;

    }
    printf ("\n\n");

}