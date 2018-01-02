
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Created By
 Doron Nussbaum 2016
 
 Modifications:
 November 2017 - minor modifications
 
 
 Copyright 2017
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName)
{
	// allocate memory
	PersonalInfo *p = NULL;
	p = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	if(p==NULL) return NULL;

	// set the data
    	p->id = id;
	strcpy(p->firstName, firstName);
	strcpy(p->familyName, familyName);

	// make new node point to first node of list
	p->next = *head;
	
	//update the head
	*head = p;
	return p;
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	// allocate memory
	PersonalInfo *p = NULL;
	p = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	if(p==NULL) return NULL;

	// set the data
   	p->id = id;
	strcpy(p->firstName, firstName);
	strcpy(p->familyName, familyName);

	//put p in between node and node->next
	p->next = node->next;
	node->next = p;
	return p;
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	// allocate memory
	PersonalInfo *p = NULL;
	p = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	
	PersonalInfo *temp = NULL;
	temp = *head;
	if(p==NULL) return NULL;

	// set the data
    	p->id = id;
	strcpy(p->firstName, firstName);
	strcpy(p->familyName, familyName);

	if(listSize(temp) == 0){ //size is nothing
		*head = p; //update the head
		return p;
	}
	/*FINDING THE LAST ONE*/
	while(temp->next != NULL){
		temp = temp->next;	
	}

	// make new node point to last node of list
	temp->next = p;
	p->next = NULL;

	return p;

}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{
	if(head == NULL) return NULL; //if list is empty
	
	while(head!= NULL){
		if(strcmp(head->firstName, firstName) ==0) return head;
		head = head->next;
	}
	return NULL;
}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	while(head!= NULL){
		if(head->id == id) return head;
		head = head->next;
	}
	return NULL;
    
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName)
{

	if(*head == NULL) return 1; //list is empty
	PersonalInfo *toDelete = *head;
	// set the data
    	*id = toDelete->id;
	strcpy(firstName, toDelete->firstName);
	strcpy(familyName, toDelete->familyName);
	// update head
	*head = toDelete->next;
	free(toDelete);
	
	return 0;
}


/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id,
                char *firstName, char *familyName)

{
   	if(*head == NULL) return 1; //list is empty
	PersonalInfo *p = *head;
	// set the data
    	*id = p->id;
	strcpy(firstName, p->firstName);
	strcpy(familyName, p->familyName);
	if(listSize(*head) == 1){ //1 nodess
		*head = NULL;
		free(p);
		return 0;
	}
	//find the last node
	while(p->next->next !=NULL){
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	return 0;
}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id, char *firstName, char *familyName)
{
   	if (node == NULL || node->next == NULL) return 1;
	PersonalInfo *toDelete = node->next;
	//link the node before the deleted node with the one after deleted node
	node->next = toDelete->next;
	// set the data
    	*id = toDelete->id;
	strcpy(firstName, toDelete->firstName);
	strcpy(familyName, toDelete->familyName);
	
	free(toDelete);
	return 0;
}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName, char *familyName, unsigned int *id){
	// list is empty
	if (*head == NULL) return 1;
	PersonalInfo *toDelete = NULL;
	PersonalInfo *p = NULL;
	toDelete = *head;
	//not empty so find the match
	while(toDelete != NULL && strcmp(toDelete->firstName, firstName) != 0){
			p = toDelete;
			toDelete = toDelete->next;
	}
	// No match = no bueno
	if(toDelete == NULL) return 1;

	// if the match is head
	if(*head == toDelete){
		*head = toDelete->next;
		strcpy(firstName, toDelete->firstName);
		strcpy(familyName, toDelete->familyName);
		*id = toDelete->id;
		free(toDelete);
		return 0;
	}
	strcpy(firstName, toDelete->firstName);
	strcpy(familyName, toDelete->familyName);
	*id = toDelete->id;
	p->next = toDelete->next;
	free(toDelete);
	return 0;
}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	//create current and next pointers
	PersonalInfo *current = NULL;
	PersonalInfo *next = NULL;
	//iterate through the list
	while(current != NULL) {
		//set next to the current nodes next node
		next = current->next;
		//free the current node memory
		free(current);
		//set current next
		current = next;
	}
	//set head to null
	*head = NULL;
}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	PersonalInfo *current= head;
	//iterate through list
	while (current != NULL) {
		//print the current node
		printNode(current);
		//set current to the next node
		current = current->next;
	}

}
/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	int i = 0;
	while(head!= NULL){
		i++;
		head = head->next;
	}
	return i;
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName)
{
	int i = 0;
	if(head == NULL) return 0; //if list is empty

	while(head != NULL){
		if(strcmp(head->firstName, firstName) == 0) i++;
		head = head->next;
	}
	return i;
}





/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head)
{
	// if list is empty return
	if (head == NULL) return;

	PersonalInfo *p = NULL;
	PersonalInfo *after = NULL;
	p = head;

	// remove current node if first name is same with next node 
	while (p->next != NULL){
		if (strcmp(p->firstName, p->next->firstName) == 0){
			after = p->next->next;
			free(p->next);
			p->next = after;
		}
		else{
			p = p->next;
		}
	}

}

