/* Approach 2 : student2.c : Adds collision handling on approach 1.
 *    Uses chaining.
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LEN 30
#define MAX_ADDRESS_LEN 80
#define MAX_DEPT_LEN 20

typedef struct student
{
   char name[MAX_NAME_LEN]; // Assume it is a unique Key
   int  rollno;
   char address[MAX_ADDRESS_LEN];
   int  age;
   char dept[MAX_DEPT_LEN];
 
   struct student *next; // NOTICE IT : added to implement chains in the buckets
} student_t;


/* Hash Table : Array of linked lists. Each bucket is a (possibly empty) chain*/
#define NUM_BUCKETS 5
student_t *hash_tbl[NUM_BUCKETS];

/* Function : hash_func */
/* Implementation 1 : return the index starting from 'a' modullo size */
int hash_func(char *name)
{
   return (tolower(name[0]) - 'a') % NUM_BUCKETS;
}

/* Function : Initialize the hash table */
void hash_tbl_init(student_t *hash_tbl[NUM_BUCKETS])
{
   int i;
   for(i=0;i<NUM_BUCKETS;i++)
     hash_tbl[i] = NULL;
}

/* Function : Insert an entry into the hash table */
int insert_hash_tbl(student_t *hash_tbl[NUM_BUCKETS],
     char name[], int rollno, char address[], int age, char dept[])
{
   int index;
   student_t *p_rec;

   /* Generate Index */
   index = hash_func(name);
   printf("insert_hash_tbl : index = %d\n", index);

   /* Add at begining of linked list : O(1) */
   p_rec = (student_t *) malloc(sizeof(student_t));
   //TBD : error check on p_rec;
   /* Copy Data */
   strcpy(p_rec->name, name); 
   p_rec->rollno = rollno;
   strcpy(p_rec->address, address); 
   p_rec->age = age;
   strcpy(p_rec->dept, dept); 

   /* Set pointers, so as to en-chain the new node at the beginning */
   p_rec->next = hash_tbl[index];
   hash_tbl[index] = p_rec;

   /* Notice that we did not do duplicate key check. If we want to ensure uniqueness, we may 
    * want to do duplicate check, which will ofcourse require O(K) traversal through the list.
    * (K is expected length of linked list. i.e. expected number of colliding entries in one 
    *  bucket)
    */
   
   return 1; // SUCCESS
}

/* Function : To search the hash table for a given element.
 * hash_tbl and name are INPUT parameters.
 * other arguments are OUTPUT parameters.
 */
int search_hash_tbl(student_t *hash_tbl[NUM_BUCKETS],
     char name[], int *p_rollno, char address[], int *p_age, char dept[])
{
   int index;
   student_t *p_rec;

   /* Generate Index */
   index = hash_func(name);
   printf("search_hash_tbl : index = %d\n", index);

   p_rec = hash_tbl[index];

   while (p_rec != NULL)
   {
      if (strcmp(p_rec->name, name) == 0)
      {
        /* Copy Data */
        strcpy(name, p_rec->name); 
        *p_rollno = p_rec->rollno;
        strcpy(address, p_rec->address); 
        *p_age = p_rec->age;
        strcpy(dept, p_rec->dept); 
        return 1; // SUCCESS. Found it
      }

      // Move to next node
      p_rec = p_rec->next;
   }

   return 0; // FAILURE. Did not find it
}

/* Function : To delete a given element from the hash table 
 */
int delete_hash_tbl_elem(student_t *hash_tbl[NUM_BUCKETS], char name[])
{
   int index;
   student_t *p_rec, *p_prev; // p_rec : the node to be deleted. p_prev : previous node

   /* Generate Index */
   index = hash_func(name);
   printf("delete_hash_tbl_elem : index = %d\n", index);

   p_rec = hash_tbl[index];
   p_prev = NULL;

   while (p_rec != NULL)
   {
      if (strcmp(p_rec->name, name) == 0)
      {
        // Found it.
        if (p_prev != NULL)
          p_prev->next = p_rec->next;
        else
           hash_tbl[index] = p_rec->next;
        free(p_rec);
        return 1; // SUCCESS. found it. Deleted it.
      }

      /* Keep Looking. Move pointers. */
      p_prev = p_rec;
      p_rec = p_rec->next;
  }

   return 0; // FAILURE. did not find it
}

/* Function : To print the hash table
 */
void print_hash_tbl(student_t *hash_tbl[NUM_BUCKETS])
{
   int i;
   student_t *p_rec;
   printf("The elements in hash table are:\n");
   for(i=0;i<NUM_BUCKETS;i++)
   {
     p_rec = hash_tbl[i];
     printf("Chain at Bucket %d:\n", i);
     while (p_rec != NULL)
     {
        printf("<name=%s, rollno=%d, address=%s, age=%d, dept=%s>\n",
       p_rec->name, p_rec->rollno, p_rec->address, p_rec->age, p_rec->dept);
        p_rec = p_rec->next;
     }
   }
}

int main()
{
  int choice, rollno, age, ret;
  char name[MAX_NAME_LEN], address[MAX_ADDRESS_LEN], dept[MAX_DEPT_LEN];

  /* Initialize hash table */
  hash_tbl_init(hash_tbl);

  while (1)
  {
    printf(" 1)Print Hash Table\n");
    printf(" 2)Insert Record\n");
    printf(" 3)Search Record\n");
    printf(" 4)Delete Record\n");
    printf(" 0)Exit\n");
    printf(" What do you want to do?");
   
    scanf("%d", &choice);
    switch(choice)
    {
       case 1: /* Print Hash Table */
         print_hash_tbl(hash_tbl);
         break;

       case 2: /* Insert */
         printf("Enter name rollno address age dept\n");
         scanf("%s%d%s%d%s", name, &rollno, address, &age, dept);
         ret = insert_hash_tbl(hash_tbl, name, rollno, address, age, dept);
         if (ret == 1)
           printf("insert_hash_tbl succeeded\n");
         else
           printf("insert_hash_tbl failed\n");
         break;

       case 3: /* Search */
         printf("Which name do you want to search?\n");
         scanf("%s", name);

         ret = search_hash_tbl(hash_tbl, name, &rollno, address, &age, dept);
         if (ret == 1)
           printf("search_hash_tbl succeeded\nname=%s, rollno=%d, address=%s, age=%d, dept=%s",
                   name, rollno, address, age, dept);
         else
           printf("search_hash_tbl failed\n");
         break;

       case 4: /* Delete */
         printf("Which name do you want to delete?\n");
         scanf("%s", name);

         ret = delete_hash_tbl_elem(hash_tbl, name);
         if (ret == 1)
           printf("delete_hash_tbl_elem succeeded\n");
         else
           printf("delete_hash_tbl_elem failed\n");
         break;

       case 0: /* Exit */
         exit(0);

    }
  }
}
