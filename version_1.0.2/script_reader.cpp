#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <windows.h>
/* 
DISCLAIMER:
the script reader function is a giant spaggeti code... for every command is it has an if((strcmp(command,"<command>"))==0){}!
*/
typedef int index;
typedef char index_c;
index loop_used_index[63];
index comp1[63];
index comp2[63];
index loop_used_index_c[63];
index_c* comp1_c[63];
index_c* comp2_c[63]; 

index for_loop_cnt_i[63];
index for_loop_cnt_i_real[63];
index for_loop_used_index[63];
index for_loop_cnt;
char cnt_char_l[50];
char cnt_char_l_2[50];

index if_used_index[63];
index if_used_index_c[63];
index_c* comp1_c_if[63];
index_c* comp2_c_if[63];
index_c* comp1_if[63];
index_c* comp2_if[63];
index cnt_loop;
index cnt_loop_c;
index cnt_if;
index cnt_if_c;
char cnt_char[50];
char cnt_char_if[50];
char cnt_char_2[50];
char cnt_char_c[50];
char cnt_char_c_2[50];
int compare(char command[300],FILE*fp);
int load_int(char var_name[300]);
int load_char(char var_name[300],char*output);
int scan_char(char var_name[300]);
int scan_int(char var_name[300]);
int set_int_value(char var_name[300],int data);
int set_char_value(char var_name[300],char data[300]);
int math(char result[300],char op[30],int num2);
int num_to_char(int a,char*ptr);
void getraw(char*input,int max);
void print_help_full();
int main(int argc, char** argv);
int using_cmd=false;
int load_settings(int*s_1,int*s_2,int*s_3,int*s_4,int*s_5);
int to_comp1,to_comp2;
int s_1,s_2,s_3,s_4,s_5;
FILE*func_file;
void printall();

int start_script_reader(char path[300])
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);	
	FILE*fp;
	char command[300];
	char buffer[300];
	int error;
	load_settings(&s_1,&s_2,&s_3,&s_4,&s_5);
	if((fp=fopen("c:\\jakach-language\\system\\chars.jl","w"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("error: couldn't load file for variables; type=char\n");
		SetConsoleTextAttribute(console_color, 7);
	}
	if((fp=fopen("c:\\jakach-language\\system\\ints.jl","w"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("error: couldn't load file for variables; type=int\n");
		SetConsoleTextAttribute(console_color, 7);
	}
	if((fp=fopen(path,"r"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("error: couldn't load file\n");
		SetConsoleTextAttribute(console_color, 7);
		return 1;
	}
	fscanf(fp,"%290s",&command);
	if((strcmp(command,"script:jakach_achscript.script"))!=0&&(strcmp(command,"script:jakach_achscript.function"))!=0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("an error occured, this script isnt a jakach script\nplease add a \"script:jakach_achscript.script\" or a \"script:jakach_achscript.function\"at the start of your script\n");
		SetConsoleTextAttribute(console_color, 7);
		return 1;
	}
	else if((strcmp(command,"script:jakach_achscript.function"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("an error occured, this script isnt a jakach script\nYour requested file is a achscript functionfile. And can only be used as a function\n");
		SetConsoleTextAttribute(console_color, 7);
		return 1;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%295s",&command);
		error=compare(command,fp);
		if(error==1)
		{
			if(s_4==true)
			{
				SetConsoleTextAttribute(console_color, 4);
				printf("An error occured while executing command (command not found): %s\naborted\ncore dumped\n",command);
				SetConsoleTextAttribute(console_color, 7);
				main(0,NULL);
				return 1;
			}
			SetConsoleTextAttribute(console_color, 4);
			strcpy_s(buffer,"An error occured while executing command (command not found): ");
			strcat_s(buffer,command);
			printf("%s\n",buffer);
			SetConsoleTextAttribute(console_color, 7);
			MessageBox(NULL,buffer,"ERROR",MB_OK);
		}
		else if(error==99)
		{		
			SetConsoleTextAttribute(console_color, 4);
			printf("resetting...\n");
			SetConsoleTextAttribute(console_color, 7);
			sleep(3);
			printf("press any button except from the power button and some other non-keyboard buttons\n");
			getch();
			main(0,NULL);
			return 0;
		}
	}
	return 0;
}

int compare(char command[300],FILE*fp)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	FILE*variables;
	FILE*for_loop;
	char buffer[505];
	char buffer_2[505];
	char buffer_3[505];
	char var_name1[300],var_name2[300];
	char charname[300];
	char charname2[300];
	char command_[300];
	char path[305];
	int temp;
	int pause;
	int cnt;
	//printall();
	if((strcmp(command,"using_cmd"))==0)
	{
		if(s_1==true)
		{
			if((MessageBox(NULL,"This script uses cmd commands. Please let a script only execute cmd commands, if you trust the script!","Information",MB_YESNO))==IDYES)
			{
				using_cmd=true;
			}
			else
			{
				using_cmd=false;
			}
		}
		else
		{
			using_cmd=true;
		}
	}
	else if((strcmp(command,"script:jakach_achscript.script"))==0)
	{
		//this is the achscript starting sequence of a script;
	//	SetConsoleTextAttribute(console_color, 4);
	//	printf("script starting sequence called twice!\n");
	//	SetConsoleTextAttribute(console_color, 7);
	}
	else if((strcmp(command,"script:jakach_achscript.function"))==0)
	{
		//this is the achscript starting sequence of a function;
	//	SetConsoleTextAttribute(console_color, 4);
	//	printf("function starting sequence called twice!\n");
	//	SetConsoleTextAttribute(console_color, 7);
	}
	else if((strcmp(command,"help"))==0)
	{
		print_help_full();
	}
	else if((strcmp(command,"clearscreen"))==0)
	{
		system("cls");
	}
	else if((strcmp(command,"print"))==0)
	{
		fgets(buffer,500,fp);
		getraw(buffer,500);
		printf("%s",buffer);
	}
	else if((strcmp(command,"println"))==0)
	{
		fgets(buffer,500,fp);
		getraw(buffer,500);
		printf("%s\n",buffer);
	}
	else if((strcmp(command,"pause"))==0)
	{
		fscanf(fp,"%d",&pause);
		sleep(pause);
	}	
	else if((strcmp(command,"cmd.exec"))==0)
	{
		fgets(buffer,500,fp);
		getraw(buffer,500);
		if(s_2==true)
		{
			strcpy_s(path,"the script tries to execute the command :");
			strcat_s(path,buffer);
			strcat_s(path," ,should the command be executed?");
			if((MessageBox(NULL,path,"security",MB_YESNO)==IDYES))
			{
				system(buffer);
			}
		}
		else if(using_cmd==true)
		{
			system(buffer);
		}
		else
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("[SYSTEM]: the script tried to execute the cmd command \"%s\", but cmd commands are deactivated.\n",buffer);
			SetConsoleTextAttribute(console_color, 7);
		}
	}
	else if((strcmp(command,"scan.char"))==0)
	{
		fscanf(fp,"%290s",&charname);
		scan_char(charname);
	}
	else if((strcmp(command,"scan.int"))==0)
	{
		fscanf(fp,"%290s",&charname);
		scan_int(charname);
	}

	else if((strcmp(command,"print.char"))==0)
	{
		fscanf(fp,"%290s",&charname);
		load_char(charname,buffer);
		printf("%s",buffer);
	}
	else if((strcmp(command,"print.int"))==0)
	{
		fscanf(fp,"%290s",&charname);
		printf("%d",load_int(charname));
	}
	else if((strcmp(command,"print.none"))==0)
	{
		printf(" ");
	}
	else if((strcmp(command,"math.var"))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%5s",&buffer);
		fscanf(fp,"%290s",&var_name2);
		math(var_name1,buffer,load_int(var_name2));
	}
	else if((strcmp(command,"math.num"))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%5s",&buffer);
		fscanf(fp,"%d",&temp);
		math(var_name1,buffer,temp);
	}
	else if((strcmp(command,"init.char"))==0)
	{
		fscanf(fp,"%290s",&charname);
		if((variables=fopen("c:\\jakach-language\\system\\chars.jl","a"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: error initialising variable; type=char, name= %s\n",charname);
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		else
		{
			fprintf(variables,"%s\n",charname);
			fclose(variables);
		}
	}
	else if((strcmp(command,"init.int"))==0)
	{
		fscanf(fp,"%290s",&charname);
		if((variables=fopen("c:\\jakach-language\\system\\ints.jl","a"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("\n[SYSTEM]: error initialising variable; type=char, name= %s\n",charname);
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		else
		{
			fprintf(variables,"%s\n",charname);
			fclose(variables);
		}
	}
	else if((strcmp(command,"set.int.num"))==0)
	{
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%d",&temp);
		set_int_value(charname,temp);
	}
	else if((strcmp(command,"set.int.var"))==0)
	{
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&buffer);
		set_int_value(charname,load_int(buffer));
	}
	else if((strcmp(command,"set.char.char"))==0)
	{
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&buffer);
		set_char_value(charname,buffer);
	}
	else if((strcmp(command,"set.char.var"))==0)
	{
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&buffer);
		load_char(buffer,var_name1);
		set_char_value(charname,var_name1);
	}
	else if((strcmp(command,"run.func"))==0)
	{
		fgets(path,300,fp);
		getraw(path,300);
		if(s_3==true)
		{
			if((func_file=fopen(path,"r"))==0)
			{
				SetConsoleTextAttribute(console_color, 4);
				printf("error: functionfile \"%s\" not found\n",path);
				SetConsoleTextAttribute(console_color, 7);
				if(s_4==true)
				{
					system("pause");
					main(0,NULL);
				}
				return 2;
			}
			else
			{
				fscanf(func_file,"%290s",&buffer);
				if((strcmp(buffer,"script:jakach_achscript.function"))==0)
				{
					while(!feof(func_file))
					{
						fscanf(func_file,"%290s",&buffer);
						if(!feof(func_file))
						{
							compare(buffer,func_file);
						}
					}
				}
				else
				{
					fclose(func_file);
					SetConsoleTextAttribute(console_color, 4);
					printf("error: your requested file isn't a jakach achscript function file\nplease ad \"script:jakach_achscript.function\" at the first line of your function file\n",path);
					SetConsoleTextAttribute(console_color, 7);
					printf("press any button except from the power button and some other non-keyboard buttons\n");
					getch();	
					if(s_4==true)
					{
						main(0,NULL);
					}
					return 3;
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("the script tried to run the function located in %s, but functions are deactivated\n",path);
			SetConsoleTextAttribute(console_color, 7);			
		}
	}
	else if((strcmp(command,"for.cnt"))==0)
	{
		for_loop_cnt++;
		fscanf(fp,"%d",&for_loop_cnt_i[for_loop_cnt]);
		fscanf(fp,"%d",&for_loop_used_index[for_loop_cnt]);
		num_to_char(for_loop_cnt,cnt_char_l);
		num_to_char(for_loop_used_index[for_loop_cnt],cnt_char_l_2);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopl");
		strcat_s(buffer_3,cnt_char_l);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_l_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopl");
		strcat_s(buffer_3,cnt_char_l);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(for_loop_cnt_i[for_loop_cnt]!=0)
		{
			for_loop_cnt_i[for_loop_cnt]--;
			num_to_char(for_loop_cnt,cnt_char_l);
			strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopl");
			strcat_s(buffer_3,cnt_char_l);
			strcat(buffer_3,".jl");
			for_loop=fopen(buffer_3,"r");
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
				}
			}
			fclose(for_loop);
		}	
		for_loop_cnt--;
	}
	else if((strcmp(command,"while.int.num.=="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] == comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.num.<="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] <= comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.num.>="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] >= comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
		else if((strcmp(command,"while.int.num.!="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] != comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.num.>"))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] > comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.num.<"))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] < comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			comp1[cnt_loop]=to_comp1;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.var.=="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] == comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			fclose(for_loop);
		}	
		cnt_loop--;
	}	
	else if((strcmp(command,"while.int.var.!="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] != comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.var.<="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] <= comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.var.>="))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] >= comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			fclose(for_loop);
		}	
		cnt_loop--;
	
	}
	else if((strcmp(command,"while.int.var.<"))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] < comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.int.var.>"))==0)
	{
		cnt_loop++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&loop_used_index[cnt_loop]);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		comp1[cnt_loop]=to_comp1;
		comp2[cnt_loop]=to_comp2;
		num_to_char(cnt_loop,cnt_char);
		num_to_char(loop_used_index[cnt_loop],cnt_char_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while(comp1[cnt_loop] > comp2[cnt_loop])
		{
		num_to_char(cnt_loop,cnt_char);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loop");
		strcat_s(buffer_3,cnt_char);
		strcat(buffer_3,".jl");
		for_loop=fopen(buffer_3,"r");
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			to_comp1=load_int(var_name1);
			to_comp2=load_int(var_name2);
			comp1[cnt_loop]=to_comp1;
			comp2[cnt_loop]=to_comp2;
			fclose(for_loop);
		}	
		cnt_loop--;
	}
	else if((strcmp(command,"while.char.var.=="))==0)
	{
		cnt_loop_c++;
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&charname2);
		load_char(charname,var_name1);
		load_char(charname2,var_name2);
		fscanf(fp,"%d",&loop_used_index_c[cnt_loop_c]);
		comp1_c[cnt_loop_c]=var_name1;
		comp2_c[cnt_loop_c]=var_name2;
		num_to_char(cnt_loop_c,cnt_char_c);
		num_to_char(loop_used_index_c[cnt_loop_c],cnt_char_c_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_c_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while((strcmp(comp1_c[cnt_loop_c] , comp2_c[cnt_loop_c]))==0)
		{
			num_to_char(cnt_loop_c,cnt_char_c);
			strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
			strcat_s(buffer_3,cnt_char_c);
			strcat(buffer_3,".jl");
			for_loop=fopen(buffer_3,"r");
			load_char(charname,var_name1);
			comp1_c[cnt_loop_c]=var_name1;
			load_char(charname2,var_name2);
			comp2_c[cnt_loop_c]=var_name2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
				}
			}
			load_char(charname,var_name1);
			comp1_c[cnt_loop_c]=var_name1;
			load_char(charname2,var_name2);
			comp2_c[cnt_loop_c]=var_name2;
			fclose(for_loop);
		}	
		cnt_loop_c--;
	}
	else if((strcmp(command,"while.char.var.!="))==0)
	{
		cnt_loop_c++;
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&charname2);
		load_char(charname,var_name1);
		load_char(charname2,var_name2);
		fscanf(fp,"%d",&loop_used_index_c[cnt_loop_c]);
		comp1_c[cnt_loop_c]=var_name1;
		comp2_c[cnt_loop_c]=var_name2;
		num_to_char(cnt_loop_c,cnt_char_c);
		num_to_char(loop_used_index_c[cnt_loop_c],cnt_char_c_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_c_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while((strcmp(comp1_c[cnt_loop_c] , comp2_c[cnt_loop_c]))!=0)
		{
			num_to_char(cnt_loop_c,cnt_char_c);
			strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
			strcat_s(buffer_3,cnt_char_c);
			strcat(buffer_3,".jl");
			for_loop=fopen(buffer_3,"r");
			load_char(charname,var_name1);
			load_char(charname2,var_name2);
			comp1_c[cnt_loop_c]=var_name1;
			comp2_c[cnt_loop_c]=var_name2;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
				}
			}
			load_char(charname,var_name1);
			load_char(charname2,var_name2);
			comp1_c[cnt_loop_c]=var_name1;
			comp2_c[cnt_loop_c]=var_name2;
			fclose(for_loop);
		}	
		cnt_loop_c--;
	}	
	else if((strcmp(command,"while.char.char.=="))==0)
	{
		cnt_loop_c++;
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&var_name2);
		load_char(charname,var_name1);
		fscanf(fp,"%d",&loop_used_index_c[cnt_loop_c]);
		comp1_c[cnt_loop_c]=var_name1;
		comp2_c[cnt_loop_c]=var_name2;
		num_to_char(cnt_loop_c,cnt_char_c);
		num_to_char(loop_used_index_c[cnt_loop_c],cnt_char_c_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_c_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while((strcmp(comp1_c[cnt_loop_c] , comp2_c[cnt_loop_c]))==0)
		{
			num_to_char(cnt_loop_c,cnt_char_c);
			strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
			strcat_s(buffer_3,cnt_char_c);
			strcat(buffer_3,".jl");
			for_loop=fopen(buffer_3,"r");
			load_char(charname,var_name1);
			comp1_c[cnt_loop_c]=var_name1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
				}
			}
			load_char(charname,var_name1);
			comp1_c[cnt_loop_c]=var_name1;
			fclose(for_loop);
		}	
		cnt_loop_c--;
	}	
	else if((strcmp(command,"while.char.char.!="))==0)
	{
		cnt_loop_c++;
		fscanf(fp,"%290s",&charname);
		fscanf(fp,"%290s",&var_name2);
		load_char(charname,var_name1);
		fscanf(fp,"%d",&loop_used_index_c[cnt_loop_c]);
		comp1_c[cnt_loop_c]=var_name1;
		comp2_c[cnt_loop_c]=var_name2;
		num_to_char(cnt_loop_c,cnt_char_c);
		num_to_char(loop_used_index_c[cnt_loop_c],cnt_char_c_2);
		temp=0;
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"w"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		strcpy_s(buffer_2,"end_of_for:");
		strcat_s(buffer_2,cnt_char_c_2);
		strcat_s(buffer_2,"\n");
		while((strcmp(buffer,buffer_2))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,buffer_2))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}/////////////////////////////////////////////////////done
		fclose(for_loop);
		strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
		strcat_s(buffer_3,cnt_char_c);
		strcat(buffer_3,".jl");
		if((for_loop=fopen(buffer_3,"r"))==0)
		{
			SetConsoleTextAttribute(console_color, 4);
			printf("an error occured while loading for loop!\n");
			SetConsoleTextAttribute(console_color, 7);
			return 1;
		}
		while((strcmp(comp1_c[cnt_loop_c] , comp2_c[cnt_loop_c]))!=0)
		{
			num_to_char(cnt_loop_c,cnt_char_c);
			strcpy_s(buffer_3,"c:\\jakach-language\\system\\loop\\loopc");
			strcat_s(buffer_3,cnt_char_c);
			strcat(buffer_3,".jl");
			for_loop=fopen(buffer_3,"r");
			load_char(charname,var_name1);
			comp1_c[cnt_loop_c]=var_name1;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
				}
			}
			load_char(charname,var_name1);
			comp1_c[cnt_loop_c]=var_name1;
			fclose(for_loop);
		}	
		cnt_loop_c--;
	}	
	else if((strcmp(command,"if.char.var.=="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		load_char(var_name1,var_name1);
		load_char(var_name2,var_name2);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if((strcmp(var_name1,var_name2)==0))
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.char.var.!="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		load_char(var_name1,var_name1);
		load_char(var_name2,var_name2);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if((strcmp(var_name1,var_name2)!=0))
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.char.char.=="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		load_char(var_name1,var_name1);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if((strcmp(var_name1,var_name2)==0))
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.char.char.!="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		load_char(var_name1,var_name1);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if((strcmp(var_name1,var_name2)==0))
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.var.=="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1==to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.var.<"))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1<to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.var.>"))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1>to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.var.<="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1<=to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.var.>="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1>=to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.var.!="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp1=load_int(var_name1);
		to_comp2=load_int(var_name2);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1!=to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.num.=="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1==to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.num.<"))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1<to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.num.>"))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1>to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.num.<="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1<=to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.num.>="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1>=to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"if.int.num.!="))==0)
	{
		cnt_if++;
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%d",&to_comp2);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%d",&if_used_index[cnt_if]);
		num_to_char(if_used_index[cnt_if],cnt_char_if);
		strcpy_s(buffer_2,"end_of_if:");
		strcat_s(buffer_2,cnt_char_if);
		if(to_comp1!=to_comp2)
		{	
			while((strcmp(buffer_2,command_))!=0)
			{
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
				fscanf(fp,"%295s",&command_);
				compare(command_,fp);
				num_to_char(if_used_index[cnt_if],cnt_char_if);
				strcpy_s(buffer_2,"end_of_if:");
				strcat_s(buffer_2,cnt_char_if);
			}
		}
		else
		{
			while((strcmp(buffer_2,command_))!=0)
			{
				fscanf(fp,"%295s",&command_);
			}
		}
		cnt_if--;
	}
	else if((strcmp(command,"end_"))==0)
	{
		SetConsoleTextAttribute(console_color, 4);
		printf("\n[SYSTEM]: reached the end of the script\n");
		SetConsoleTextAttribute(console_color, 7);
		SetConsoleTextAttribute(console_color, 4);
		printf("resetting...\n");
		SetConsoleTextAttribute(console_color, 7);
		sleep(3);
		printf("press any button except from the power button and some other non-keyboard buttons\n");
		getch();
		main(0,NULL);
		return 99;
	}
	else if(strstr(command,"//"))
	{
		fgets(buffer,500,fp);
		//this is a note: ignoring the command and scipping the line;
	}
	else
	{
		return 1;
	}
	return 0;
}

