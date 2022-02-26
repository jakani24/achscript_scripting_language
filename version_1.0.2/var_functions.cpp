#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <windows.h>
typedef char custom_char;
typedef int custom_int;
void getline_file(char* to_scan,int size,FILE* fp);
int load_settings(int*s1,int*s2,int*s3,int*s4,int*s5);
int main(int argc, char** argv);
custom_char char1[300],char2[300],char3[300],char4[300],char5[300],char6[300],char7[300],char8[300],char9[300],char10[300],char11[300],char12[300],char13[300],char14[300],char15[300];
custom_int int1,int2,int3,int4,int5,int6,int7,int8,int9,int10,int11,int12,int13,int14,int15;
int s1,s2,s3,s4,s5;
custom_int integers[63];

int load_int(char var_name[300])
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int cnt=0;
	FILE*variables;
	char buffer[300];
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\ints.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,var_name))!=0&&cnt!=63)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}
		if(cnt>=63)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",var_name);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return -1;
		}
		return integers[cnt];
		fclose(variables);
	}
}



int load_char(char var_name[300],char*output)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	char buffer[300];
	FILE*variables;
	int cnt=0;
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\chars.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,var_name))!=0&&cnt!=16)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}
		if(cnt==1)
		{
			strcpy(output,char1);
		}
		else if(cnt==2)
		{
			strcpy(output,char2);
		}
		else if(cnt==3)
		{
			strcpy(output,char3);
		}
		else if(cnt==4)
		{
			strcpy(output,char4);
		}
		else if(cnt==5)
		{
			strcpy(output,char5);
		}
		else if(cnt==6)
		{
			strcpy(output,char6);
		}
		else if(cnt==7)
		{
			strcpy(output,char7);
		}
		else if(cnt==8)
		{
			strcpy(output,char8);
		}
		else if(cnt==9)
		{
			strcpy(output,char9);
		}
		else if(cnt==10)
		{
			strcpy(output,char10);
		}
		else if(cnt==11)
		{
			strcpy(output,char11);
		}
		
		else if(cnt==12)
		{
			strcpy(output,char12);
		}
		else if(cnt==13)
		{
			strcpy(output,char13);
		}
		else if(cnt==14)
		{
			strcpy(output,char14);
		}
		else if(cnt==15)
		{
			strcpy(output,char15);
		}
		else
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",var_name);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return 1;
		}
		fclose(variables);
	}
}

int scan_int(char var_name[300])
{
	
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	char buffer[300];
	FILE*variables;
	int cnt=0;
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\ints.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,var_name))!=0&&cnt!=16)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}
		if(cnt>=63)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",var_name);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return 1;
		}
		scanf("%d",&integers[cnt]);
		fclose(variables);
	}
}

int scan_char(char var_name[300])
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	char buffer[300];
	FILE*variables;
	int cnt=0;
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\chars.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,var_name))!=0&&cnt!=16)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}
		if(cnt==1)
		{
			scanf("%290s",&char1);
		}
		else if(cnt==2)
		{
			scanf("%290s",&char2);
		}
		else if(cnt==3)
		{
			scanf("%290s",&char3);
		}
		else if(cnt==4)
		{
			scanf("%290s",&char4);
		}
		else if(cnt==5)
		{
			scanf("%290s",&char5);
		}
		else if(cnt==6)
		{
			scanf("%290s",&char6);
		}
		else if(cnt==7)
		{
			scanf("%290s",&char7);
		}
		else if(cnt==8)
		{
			scanf("%290s",&char8);
		}
		else if(cnt==9)
		{
			scanf("%290s",&char9);
		}
		else if(cnt==10)
		{
			scanf("%290s",&char10);
		}
		else if(cnt==11)
		{
			scanf("%290s",&char11);
		}
		else if(cnt==12)
		{
			scanf("%290s",&char12);
		}
		else if(cnt==13)
		{
			scanf("%290s",&char13);
		}
		else if(cnt==14)
		{
			scanf("%290s",&char14);
		}
		else if(cnt==15)
		{
			scanf("%290s",&char15);
		}
		else
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",var_name);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return 1;
		}
		fclose(variables);
	}
}

int set_int_value(char var_name[300],int data)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int temp;
	char buffer[300];
	FILE*variables;
	int cnt=0;
	temp=data;
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\ints.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,var_name))!=0&&cnt!=16)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}
		if(cnt>=63)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",var_name);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return 1;
		}
		integers[cnt]=temp;
		fclose(variables);
	}
}

int set_char_value(char var_name[300],char data[300])
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	char temp[300];
	char buffer[300];
	FILE*variables;
	int cnt=0;
	strcpy_s(temp,data);
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\chars.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,var_name))!=0&&cnt!=16)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}
		if(cnt==1)
		{
			strcpy_s(char1,temp);
		}
		else if(cnt==2)
		{
			strcpy_s(char2,temp);
		}
		else if(cnt==3)
		{
			strcpy_s(char3,temp);
		}
		else if(cnt==4)
		{
			strcpy_s(char4,temp);
		}
		else if(cnt==5)
		{
			strcpy_s(char5,temp);
		}
		else if(cnt==6)
		{
			strcpy_s(char6,temp);
		}
		else if(cnt==7)
		{
			strcpy_s(char7,temp);
		}
		else if(cnt==8)
		{
			strcpy_s(char8,temp);
		}
		else if(cnt==9)
		{
			strcpy_s(char9,temp);
		}
		else if(cnt==10)
		{
			strcpy_s(char10,temp);
		}
		else if(cnt==11)
		{
			strcpy_s(char11,temp);
		}
		else if(cnt==12)
		{
			strcpy_s(char12,temp);
		}
		else if(cnt==13)
		{
			strcpy_s(char13,temp);
		}
		else if(cnt==14)
		{
			strcpy_s(char14,temp);
		}
		else if(cnt==15)
		{
			strcpy_s(char15,temp);
		}
		else
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",var_name);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return 1;
		}
		fclose(variables);
	}
}

int math(char result[300],char op[30],int num2)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	//char temp[300];
	char buffer[300];
	FILE*variables;
	int cnt=0;
	//fscanf(fp,"%290s",&temp);
	load_settings(&s1,&s2,&s3,&s4,&s5);
	if((variables=fopen("c:\\jakach-language\\system\\ints.jl","r"))==0)
	{
		return 1;
	}
	else
	{
		cnt=0;
		while((strcmp(buffer,result))!=0&&cnt!=16)
		{
			fscanf(variables,"%290s",&buffer);
			cnt++;
		}           
		if(cnt>=63)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: couldn't load variable %s\n",result);
			SetConsoleTextAttribute(console_color, 7);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			if(s4==true)
			{
				main(0,NULL);
			}
			return 1;
		}    

			if((strcmp(op,"+"))==0)
			{
				integers[cnt]+=num2;
			}
			if((strcmp(op,"-"))==0)
			{
				integers[cnt]-=num2;
			}
			if((strcmp(op,"*"))==0)
			{
				integers[cnt]*=num2;
			}
			if((strcmp(op,"/"))==0)
			{
				if(num2==0)
				{
					SetConsoleTextAttribute(console_color, 4);
					printf("\n[SYSTEM]: tried to do a division by 0! Calculation aborted\n");
					SetConsoleTextAttribute(console_color, 7);
					if(s4==true)
					{
						printf("press any button except from the power button and some other non-keyboard buttons\n");
						getch();
						main(0,NULL);
					}	
				}
				else
				{
					integers[cnt]/=num2;
				}
			}
		fclose(variables);
	}
}

void getraw(char*input,int max)
{
	FILE*tmp;
	//system("mkdir c:\\jakach-language\\system\\");															//if used outside of jakach_scripting_system
	if((tmp=fopen("c:\\jakach-language\\system\\temp.ais","w"))==0)
	{
		MessageBox(NULL,"(getraw_function) fatale error while opening file \"c:\\jakach-language\\system\\temp.ais\"","ERROR",MB_OK);
		system("del c:\\jakach-language\\system\\temp.ais");
		system("cd c:\\jakach-language\\system && type nul > temp.ais");
		if(s4==true)
		{
			main(1,NULL);
		}
	}
	else
	{
		fprintf(tmp,"%s end_of_part",input);
		fclose(tmp);
		tmp=fopen("c:\\jakach-language\\system\\temp.ais","r");
		getline_file(input,max,tmp);
		fclose(tmp);
	}
}