{09:00 26.02.2022}
new things:
-added nesting to if, while, for; it should work now... 
-new syntax for if. while. for; e.g. if.char.char.== var1 hello 1 <<-- ID; end_of_if:1 <<-- ID

fixed bugs:
-the system wouldnt return to the main menu, if the "end_" command was written in an if statement. 
now it does

experimental:
now integer values get stored in an array and not in seperate variables. this should increase performance.