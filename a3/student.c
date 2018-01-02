#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "student.h"

void printStudentList(struct person c){
	char fullName[33];
	sprintf(fullName, "%s %s", c.firstName, c.familyName);

	printf("%-33s GPA: %d, Courses: %d, Tuition: %.2f \n", fullName, c.stu.gpa, c.stu.numCourses, c.stu.tuitionFees);
}

