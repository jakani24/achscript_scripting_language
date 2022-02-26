#include <iostream>
#include <windows.h>



int load_settings(int*s1,int*s2,int*s3,int*s4,int*s5);
int save_settings(int s1,int s2,int s3,int s4,int s5);
int modifie_settings();

int load_settings(int*s1,int*s2,int*s3,int*s4,int*s5)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	FILE*fp;
	char buffer[100];
	if((fp=fopen("c:\\jakach-language\\system\\settings.jl","r"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("Couldn't load settings!\n");
		SetConsoleTextAttribute(console_color, 7);
		if((fp=fopen("c:\\jakach-language\\system\\settings.jl","w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("fatale error while loading settings!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		else
		{
			fprintf(fp,"<settings>\n1 0 1 0 0\n</settings>");
			fclose(fp);
			if((fp=fopen("c:\\jakach-language\\system\\settings.jl","r"))!=0)
			{
				fscanf(fp,"%90s",&buffer);
				if((strcmp(buffer,"<settings>"))!=0)
				{
					SetConsoleTextAttribute(console_color, 4);
					printf("Error while loading settings! (settings file corrupted)\n");
					SetConsoleTextAttribute(console_color, 7);
					return 2;
				}
				else
				{
				fscanf(fp,"%d",s1);
				fscanf(fp,"%d",s2);
				fscanf(fp,"%d",s3);
				fscanf(fp,"%d",s4);
				fscanf(fp,"%d",s5);
				fclose(fp);
				}				
			}
		}
	}
	else
	{
		fscanf(fp,"%90s",&buffer);
		if((strcmp(buffer,"<settings>"))!=0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("Error while loading settings! (settings file corrupted)\n");
			SetConsoleTextAttribute(console_color, 7);
			return 2;
		}
		else
		{
		fscanf(fp,"%d",s1);
		fscanf(fp,"%d",s2);
		fscanf(fp,"%d",s3);
		fscanf(fp,"%d",s4);
		fscanf(fp,"%d",s5);
		fclose(fp);
		}
		return 0;
	}
	
}

int modifie_settings()
{
	int s1,s2,s3,s4,s5;
	char input[10];
	system("cls");
	load_settings(&s1,&s2,&s3,&s4,&s5);
	//printf("nothing to do here\n");
	printf("--security:--\n\n");
	printf("get notified, if a script tries to run cmd functions[1]. currently %s\n", s1 ? "true" : "false");
	printf("get notified, for each and every cmd command, that the script tries to run[2]. currently %s\n", s2 ? "true" : "false");
	printf("let a script run extern functions[3]. currently %s\n", s3 ? "true" : "false");
	printf("\n--error handling--\n\n");
	printf("Cancel script execution at error occurrence[4]. currently %s\n", s4 ? "true" : "false");
	printf("\n\nexit settings[99]\n");
	scanf("%5s",&input);
	if((strcmp(input,"1"))==0)
	{
		printf("\nchanging setting, please wait\n");
		if(s1==true)
		{
			s1=false;
		}
		else
		{
			s1=true;
		}
		printf("setting changed\n");
	}
	else if((strcmp(input,"2"))==0)
	{
		printf("\nchanging setting, please wait\n");
		if(s2==true)
		{
			s2=false;
		}
		else
		{
			s2=true;
		}
		printf("setting changed\n");		
	}
	else if((strcmp(input,"3"))==0)
	{
		printf("\nchanging setting, please wait\n");
		if(s3==true)
		{
			s3=false;
		}
		else
		{
			s3=true;
		}
		printf("setting changed\n");		
	}
	else if((strcmp(input,"4"))==0)
	{
		printf("\nchanging setting, please wait\n");
		if(s4==true)
		{
			s4=false;
		}
		else
		{
			s4=true;
		}
		printf("setting changed\n");		
	}
	save_settings(s1,s2,s3,s4,s5);
}

int save_settings(int s1,int s2,int s3,int s4,int s5)
{
	FILE*fp;
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	if((fp=fopen("c:\\jakach-language\\system\\settings.jl","w"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("Couldn't save settings!\n");
		SetConsoleTextAttribute(console_color, 7);
		return 1;
	}
	else
	{
		fprintf(fp,"<settings>\n");
		fprintf(fp,"%d %d %d %d %d\n",s1,s2,s3,s4,s5);
		fprintf(fp,"</settings>\n");
		fclose(fp);
		return 0;
	}
}