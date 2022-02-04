#include <iostream>
#include<stdio.h>
#include <conio.h>

int advanced_input_scan(int return_value,char*to_scan,int max_buffer,const char attributes[300],char replace_char[5],int replace_true_false,int modyfie_in_console_true_false,char end_char[30]);
int start_script_reader(char path[300]);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
FILE*fp;
int pathok=false;
char path[300];

int main(int argc, char** argv) {
	char input[30];
	system("title jakach achscript interpretor v 1.0.0");
	system("mkdir c:\\jakach-language");
	system("mkdir c:\\jakach-language\\functions");
	system("mkdir c:\\jakach-language\\functions\\3rd_party");
	system("mkdir c:\\jakach-language\\functions\\own");
	system("mkdir c:\\jakach-language\\system");
	system("cls");
	while(true)
	{
		if(argc>=2)
		{
			argc=0;
			if((fp=fopen(argv[1],"r"))==0)
			{
				printf("File not found\n");
			}
			else
			{
				printf("File found; success!\n");
				start_script_reader(argv[1]);
			}
		}
		else
		{
			//printf("start a script[1]\nexit[2]\n");
			//scanf("%25s",&input);
			//if((strcmp(input,"1"))==0)
			//{
				while(pathok==false)
				{
					printf("Please type in the path of the script file:\n");
					if((advanced_input_scan(13,path,295,"lowercase","",false,true,"\n"))!=0)
					{
						printf("unknown error\n");
					}
					printf("path:%s\n",path);
					if((fp=fopen(path,"r"))!=0)
					{
						pathok=true;
						printf("File found; success!\n");
						start_script_reader(path);
					}
					else
					{
						printf("ERROR: file not found\n");
					}
				}
			//}
			//else if((strcmp(input,"2"))==0)
			//{
			//	exit(0);
			//}
		}
		printf("press any button except from the power button and some other non-keyboard buttons\n");
		getch();
		pathok=false;
	}
	return 0;
}