#include "header1.h"

int transfer(int daccount,int caccount,int amount)
{
int caller_id1,caller_id2,xvalue,yvalue;

caller_id1=new_action(daccount);
caller_id2=new_action(caccount);

xvalue=read_current_value(daccount,caller_id2);
xvalue=xvalue-amount;
write_new_value(daccount,xvalue,caller_id2);

yvalue=read_current_value(caccount,caller_id2);
yvalue=yvalue+amount;
write_new_value(caccount,yvalue,caller_id2);

if(xvalue>0)
{
commit(caller_id2);
}
else
{
abort1(caller_id2);
printf("\n Negative transfer are not allowed...");
}
return caller_id2;
}


void application()
{
int id;
printf("\n before allocating");
allocate();
allocate();
allocate();
printf("\n after allocating");
//id=new_action(DEBIT);
/*id=transfer(DEBIT,CREDIT,500);
printf("\n after transfer");
read_account(DEBIT,id);
read_account(CREDIT,id);*/
return;
}

void read_account(int did,int cid)
{

struct var_data *data1=NULL;
fp_version_storage=fopen("version_storage.txt","r+b");

data1=read_data();

while(data1->next !=NULL)
{
data1=data1->next;
}

while(data1->prev!=NULL)
{

if(data1->data_id==did)
{
printf("\n %d",data1->data);
free(data1);
fclose(fp_version_storage);
return;

}

data1=data1->prev;
}
free(data1);
fclose(fp_version_storage);
printf("\n no data found");

return;
}

