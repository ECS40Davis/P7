// Author: Jessica Ma

#include <sstream>
#include <iostream>
#include <cstdio>
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

// insert
void cmdI(vector<string> &vect, const string line)
{
    int lNum, pNum;
    string command,lineNum, positionNum, ins;
    istringstream l(line);
    stringstream convert;
    vector<string>::const_iterator row;
    
    getline(l, command, ' ');
    getline(l, lineNum, ' ');
    getline(l, positionNum, ' ');
    getline(l, ins, '\n');
    
    convert << lineNum;
    convert >> lNum;
    
    convert.str(""); // clear the stringstream
    convert.clear(); // clear the state flags for another conversion
    
    convert << positionNum;
    convert >> pNum;
    
    (*(vect.begin() + lNum)).insert(pNum, ins);    
} // cmdI

// replace
void cmdR(vector<string> &vect, const string line)
{
    
    int lNum, startpNum, endpNum;
    string command,lineNum, startPositionNum, endPositionNum, ins;
    istringstream l(line);
    stringstream convert;
    vector<string>::const_iterator row;
    
    getline(l, command, ' ');
    getline(l, lineNum, ' ');
    getline(l, startPositionNum, ' ');
    getline(l, endPositionNum, ' ');
    getline(l, ins, '\n');
    
    convert << lineNum;
    convert >> lNum;
    
    convert.str(""); // clear the stringstream
    convert.clear(); // clear the state flags for another conversion
    
    convert << startPositionNum;
    convert >> startpNum;
    
    convert.str(""); // clear the stringstream
    convert.clear(); // clear the state flags for another conversion
    
    convert << endPositionNum;
    convert >> endpNum;
    
    (*(vect.begin() + lNum)).replace(startpNum, endpNum - startpNum, ins);

//    printVector(vector);
//    cout << line << endl;
} // cmdR

// find
void cmdF(vector<string> &vect, const string line)
{
//    printVector(vector);
//    cout << line << endl;
} // cmdF

// vector: erase
void cmdD(vector<string> &vect, const string line)
{
//    printVector(vector);
//    cout << line << endl;
} // cmdD

// erase
void cmdE(vector<string> &vect, const string line)
{
//    printVector(vector);
//    cout << line << endl;
} // cmdE


void cmdC(vector<string> &vect, const string line)
{
//    printVector(vector);
//    cout << line << endl;
} // cmdC


void cmdM(vector<string> &vect, const string line)
{
//    printVector(vector);
//    cout << line << endl;
} // cmdM


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
            cmdR(destination, line);
        
        if (!command.compare("F"))
            cmdF(destination, line);
        
        if (!command.compare("D"))
            cmdD(destination, line);
        
        if (!command.compare("E"))
            cmdE(destination, line);
        
        if (!command.compare("C"))
            cmdC(destination, line);
        
        if (!command.compare("M"))
            cmdM(destination, line);
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
    destination = editFile(source, command);

    return 0;
} // main
