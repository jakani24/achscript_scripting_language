#include <iostream>
#include <windows.h>

int num_to_char(int a,char*ptr)
{
	FILE*fp;
	char buf[20];
	if((fp=fopen("c:\\temp\\tmp.ais","w+"))==0)
	{
		return 1;
	}
	else
	{
		fprintf(fp,"%d",a);
		rewind(fp);
		fscanf(fp,"%19s",&buf);
		strcpy(ptr,buf);
		fclose(fp);
	}
	return 0;
} 

int DirectoryExists(const char* dirName) {
  DWORD attribs = ::GetFileAttributesA(dirName);
  if (attribs == INVALID_FILE_ATTRIBUTES) {
    return false;
  }
  return true;
}