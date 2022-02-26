#include <iostream>
#include<stdio.h>
#include <conio.h>

int advanced_input_scan(int return_value,char*to_scan,int max_buffer,const char attributes[300],char replace_char[5],int replace_true_false,int modyfie_in_console_true_false,char end_char[30]);
int start_script_reader(char path[300]);
void print_help_full();
int modifie_settings();
int DirectoryExists(const char* dirName);
FILE*fp;
int pathok=false;
char path[300];

int main(int argc, char** argv) {
	system("title jakach achscript interpretor v 1.0.2");
	char input[30];
	if(( DirectoryExists("c:\\jakach-language"))==false)
	{
		system("mkdir c:\\jakach-language");
	}
	if(( DirectoryExists("c:\\jakach-language\\functions"))==false)
	{
		system("mkdir c:\\jakach-language\\functions");
	}
	if(( DirectoryExists("c:\\jakach-language\\functions\\3rd_party"))==false)
	{
		system("mkdir c:\\jakach-language\\functions\\3rd_party");
	}
	if(( DirectoryExists("c:\\jakach-language\\functions\\own"))==false)
	{
		system("mkdir c:\\jakach-language\\functions\\own");
	}
	if(( DirectoryExists("c:\\jakach-language\\system"))==false)
	{
		system("mkdir c:\\jakach-language\\system");
	}
	if(( DirectoryExists("c:\\jakach-language\\system\\if"))==false)
	{
		system("mkdir c:\\jakach-language\\system\\if");
	}
	if(( DirectoryExists("c:\\jakach-language\\system\\loop"))==false)
	{
		system("mkdir c:\\jakach-language\\system\\loop");
	}
	
//	system("mkdir c:\\jakach-language\\functions");
//	system("mkdir c:\\jakach-language\\functions\\3rd_party");
//	system("mkdir c:\\jakach-language\\functions\\own");
//	system("mkdir c:\\jakach-language\\system");
//	system("mkdir c:\\jakach-language\\system\\loop");
//	system("mkdir c:\\jakach-language\\system\\if");
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
			system("cls");
			printf("start a script[1]\nexit[2]\nsettings[3]\n");
			scanf("%25s",&input);
			if((strcmp(input,"1"))==0)
			{
				while(pathok==false)
				{
					printf("Please type in the path of the script file: ($exit to exit the achscript interpretor or $help for help)\n");
					if((advanced_input_scan(13,path,295,"lowercase","",false,true,"\n"))!=0)
					{
						printf("unknown error\n");
					}
					if((strcmp(path,"$exit "))==0)
					{
						exit(0);
					}
					else if((strcmp(path,"$help "))==0)
					{
						print_help_full();
					}
					else
					{
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
				}
			}
			else if((strcmp(input,"2"))==0)
			{
				exit(0);
			}
			else if((strcmp(input,"3"))==0)
			{
				modifie_settings();
			}
		}
		printf("press any button except from the power button and some other non-keyboard buttons\n");
		getch();
		pathok=false;
	}
	return 0;
}