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
    
    This will all be error free
