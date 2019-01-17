/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.cpp
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of dictionary.h.
 * ----------------------------------------------------------
 */
 #include "dictionary.h"
 #include <stdlib.h>
 #include <string.h>

 typedef struct NodeImplementation* Node;

 struct NodeImplementation
 {
   const char* word;
   struct NodeImplementation* next;
 };

 struct DictionaryImplementation
 {
   int length;
   Node head;
   Node current; //added a new Node current which is used for iterating through the list
 };


 Dictionary new_dictionary()
 {
   Dictionary dict = (Dictionary)malloc(sizeof(DictionaryImplementation));
   dict->head = 0;
   dict->length = 0;
   return dict;
 }

 void delete_dictionary (Dictionary dictionary)
 {
   Node current = dictionary->head;

   while (current != 0)
   {
     Node delete_node = current;
     current = current->next;
     sfree(delete_node);
   }
   sfree(dictionary);
 }



 void add (Dictionary dict, const char* word)
 {

     if (word == 0)return;
     Node current = dict->head;
     Node newNode = (Node)malloc(sizeof(NodeImplementation));
     newNode->word = word;
     newNode->next = 0;

     if (dict->head == 0)
     {
       dict->head = newNode;
     }
     else
     {
       while (current->next != 0)
       {
         if (current->word == word)
         {
           return;
         }
         current = current->next;
       }

       current->next = newNode;
     }
     dict->length++;
 }

 int get_size (Dictionary dict)
 {
   return dict->length;
 }

 bool is_in_dict (Dictionary dict, const char *word)
 {
   Node current = dict->head;

   while (current->next != 0)
   {
     if (strcasecmp(current->word, word) == 0) //added strcasecmp to ignore the cases.
     {
       return true;
     }
     current = current->next;
   }
   if (strcasecmp(current->word, word) == 0) //added strcasecmp to ignore the cases.
   {
     return true;
   }
   return false;
 }

 void start_iterating (Dictionary dict) //added the whole function
 {
   dict->current = dict->head;
 }

 bool has_next (Dictionary dict) //added the whole function
 {
   return dict->current != 0;
 }

 const char* get_next_entry (Dictionary dict)  //added the whole function
 {
   if(has_next(dict)){
     const char* tmp = dict->current->word;
     dict->current = dict->current->next;
     return tmp;
   }
   return 0;
 }

 void insert_sorted (Dictionary dict, const char *word) //didn't added this function, because to do this i have to change my whole code
 {
 }
