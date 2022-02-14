#include <iostream>
#include<stdio.h>
#include <conio.h>

void getline_file(char* to_scan,int size,FILE* fp)
{
	char buffer[300];
	strncpy(to_scan,"",sizeof(""));												//clear the variable
	strncpy(buffer,"",sizeof(""));												//clear the variable
	while((strcmp(buffer,"end_of_part")!=0))				
	{
		fscanf(fp,"%250s",&buffer);
		if(strlen(to_scan)+strlen(buffer)+strlen("sys-sec")>size)				//buffer overflow preventation "sys-sec" is just a little extra buffer
		{
			strncpy(to_scan,"error",sizeof("error"));
			return;
		}
		if(strcmp(buffer,"end_of_part")!=0)
		{
			strncat(to_scan,buffer,sizeof(buffer));
			strncat(to_scan," ",sizeof(" "));
		}
	}
}

int advanced_input_scan(int return_value,char*to_scan,int max_buffer,const char attributes[300],char replace_char[5],int replace_true_false,int modyfie_in_console_true_false,char end_char[30])
{
	FILE*fp;
	int c;
	if((fp=fopen("c:\\jakach-language\\system\\input_file.ais","w"))==0)
	{
		return 1;
	}
	else
	{
		while(c!=return_value)
		{
			c=getch();
			if(replace_true_false==true)
			{
				if(c!=return_value)
				{
					printf("%s",replace_char);
				}
			}
			else
			{
				if(modyfie_in_console_true_false==false)
				{
					if(c!=return_value)
					{
						printf("%c",c);
					}
				}
				else
				{
					if((strcmp(attributes,"uppercase"))==0)
					{
						if(c<=122&&c>=97&&c!=return_value)
						{
							printf("%c",c-32);
						}
						else if(c!=return_value)
						{
							printf("%c",c);
						}
					}
					if((strcmp(attributes,"lowercase"))==0)
					{
						if(c<=90&&c>=65&&c!=return_value)
						{
							printf("%c",c+32);
						}
						else if(c!=return_value)
						{
							printf("%c",c);
						}
					}
				}
			}
			///////////////////////////////////////////////////////////////////////////////////////////7
			if((strcmp(attributes,"uppercase"))==0)
			{
				if(c<=122&&c>=97&&c!=return_value)
				{
					fprintf(fp,"%c",c-32);
				}
				else if(c!=return_value)
				{
					fprintf(fp,"%c",c);
				}
			}
			if((strcmp(attributes,"lowercase"))==0)
			{
				if(c<=90&&c>=65&&c!=return_value)
				{
					fprintf(fp,"%c",c+32);
				}
				else if(c!=return_value)
				{
					fprintf(fp,"%c",c);
				}
			}
		}
		fprintf(fp," end_of_part");
		fclose(fp);
		fp=fopen("c:\\jakach-language\\system\\input_file.ais","r");
		getline_file(to_scan,max_buffer,fp);
		fclose(fp);
		fp=fopen("c:\\jakach-language\\system\\input_file.ais","w");
		fclose(fp);
		printf("%s",end_char);
	}
	return 0;
}