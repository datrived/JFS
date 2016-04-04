#include "header1.h"

void commit(int id)
{
struct var_data *data=NULL;

fp_version_storage=fopen("version_storage.txt","r+b");
data=read_data();

while(data->caller_id != id)
{
data=data->next;
}

data->status=COMMITTED;

write_data(data);
fclose(fp_version_storage);
free(data);
return;
}
