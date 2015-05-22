# P7

Source file, command file, destination file
  
  Source contains text with \n at the end of each line.
 
  Command file contains one command (I, R, F, D, E, C, M)
    insert: I line# position# char*
    replace: R line# startposition# endposition# char*
    find: F char*
    delete lines: D startline# endline#
    erase words: E char*
    copy and paste: C startline# endline# destinationline#
    move: M startline# endline# destinationline#
    
    
**So step by step ideas:**
    Read the initial file
    Read command file
    /*
    char str[]
    getline()
    char* command = strtok(str, " ")
      If (command = I)
        parse line# position# char
      If (command = R)
        parse line# startline# endline#
      //etc...
    */  
    
    
    
    We will somehow need to navigate through the old file and place additions into it. Maybe we should copy the entire 
      file into newfile then somehow append to it? I'm not sure how we could move down different lines and such.
    
    
    
    
    std::ofstream newfile ("newfile.txt");
    
    newfile << /*something*/ << endl;
    newfile.close()
      
    
    
