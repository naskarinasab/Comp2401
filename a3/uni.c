

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "populateRecords.h"
#include "student.h"
#include "employee.h"

#define NUM_RECORDS 20

/*Prototypes*/
int menu();
void quit();

int main()
{
    int input;
	int p;
    struct person person[NUM_RECORDS];
    populateRecords(person, NUM_RECORDS);
    input = menu();
    switch(input){
		case 0:
			quit();
			break;

		case 1:
			for(int i = 0; i<21; i++){
				if(person[i].employeeOrStudent == 0){
					printEmployeeList(person[i]);
				}
			}
			break;
		case 2:
			for(int i = 0; i<21; i++){
				if(person[i].employeeOrStudent == 1){
					printStudentList(person[i]);
				}
			}
			break;
		case 3:
			printf("Done\n");
			break;
		case 4:
			printf("Done\n");
			break;
		default:
			printf("Done\n");
			break;

	}


    return 0;
}


int menu(){
	int result;
	printf("Welcome to the menu. Please choose an option:\n");
	printf("1. Print all employees\n");
	printf("2. Print all students\n");
	printf("3. Search students using Family Name\n");
	printf("4. Summary of data\n");
	printf("0. Quit\n");
	printf("Please choose one of the options (enter 0-4): ");
	scanf("%d", &result);
	
	if(result< 0 || result>4){
		printf("Sorry that is not a valid option. \n");
		printf("\n");
		result = menu();
	}
	
	return result;
}

void quit(){
	char result;
	printf("Are you sure you want to quit? (y/n): ");
	scanf("%s", &result);

	if(result == 'y'){
		exit(0);
	}
	else if(result == 'n'){
		menu();
	}
	else{
		printf("Sorry that is not a valid option. \n");
		printf("\n");
		quit();
	}
}
