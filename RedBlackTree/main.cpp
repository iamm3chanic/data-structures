/**
 * @file rbapp.cpp An application that stores information in a red-black tree.
 * 
 * @author Gavin Fielder
 * @date 11/13/2017
 **/

#include <string>
#include <iostream>
#include "rbtree.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

RBTree myRBT;

//Function prototypes
void splitString(string& in, string& out1, string& out2); //split at first space
string firstWord(string& str); //trims string to first word
/**
 * Inserts a node into red-black tree
 *
 * @param  str  a string containing the key and subsequent data
 */
void processInsert(string& str) {
    string key = "", data = "";
    splitString(str, key, data);
    myRBT.rbInsert(key, data);
}

/**
 * Prints the tree
 */
void processPrint() {
    myRBT.rbPrintTree();
}

/**
 * Finds and prints all occurences of a key
 *
 * @param  key  the key to find
 */
void processFind(string& key) {
    key = firstWord(key);
    vector<const string*> results = myRBT.rbFind(key);
    for (auto str_ptr : results) 
        cout << key << " " << *(str_ptr) << endl;
}

/**
 * Finds and deletes all occurences of a key
 *
 * @param  key  the key to delete
 */
void processDelete(string& str) {
    string key = "", data = "";
    splitString(str, key, data);
    myRBT.rbDelete(key, data);
}
/**
 * Parses a command and executes
 *
 * @param  str  the line to parse and execute
 */
bool processCommand(string& input) {
    string cmd = "", arg = "";
    splitString(input, cmd, arg);
    if (cmd == "insert") 
        processInsert(arg);
    else if (cmd == "find")
        processFind(arg);
    else if (cmd == "delete")
        processDelete(arg);
    else if (cmd == "print")
        processPrint();
    else if (cmd == "quit")
        return false;
    return true;
}

/**
 * Read and process commands until done
 */
void mainLoop(void) {
    string input = "";
    do {
        printf("\nCOMMANDS:\n");
        printf("insert \"args\"\n"); 
        printf("find \"args\"\n");
        printf("delete \"args\"\n");
        printf("print\n");
        printf("quit\n");
    } while (getline(cin, input) && processCommand(input));
}



/**
 * Takes an input string and splits it at the first space into two substrings
 * If no spaces, entire string is put into out1
 *
 * @param  in  the input string
 * @param  out1  the first substring to return to
 * @param  out2  the second substring to return to
 */
void splitString(string& in, string& out1, string& out2) {
    unsigned int i = 0;
    out1 = "";
    out2 = "";
    while (i < in.length() && in.substr(i,1) != " ") {
        out1 += in.substr(i,1);
        i++;
    }
    i++;
    if (i < in.length()) out2 = in.substr(i); 
}

/**
 * Trims a string to the first word only.
 * If the string has no spaces, returns as-is
 *
 * @param  str  the string to trim
 *
 * @return  the first word of the string
 */
string firstWord(string& str) {
    string out1 = "", out2 = "";
    splitString(str, out1, out2);
    return out1;
}


char genRandom()  {
static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";
int stringLength = sizeof(alphanum) - 1;
    return alphanum[rand() % stringLength];
}

/**
 * Autotest
 */
void autotest() {
    srand(time(0));
    std::string Str;
    std::string abcde="abcde";
    for(int i=0;i<20;i++){
     for(unsigned int i = 0; i < 5; ++i){Str += genRandom();}
     processInsert(Str);
     Str="";
    }
    processPrint();
    printf("inserting abcde:\n");
    processInsert(abcde);
    processPrint();
    printf("searching abcde:\n");
    processFind(abcde);
    printf("deleting abcde:\n");   
    processDelete(abcde);
    processPrint();
}
/**
 * Main entry point
 */
int main(void) {
   autotest();
   mainLoop();

    return 0;
}










