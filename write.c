#include "header1.h"

void write_new_value(int did,int new_value,int cid)
{
int cid1;
struct var_data *data1=NULL;
struct var_data *data2=NULL;
fp_version_storage=fopen("version_storage.txt","r+b");
data1=read_data();

while(data1->caller_id !=cid)
{
data1=data1->next;
}

fclose(fp_version_storage);

if(data1->status==PENDING)
{

cid1=new_action(did);
fp_version_storage=fopen("version_storage.txt","r+b");
data2=read_data();
while(data2->caller_id != cid1)
{
data2=data2->next;
}
data2->data=new_value;
fclose(fp_version_storage);
write_data(data2);
}
free(data1);
free(data2);

printf("\n Tried to write outside an all-or-nothing action...");
return;
}
