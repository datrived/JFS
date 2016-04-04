#ifndef HEAD

#define HEAD

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#define SIZE_OF_CELL_STORAGE 1024*10240


#define VAR_DATA_OFFSET 10240

#define PENDING 1
#define COMMITTED 2
#define ABORTED 3

#define DEBIT 2
#define CREDIT 3


#define OFFSET 1024



extern int id1;
extern int data_id1;


FILE *fp_cell_storage;



struct var_data
{

int data_id;
int data;
int status;
int caller_id;
int action_id;
};




extern void boot_cell_storage();


extern void allocate();




#endif

