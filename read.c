#include "header1.h"



int read_current_value(int did,int cid)
{
int s;
struct var_data *data1=NULL;
//fp_cell_storage=fopen("cell_storage_file.txt","r+b");
fp_version_storage=fopen("version_storage.txt","r+b");
data1=read_data();

while(data1->next != NULL)
{
data1=data1->next;
}

while(data1->prev != NULL)
{

if(data1->data_id==did)
{
s=data1->status;
  if(s==COMMITTED)
   {
   return data1->data;
   }

}
data1=data1->prev;
}
free(data1);
fclose(fp_version_storage);

printf("\n Tried to read an uninitialized value...");
}
