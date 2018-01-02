#include "stdio.h"
#include "struct.h"
#include "employee.h"
#include "stdlib.h"


void printEmployeeList(struct person c){
	char fullName[33];
	sprintf(fullName, "%s %s", c.firstName, c.familyName);

	printf("%-33s Years: %d, Level: %d, Salary: %.2f \n", fullName, c.emp.yearsService, c.emp.level, c.emp.salary);
}

