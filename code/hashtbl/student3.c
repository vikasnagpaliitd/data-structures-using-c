/* Approach 3 : Enhances approach 1 by adding collision handling
 *   Does Linear Probing.
 * Author: Vikas Nagpal : http://anuttaralearning.com/
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

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

   int is_deleted; // NOTICE : added flag to indicate that the element was deleted 1/0 (TRUE/FALSE)
} student_t;


/* Hash Table
 * 1) Option 1 : array of structures
 * 2) Option 2 : array of pointer to struct
 */
/* Empty entry is indicated by name being "" */
#define NUM_BUCKETS 5
student_t hash_tbl[NUM_BUCKETS];

/* FoodForThought: Refer hash_tbl array.
 * 1) We waste memory for the empty buckets. Shall we have array of pointers (where each pointer,
 *   would finally be allocated to store one student record)
 */

/* Function : hash_func */
/* Implementation 1 : return the index starting from 'a' modullo size */
int hash_func(char *name)
{
   return (tolower(name[0]) - 'a') % NUM_BUCKETS;
}

/* Function : Initialize the hash table */
void hash_tbl_init(student_t hash_tbl[NUM_BUCKETS])
{
   int i;
   for(i=0;i<NUM_BUCKETS;i++)
   {
     hash_tbl[i].name[0] = '\0';
     hash_tbl[i].is_deleted = 0; // FALSE
   }
}

/* Function : Insert an entry into the hash table */
int insert_hash_tbl(student_t hash_tbl[NUM_BUCKETS],
     char name[], int rollno, char address[], int age, char dept[])
{
   int index, last_index;
   student_t *p_rec;

  
   /* Generate Index */
   index = hash_func(name);
   printf("insert_hash_tbl : index = %d\n", index);

   // Before starting, let us know when to stop
   last_index = (index + NUM_BUCKETS - 1) % NUM_BUCKETS;
   // Look for an empty slot. If this slot busy, try the next one (+1) 
   while ((strcmp(hash_tbl[index].name, "") != 0) && (index != last_index))
   {
      printf("Index %d is OCCUPIED with name %s\n", index, hash_tbl[index].name);
      index = (index + 1) % NUM_BUCKETS;
   }

   if (strcmp(hash_tbl[index].name, "") != 0)
   {
     printf("Could not find an empty slot\n");
     assert(index == last_index);
     return 0; // FAILURE
   }
   
   printf("Storing the data at index %d\n", index); 
   /* Copy Data */
   p_rec = &hash_tbl[index];
   strcpy(p_rec->name, name); 
   p_rec->rollno = rollno;
   strcpy(p_rec->address, address); 
   p_rec->age = age;
   strcpy(p_rec->dept, dept); 
  
   // reset the flag 
   p_rec->is_deleted = 0; // FALSE

   return 1; // SUCCESS
}

/* Function : To search the hash table for a given element.
 * hash_tbl and name are INPUT parameters.
 * other arguments are OUTPUT parameters.
 */
int search_hash_tbl(student_t hash_tbl[NUM_BUCKETS],
     char name[], int *p_rollno, char address[], int *p_age, char dept[])
{
   int index, last_index;
   student_t *p_rec;

   /* Generate Index */
   index = hash_func(name);
   printf("search_hash_tbl : index = %d\n", index);

   // Before starting, let us know when to stop
   last_index = (index + NUM_BUCKETS - 1) % NUM_BUCKETS;
   while ((strcmp(hash_tbl[index].name, name) != 0) && (index != last_index))
   {
      if ((strcmp(hash_tbl[index].name, "") == 0) && (hash_tbl[index].is_deleted == 0))
      {
          printf("Found empty (non-deleted) slot at index %d index... stopping.\n", index);
          return 0; // no hope of finding it. return FAILURE
      }

      printf("Looked at Index %d name=[%s], is_deleted=%d... Trying next...\n", index, hash_tbl[index].name, hash_tbl[index].is_deleted);

      // Keep Looking
      index = (index + 1) % NUM_BUCKETS;
   }

   // We come here if 1) we find the element or 2) table is completely full
   if (strcmp(hash_tbl[index].name, name) == 0)
   {
     // Found the element
     p_rec = &hash_tbl[index];
     strcpy(name, p_rec->name); 
     *p_rollno = p_rec->rollno;
     strcpy(address, p_rec->address); 
     *p_age = p_rec->age;
     strcpy(dept, p_rec->dept); 
     printf("Found:hash_tbl[%d]=<name=%s, rollno=%d, address=%s, age=%d, dept=%s>\n",
    index, p_rec->name, p_rec->rollno, p_rec->address, p_rec->age, p_rec->dept);
     return 1; // SUCCESS
   }
    
   printf("Could not find the element. Checked the full hash table\n");
   return 0; // FAILURE
}

/* Function : To delete a given element from the hash table 
 */
int delete_hash_tbl(student_t hash_tbl[NUM_BUCKETS], char name[])
{
   int index, last_index;
   student_t *p_rec;

   /* Generate Index */
   index = hash_func(name);
   printf("delete_hash_tbl : index = %d\n", index);

   // Before starting, let us know when to stop
   last_index = (index + NUM_BUCKETS - 1) % NUM_BUCKETS;
   while ((strcmp(hash_tbl[index].name, name) != 0) && (index != last_index))
   {
      if ((strcmp(hash_tbl[index].name, "") == 0) && (hash_tbl[index].is_deleted == 0))
      {
          printf("Found empty (non-deleted) slot at index %d index... stopping.\n", index);
          return 0; // no hope of finding it. return FAILURE
      }

      printf("Looked at Index %d name=[%s], is_deleted=%d... Trying next...\n", index, hash_tbl[index].name, hash_tbl[index].is_deleted);

      // Keep Looking
      index = (index + 1) % NUM_BUCKETS;
   }

   // We come here if 1) we find the element or 2) table is completely full
   if (strcmp(hash_tbl[index].name, name) == 0)
   {
     // Found the element
     p_rec = &hash_tbl[index];
     printf("Found:hash_tbl[%d]=<name=%s, rollno=%d, address=%s, age=%d, dept=%s>\n",
    index, p_rec->name, p_rec->rollno, p_rec->address, p_rec->age, p_rec->dept);

     strcpy(hash_tbl[index].name, "");
     hash_tbl[index].is_deleted = 1; // Set flag to TRUE
     return 1; // SUCCESS
   }
    
   printf("Could not find the element. Checked the full hash table\n");
   return 0; // FAILURE
}

/* Function : To print the hash table
 */
void print_hash_tbl(student_t hash_tbl[NUM_BUCKETS])
{
   int i;
   student_t *p_rec;
   printf("The elements in hash table are:\n");
   for(i=0;i<NUM_BUCKETS;i++)
   {
     if (strcmp(hash_tbl[i].name, "") != 0)
     {
        p_rec = &hash_tbl[i];
        printf("hash_tbl[%d]=<name=%s, rollno=%d, address=%s, age=%d, dept=%s>\n",
       i, p_rec->name, p_rec->rollno, p_rec->address, p_rec->age, p_rec->dept);
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

         ret = delete_hash_tbl(hash_tbl, name);
         if (ret == 1)
           printf("delete_hash_tbl succeeded\n");
         else
           printf("delete_hash_tbl failed\n");
         break;

       case 0: /* Exit */
         exit(0);

    }
  }
}
