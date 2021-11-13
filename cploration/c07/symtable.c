#include "symtable.h"
#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
struct Symbol* hashArray[SYMBOL_TABLE_SIZE];
struct Symbol* item;


void display_table() {
   int i = 0;
	
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->address);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

unsigned int hashCode(char *str)  {
  unsigned int hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash % SYMBOL_TABLE_SIZE;
}

struct Symbol *find(char *str) {
   //get the hash 
   int hashIndex = hashCode(str);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->name == str)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }        
	
   return NULL;        
}

void insert(char *key, hack_addr data) {

  struct Symbol *item = (struct Symbol*) malloc(sizeof(struct Symbol));
   item->address = data;  
   item->name = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }
	
   hashArray[hashIndex] = item;
}
/*
struct Symbol* delete(struct Symbol* item) {
   int key = item->name;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->name == key) {
         struct Symbol* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }      
	
   return NULL;        
}
*/
/*
int hashCode(char *str) {
   int hashIndex = hash(str*);  
   return hashIndex % SYMBOL_TABLE_SIZE;
}
*/
