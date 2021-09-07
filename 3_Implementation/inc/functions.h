#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define Employee struct emp
FILE * del(FILE * fp);//to delete from list
void displaybasic();
void basiccontact();
void maleemp();
void femaleemp();
void frmindia();
void mainbr();
void otherbr();


void add(FILE * fp); //to add to list
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();



#endif