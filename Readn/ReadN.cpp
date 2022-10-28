/*
    Created by Benjamin DUncan
    Started: Oct 10, 2022
    Finished: Ooct 27, 2022

    [EASY]

    This problem was asked Microsoft.
    Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.
    For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string read7(string iString) {
    string oString = "";
    const int NUM_CHAR = 7;
    for (int i = 0; i < NUM_CHAR; i++) {
        if (i < iString.length()) {
            oString += iString[i];
        }
    }
    return oString;
}

string readN(string iString, int numChars) {
    if (numChars > iString.length()) numChars = iString.length();
    string oString = "";
    int numIterations = numChars / 7 + 1;
    
    for (int i = 0; i < numIterations; i++) {
        oString += read7(iString.substr(i * 7, numChars - i * 7));
    }
    
    return oString;
}

int main(int argc, char *argv[]) {
    // check number of arguments
    if (argc < 4 || argc > 4) {
        throw runtime_error("ERROR: Improper number of arguments. Please include the input file, output file, and the length to read in the arguments.");
    }

    // open input file
    ifstream iStream(argv[1]);
    if (iStream.fail()) throw runtime_error("Failed to open input file: " + string(argv[1]));

    // open output file
    ofstream oStream(argv[2]);
    if (oStream.fail()) throw runtime_error("Failed to open output file: " + string(argv[2]));

    // create string buffer
    stringstream iBuffer;
    iBuffer << iStream.rdbuf();

    // read N number of characters and output them to the output file
    oStream << readN(iBuffer.str(), stoi(argv[3]));

    // close output file
    oStream.close();
    return 0;
}
