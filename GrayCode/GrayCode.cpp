/*
    Filename: GracyCode.cpp
    Benjamin Duncan
    Dec 2, 2022

    Challenge: Gray code is a binary code where each successive value differ in only one bit, as well as when
    wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions.
        - Given a number of bits n, generate a possible gray code for it
        - For example, for n = 2, one gray code would be [00, 01, 11, 10]

    Initial ideas:
        - I thought about just decoding integers into binary, looping back to zero whenever the value reached beyond n bits.
        However, that won't work because some increments of 1 change more than one bit.
        - Looking at a pattern of gray code on wikipedia (https://en.m.wikipedia.org/wiki/Gray_code), I can see a pattern in the graph...
        you can divide the rows by powers of two and they reflect along those lines.
        - I'd like to be able to make a conversion function between base ten to gray code binary.
        - So there's a pattern for each bit. The value for each bit at different values is
        
        ((int) ((x + 2^(b - 1)) / (2^b))) % 2

        - Where b is the bit position (starting at 1) and x is the numerical value.
        - The pattern in the bits is each bit position alternates between 1s and 0s every 2^b th count offset by 2^(b-1).
        For example, the 1st bit alternates as 0110011001100110011... The 2nd bit alternates as 0011110000111100001111...
        - Adding the offset again and then dividing by half the pattern period (2^b) will give us a number that, when floored (or converted to an int), will be
        odd or even. Modulusing that by 2 will give us the 1s and 0s that we need.

        - I'm going to give this idea a shot. (Dec 2, 2022)

    Result (Dec 2, 2022): Success! First time through worked very well. I tweaked the output characters for readability. 
        Feel free to set USE_DEBUG_CHARS to false if you want to see the ones and zeroes
*/

using namespace std;

#include <iostream>
#include <math.h>

#define USE_DEBUG_CHARS true

int decToGray(int bitNum, int value) {
    return ((int) ((value + pow(2, bitNum - 1)) / pow(2, bitNum))) % 2;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        throw "Not enough arguments: <filename> <num bits>";
    }

    int numBits = stoi(argv[1]);

    for (int i = 0; i < pow(2, numBits) * 3; i++) {
        for (int j = numBits; j > 0; j--) {
            int bitValue = decToGray(j, i);
            if (USE_DEBUG_CHARS) {
                cout << (bitValue == 1 ? "O" : "'");
            } else {
                cout << bitValue;
            }
        }
        cout << endl;
    }

    return 0;
}