#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <windows.h>

int compare(char command[300],FILE*fp);
int load_int(char var_name[300]);
int load_char(char var_name[300],char*output);
int scan_char(char var_name[300]);
int scan_int(char var_name[300]);
int set_int_value(char var_name[300],int data);
int set_char_value(char var_name[300],char data[300]);
int math(char result[300],char op[30],int num2);
void getraw(char*input,int max);
void print_help_full();
int using_cmd=false;

FILE*func_file;

int start_script_reader(char path[300])
{
	FILE*fp;
	char command[300];
	char buffer[300];
	int error;
	if((fp=fopen("c:\\jakach-language\\system\\chars.jl","w"))==0)
	{
		printf("error: couldn't load file for variables; type=char\n");
	}
	if((fp=fopen("c:\\jakach-language\\system\\ints.jl","w"))==0)
	{
		printf("error: couldn't load file for variables; type=int\n");
	}
	if((fp=fopen(path,"r"))==0)
	{
		printf("error: couldn't load file\n");
		return 1;
	}
	fscanf(fp,"%290s",&command);
	if((strcmp(command,"script:jakach_achscript.script"))!=0&&(strcmp(command,"script:jakach_achscript.function"))!=0)
	{
		printf("an error occured, this script isnt a jakach script\nplease add a \"script:jakach_achscript.script\" or a \"script:jakach_achscript.function\"at the start of your script\n");
		return 1;
	}
	else if((strcmp(command,"script:jakach_achscript.function"))==0)
	{
		printf("an error occured, this script isnt a jakach script\nYour requested file is a achscript functionfile. And can only be used as a function\n");
		return 1;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%295s",&command);
		error=compare(command,fp);
		if(error==1)
		{
			strcpy_s(buffer,"An error occured while executing command (command not found): ");
			strcat_s(buffer,command);
			MessageBox(NULL,buffer,"ERROR",MB_OK);
		}
		else if(error==99)
		{
			return 0;
		}
	}
	return 0;
}

int compare(char command[300],FILE*fp)
{
	int to_comp1,to_comp2;
	FILE*variables;
	FILE*for_loop;
	char buffer[505];
	char var_name1[300],var_name2[300];
	char charname[300];
	char command_[300];
	char path[305];
	int temp;
	int pause;
	int cnt;
	if((strcmp(command,"using_cmd"))==0)
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
	else if((strcmp(command,"script:jakach_achscript.script"))==0)
	{
		//this is the achscript starting sequence of a script;
	}
	else if((strcmp(command,"script:jakach_achscript.function"))==0)
	{
		//this is the achscript starting sequence of a function;
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
		if(using_cmd==true)
		{
			system(buffer);
		}
		else
		{
			printf("[SYSTEM]: the script tried to execute the cmd command \"%s\", but cmd commands are deactivated.\n",buffer);
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
			printf("\n[SYSTEM]: error initialising variable; type=char, name= %s\n",charname);
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
			printf("\n[SYSTEM]: error initialising variable; type=char, name= %s\n",charname);
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
		if((func_file=fopen(path,"r"))==0)
		{
			printf("error: functionfile \"%s\" not found\n",path);
			return 2;
		}
		else
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
	}
	else if((strcmp(command,"for.cnt"))==0)
	{
		temp=0;
		fscanf(fp,"%d",&temp);
		if((for_loop=fopen("c:\\jakach-language\\system\\loop.jl","w"))==0)
		{
			printf("an error occured while loading for loop!\n");
			return 1;
		}
		while((strcmp(buffer,"end_of_for\n"))!=0)
		{
			fgets(buffer,500,fp);
			if((strcmp(buffer,"end_of_for\n"))!=0)
			{
				fprintf(for_loop,"%s\n",buffer);
			}
		}
		fclose(for_loop);
		if((for_loop=fopen("c:\\jakach-language\\system\\loop.jl","r"))==0)
		{
			printf("an error occured while loading for loop!\n");
			return 1;
		}
		while(temp!=0)
		{
			for_loop=fopen("c:\\jakach-language\\system\\loop.jl","r");
			temp--;
			while(!feof(for_loop))
			{
				fscanf(for_loop,"%500s",&buffer);
				if(!feof(for_loop))
				{
					compare(buffer,for_loop);
					//printf("%s %d\n",buffer,temp);
				}
			}
			fclose(for_loop);
		}
	}
	else if((strcmp(command,"if.char.=="))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		load_char(var_name1,var_name1);
		load_char(var_name2,var_name2);
		while((strcmp("end_of_if",command_))!=0)
		{
			fscanf(fp,"%295s",&command_);

			if((strcmp(var_name1,var_name2)==0))
			{
				compare(command_,fp);
			}
		}
	}
	else if((strcmp(command,"if.char.!="))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		fscanf(fp,"%290s",&var_name2);
		load_char(var_name1,var_name1);
		load_char(var_name2,var_name2);
		while((strcmp("end_of_if",command_))!=0)
		{
			fscanf(fp,"%295s",&command_);

			if((strcmp(var_name1,var_name2)!=0))
			{
				compare(command_,fp);
			}
		}
	}
	else if((strcmp(command,"if.int.=="))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp2=load_int(var_name2);
			//printf("%d %d, %d %d %d\n",to_comp1,to_comp2,int1,int2,int3);
			while((strcmp("end_of_if",command_))!=0)
			{
				fscanf(fp,"%295s",&command_);

				if(to_comp1==to_comp2)
				{
					compare(command_,fp);
				}
			}
	}
	else if((strcmp(command,"if.int.<"))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp2=load_int(var_name2);
			//printf("%d %d, %d %d %d\n",to_comp1,to_comp2,int1,int2,int3);
			while((strcmp("end_of_if",command_))!=0)
			{
				fscanf(fp,"%295s",&command_);

				if(to_comp1<to_comp2)
				{
					compare(command_,fp);
				}
			}	
	}
	else if((strcmp(command,"if.int.>"))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp2=load_int(var_name2);
			//printf("%d %d, %d %d %d\n",to_comp1,to_comp2,int1,int2,int3);
			while((strcmp("end_of_if",command_))!=0)
			{
				fscanf(fp,"%295s",&command_);

				if(to_comp1>to_comp2)
				{
					compare(command_,fp);
				}
			}
	}
	else if((strcmp(command,"if.int.<="))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp2=load_int(var_name2);
			//printf("%d %d, %d %d %d\n",to_comp1,to_comp2,int1,int2,int3);
			while((strcmp("end_of_if",command_))!=0)
			{
				fscanf(fp,"%295s",&command_);

				if(to_comp1<=to_comp2)
				{
					compare(command_,fp);
				}
			}
	}
	else if((strcmp(command,"if.int.>="))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp2=load_int(var_name2);
			//printf("%d %d, %d %d %d\n",to_comp1,to_comp2,int1,int2,int3);
			while((strcmp("end_of_if",command_))!=0)
			{
				fscanf(fp,"%295s",&command_);

				if(to_comp1>=to_comp2)
				{
					compare(command_,fp);
				}
			}
	}
	else if((strcmp(command,"if.int.!="))==0)
	{
		fscanf(fp,"%290s",&var_name1);
		to_comp1=load_int(var_name1);
		fscanf(fp,"%290s",&var_name2);
		to_comp2=load_int(var_name2);
			//printf("%d %d, %d %d %d\n",to_comp1,to_comp2,int1,int2,int3);
			while((strcmp("end_of_if",command_))!=0)
			{
				fscanf(fp,"%295s",&command_);

				if(to_comp1!=to_comp2)
				{
					compare(command_,fp);
				}
			}
	}
	else if((strcmp(command,"end_"))==0)
	{
		printf("\n[SYSTEM]: reached the end of the script\n");
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

