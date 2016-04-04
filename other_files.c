#include "header1.h"


void write_table(struct var_table *table)
{
int x;
while(table->next!=NULL)
{
table=table->next;
}
x=(table->data_id)*sizeof(struct var_table);
fseek(fp_cell_storage,VAR_TABLE_OFFSET, SEEK_SET);
fwrite(table,1,x,fp_cell_storage);
return;
}

void write_data(struct var_data *data)
{
int x;
while(data->next!=NULL)
{
data=data->next;
}
x=(data->caller_id)*sizeof(struct var_data);
fseek(fp_version_storage,VAR_DATA_OFFSET, SEEK_SET);
fwrite(data,1,x,fp_version_storage);
return;
}

struct var_table* read_table()
{
//int x=id*sizeof(struct var_table);
struct var_table *table=(struct var_table*)malloc(sizeof(struct var_table));
fseek(fp_cell_storage,VAR_TABLE_OFFSET, SEEK_SET);
fread(table,1,sizeof(struct var_table),fp_cell_storage);
return table;
}


struct var_data* read_data()
{
//int x=id*sizeof(struct var_data);
struct var_data *data=(struct var_data*)malloc(sizeof(struct var_data));
fseek(fp_version_storage,VAR_DATA_OFFSET,SEEK_SET);
fread(data,1,sizeof(struct var_data),fp_version_storage);
return data;
}
