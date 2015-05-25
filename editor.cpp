// Author: Jessica Ma

#include <iostream>
#include <fstream>
#include <vector>
#include <string> 

using namespace std;


// Prints the contents of the vector
void printVector(vector<string> &vect)
{
    vector<string>::const_iterator index;
    
    for (index = vect.begin(); index != vect.end(); index++)
    {
        cout << *index <<endl;
    } // going through the vector
    
} // printVector


void cmdI(vector<string> &vector, const string line)
{
    printVector(vector);
    cout << line << endl;
} // cmdI


vector<string> editFile(const vector<string> &src, const vector<string> &cmd)
{
    vector<string> destination = src;
    string line, command;
    vector<string>::const_iterator rows;
    
    for (rows = cmd.begin(); rows != cmd.end(); rows++) // gets commands
    {
        line = *rows;
        command = *line.begin();
        
        if (!command.compare("I"))
            cmdI(destination, line);
        
        if (!command.compare("R"))
            cout << "I found an R" << endl;
        
        if (!command.compare("F"))
            cout << "I found an F" << endl;
        
        if (!command.compare("D"))
            cout << "I found an D" << endl;
        
        if (!command.compare("E"))
            cout << "I found an E" << endl;
        
        if (!command.compare("C"))
            cout << "I found an C" << endl;
        
        if (!command.compare("M"))
            cout << "I found an M" << endl;
    } // for all the lines in the command file
    
    return destination;
} // editFile


// Stores contents of a file into a vector
void readFile(vector<string> &vect, ifstream &file)
{
    string line;
    
    while (getline(file, line))
        vect.push_back(line);
} // readSource


int main (int argc, char** argv)
{
    vector<string> source;
    vector<string> command;
    vector<string> destination;
    ifstream sourcef(argv[1]);
    ifstream commandf(argv[2]);
    
    // Check for right number of arguments
    if (argc != 4)
    {
        cout << "error: editor.out src_file cmd_file dest_file" << endl;
        return 0;
    } // right number of arguments?
    
    readFile(source, sourcef);
    readFile(command, commandf);
    
    sourcef.close();
    commandf.close();
    
//    printVector(source);
//    printVector(command);
    
    destination = editFile(source, command);

    return 0;
} // main
