// Author: Jessica Ma + Nathaniel Clay

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
    printVector(vect);
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
    printVector(vect);
} // cmdR

// find
void cmdF(vector<string> &vect, const string line)
{
    int count = 0;
    string command, fin;
    istringstream l(line);
    vector<string>::const_iterator rows;
    
    getline(l, command, ' ');
    getline(l, fin, '\n');
    
    cout << fin << " ";
    
    for (rows = vect.begin(); rows != vect.end(); rows++)
    {
        int position = (*rows).find(fin);
        if (position != -1)
            cout << count << " ";
        count++;
    } // for all the rows
    
    cout << endl;
} // cmdF

// vector: erase
void cmdD(vector<string> &vect, const string line)
{
    int sLine, eLine;
    string command, startLine, endLine;
    istringstream l(line);
    stringstream convert;
    
    getline(l, command, ' ');
    getline(l, startLine, ' ');
    getline(l, endLine, ' ');
    
    convert << startLine;
    convert >> sLine;
    
    convert.str(""); // clear the stringstream
    convert.clear(); // clear the state flags for another conversion
    
    convert << endLine;
    convert >> eLine;
    
    vect.erase(vect.begin() + sLine, vect.begin() + eLine + 1);
    printVector(vect);
} // cmdD

// erase
void cmdE(vector<string> &vect, const string line)
{
    int startPosition, count = 0;
    string command, eras;
    istringstream l(line);
    vector<string>::iterator rows;
    
    getline(l, command, ' ');
    getline(l, eras, '\n');
    
   for (rows = vect.begin(); rows != vect.end(); rows++)
   {
       startPosition = (*rows).find(eras);
       
       if (startPosition != -1)
       {
           
           if (eras.size() == (unsigned int)((*rows).size()))
               vect.erase(vect.begin() + count);
           else // not whole line
               (*rows).erase(startPosition, eras.size());
           printVector(vect);
       } // if found
       
       count++;
   } // for all the rows in the vector/file
    
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
