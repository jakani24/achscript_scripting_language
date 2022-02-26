#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <windows.h>

void print_help_full()
{
	printf("[SYSTEM]: Jakach achscript command overview\n\n");
	printf("-script-\n");
	printf("there's only one thing to watch: add the \"script:jakach_achscript.script\" to the top (the very first line) of your file\n\n");
	printf("-function-\n");
	printf("there's only one thing to watch: add the \"script:jakach_achscript.function\" to the top (the very first line) of your file\n\n");	
	printf("-commands-\n");
	printf("using_cmd : imports the cmd command, so you can use cmd commands (this will trigger a warning for the user)\n");
	printf("cmd.exec : runs a cmd command\n");
	printf("help : displays the help :)\n");
	printf("clearscreen : clears the console-screen\n");
	printf("init.int : creates an integer variable with the following name\n");
	printf("init.char : creates a char variable with the following name\n");
	printf("set.int.num : sets the following variable to a specified value\n");
	printf("set.char.char : sets the following variable to a specified value\n");
	printf("set.int.var : sets the following variable to the following variable\n");
	printf("set.char.var : sets the following variable to the following variable\n");
	printf("print : prints the \"print\" following words\n");
	printf("println print : prints the \"print\" following words but with a \\n at the end\n");
	printf("print.int : prints the integer variable, that follows the command\n");
	printf("print.char : prints the char variable, that follows the command\n");
	printf("print.none : prints nothing ~ print without any words\n");
	printf("scan.char : scans a char value and stores it in the variable, that follows the command\n");
	printf("scan.int : scans an int value and stores it in the variable, that follows the command\n");
	printf("pause : waits until the user presses something\n");
	printf("math.num : runs a mathematical operation (+-*/) and stores it in the first variable; p.ex math.num num1 + 5\n");
	printf("math.var : runs a mathematical operation (+-*/) and stores it in the first variable; p.ex math.num num1 + num2\n");
	printf("run.func : takes the following path and tries to run the script on this path\n");
	printf("for.cnt : runs a for loop for the number of iteration specified in the following number; ends with \"end_of_for\"\n");
	printf("if.char.char <;==;<;>;<=;>=;!=;> : compares a variable and a char; ends with end_of_if\n");
	printf("if.int.num <;==;<;>;<=;>=;!=;> : compares a variable and an int; ends with end_of_if\n");
	printf("if.char.var <;==;<;>;<=;>=;!=;> : compares char variables; ends with end_of_if\n");
	printf("if.int.var <;==;<;>;<=;>=;!=;> : compares int variables; ends with end_of_if\n");
	printf("while.int.num. <;==;<;>;<=;>=;!=;> <ID>: creates a locig while loop; compares a variable and a nummber ends with end_of_for:<ID> ID has to be a valid integer\n");
	printf("while.int.var. <;==;<;>;<=;>=;!=;> <ID>: creates a locig while loop; compares with 2 variables; ends with end_of_for:<ID> ID has to be a valid integer\n");
	printf("while.char.char. <;==;<;>;<=;>=;!=;> <ID> : creates a locig while loop; compares a variable and a char ends with end_of_for:<ID> ID has to be a valid integer\n");
	printf("while.char.var. <;==;<;>;<=;>=;!=;> <ID> : creates a locig while loop; compares with 2 variables; ends with end_of_for:<ID> ID has to be a valid integer\n");
	printf("// : notes, will be ignored\n");
	printf("end_ : marks the end of a jakach achscript\n");
}
