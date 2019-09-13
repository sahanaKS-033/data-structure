/*
 *	Author : Deepak
 *	Date   : 23 August 2019 
 *	Specification file for Single Linked List
 *	Contain test cases to test various functionalities
 *	of Single Linked List.
*/


#include <assert.h>
#include "slist.h"

/* test case to check creation of empty slist variable */
void test_empty_list()
{
	Slist s = slist_new();
	Slist *list = &s;
	assert (slist_length(list) == 0);
}

/*	test case to check adding node from 'head' position
 *	finding length of list and lookup functions
*/
void test_addition_at_head()
{
	Slist s = slist_new();
	Slist *list = &s;
	list = slist_add_head(list, 10);
	assert (slist_length(list) == 1);
	
	list = slist_add_head(list, 20);
	list = slist_add_head(list, 30);
	list = slist_add_head(list, 40);
	list = slist_add_head(list, 50);
	assert (slist_length(list) == 5);
	assert (slist_lookup(list, 30))

}

int main()
{
	test_empty_list();
	test_addition_at_head();
	return 0;
}

/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *	
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/