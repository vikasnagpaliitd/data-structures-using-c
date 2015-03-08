#include <stdio.h>

#define MAX_NAME_LEN 30
#define MAX_ADDRESS_LEN 80
#define MAX_DEPT_LEN 20

typedef struct student_record
{
   char name[MAX_NAME_LEN]; // Assume it is a unique Key
   int  rollno;
   char address[MAX_ADDRESS_LEN];
   int  age;
   char dept[MAX_DEPT_LEN];
} student_record_t;


/* Hash Table
 * 1) Option 1 : array of structures
 * 2) Option 2 : array of pointer to struct
 */
/* Empty entry is indicated by name being "" */
#define MAX_NUM_BUCKETS 5
student_record_t hash_tbl[MAX_NUM_BUCKETS];

/* Function : Initialize the hash table */
void init_hash_tbl(student_record_t hash_tbl[MAX_NUM_BUCKETS])
{
   int i;
   for(i=0;i<MAX_NUM_BUCKETS;i++)
     hash_tbl[i].name[0] = '\0';
}

int main()
{
  int choice, rollno, age;
  char name[MAX_NAME_LEN], address[MAX_ADDRESS_LEN], dept[MAX_DEPT_LEN];

  /* Initialize hash table */
  init_hash_tbl(hash_tbl);

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
         ret = search_hash_tbl(hash_tbl, name, &rollno, address, &age, dept);
         if (ret == 1)
           printf("search_hash_tbl succeeded\nname=%s, rollno=%d, address=%s, age=%d, dept=%s",
                   name, rollno, address, age, dept);
         else
           printf("search_hash_tbl failed\n");
         break;

       case 4: /* Delete */
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
