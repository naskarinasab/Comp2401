#ifndef _STRUCTH_
#define _STRUCTH_
#define NAME_SIZE 15

typedef struct student{
	float tuitionFees;
	unsigned int numCourses: 6; //0-40 would be 000000-101000 so 6 bits
	unsigned int gpa: 4; //0-10 would be 0000-1010 so 4 bits

}Student;

typedef struct employee{
	float salary;
	unsigned int yearsService: 6; //0-63 would be 000000-111111 so 6 bits
	unsigned int level: 4; //1-15 would be 0001 - 1111 so 4 bits.

}Employee;

typedef struct person{
	char firstName[NAME_SIZE + 1]; //Navid, make sure /0 is avaialable. COME BACK TO THIS
	char familyName[NAME_SIZE + 1];
	char telephone[10];
	unsigned int employeeOrStudent: 1; //0 if employee and 1 if student so only 1 bit is required
	union{
		Student stu;
		Employee emp;
	};
}Person;

#endif

