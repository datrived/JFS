#include "header1.h"



int id1=0;
int data_id1=0;



void allocate()
{
long int x;
fp_cell_storage=fopen("cell_storage_file.dsk","r+");
printf("\n 1...\n");
if(fp_cell_storage==NULL)
printf("\n this is problem...");

struct var_data *node2=(struct var_data*)malloc(sizeof(struct var_data));

node2->data_id=data_id1+1;
data_id1=data_id1+1;
node2->action_id=1;
node2->caller_id=id1+1;
id1=id1+1;

node2->status=COMMITTED;
node2->data=3000;

printf("\n here...");
x=VAR_DATA_OFFSET + (node2->caller_id)*OFFSET;

printf("\n %ld ",x);


printf("\n before write");
fseek(fp_cell_storage,x,SEEK_SET);

printf("\n after seek...");







fwrite(node2,sizeof(struct var_data),1,fp_cell_storage);




printf("\n after write");




fclose(fp_cell_storage);

printf("\n after close");

free(node2);
printf("\n after free");
return;
}







int new_action()
{
int id;
int i=1;
long int x;
struct var_data *node=NULL;
printf("\n here");
fp_cell_storage=fopen("cell_storage_file.dsk","r+");

printf("\n after:");
struct var_data *data=(struct var_data*)malloc(sizeof(struct var_data));
printf("\n here2");
x=VAR_DATA_OFFSET + OFFSET;
printf("\n %ld ",x);
fseek(fp_cell_storage,x,SEEK_SET);
fread(node,1,sizeof(struct var_data),fp_cell_storage);

printf("\n first...");
while(!node->caller_id)
{
i++;
x=VAR_DATA_OFFSET + i * OFFSET;
fseek(fp_cell_storage,x,SEEK_SET);
fread(node,1,sizeof(struct var_data),fp_cell_storage);
printf("\n i=%d th",i);
}
data->data_id=data_id1+1;
data_id1=data_id1+1;
data->caller_id=i;
data->action_id=1;
data->status=PENDING;
x=VAR_DATA_OFFSET + OFFSET*i;
id=i;

fseek(fp_cell_storage,x,SEEK_SET);
fwrite(data,sizeof(struct var_data),1,fp_cell_storage);
fclose(fp_cell_storage);
printf("\n after write");

return id;
}
