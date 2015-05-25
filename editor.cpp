// Author: Jessica Ma

#include <iostream>
#include <fstream>
#include <vector>
#include <string> 

using namespace std;


string getCommand(const string &line)
{
    return line;
}


vector<string> editFile(const vector<string> &src, const vector<string> &cmd)
{
    vector<string> destination;
    string line, command;
    vector<string>::const_iterator rows;
    
    for (rows = cmd.begin(); rows != cmd.end(); rows++)
    {
        //command = getCommand(*rows);
        line = *rows;
        command = *line.begin();
        cout << "Command = " << command << endl;
    } // for all the lines in the command file
    
    return destination;
} // editFile


// Prints the contents of the vector
void printVector(vector<string> &vect)
{
    vector<string>::const_iterator index;
    
    for (index = vect.begin(); index != vect.end(); index++)
    {
        cout << *index <<endl;
    } // going through the vector
    
} // printVector


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
