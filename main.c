#include "header1.h"

int main()
{
int id;

fp_cell_storage=fopen("cell_storage_file.dsk","wb+");

printf("\n after pointer:");
boot_cell_storage();

fclose(fp_cell_storage);

allocate();
id=new_action();
/*allocate();
allocate();
*/
return 0;
}

void boot_cell_storage()
{
long int x= 1024*10240;
fseek(fp_cell_storage,x, SEEK_SET);
fputc('\n',fp_cell_storage);

return;
}

