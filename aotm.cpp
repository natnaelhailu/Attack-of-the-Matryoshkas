/*
*Written by: natizgr8
*Description: This program immplements a function that checks whether
*             a given set of numbers represent a matryoshka doll or not.
*Input : a filename of a file containing a sequence of numbers.
*Output: 'matryoshka' if the numbers represent a matryoshka doll;
         'Try again.' if they don't.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

// function prototype
int is_matryoshka(const std::vector<int>&, size_t, size_t);

/*
* Main entry-point for this program.
* @returns Exit-code for the process - 0 for success, else an error code.
*/
int main()
{
    std::string filename;     //< input file
    std::ifstream file;       //< input file stream object
    std::vector<int> doll;    //< a vector of one line of input
    std::string str;          //< a string of one line of input
    int num;                  //< each integer in that line of input

    // accept a valid filename from user & open file
    while (true) {
        std::cout << "Enter file name: ";
        std::cin >> filename;
        file.open(filename);
        if(file.is_open()) {
            break;
        }
    }

    // read one line of data from input file; store it in 'doll'
    while (std::getline(file, str)) {
        std::istringstream iss(str);
        while(iss >> num) {
            doll.push_back(num);
        }

        // check if 'doll' is a matryoshka
        switch(is_matryoshka(doll, 0, doll.size()-1)) {
        case -1:
            std::cout << "\n:-( Try again.";
            break;
        default:
            std::cout << "\n:-) matryoshka!";
        }

        doll.clear();
    }

    std::cout << std::endl;
    file.close();
    return 0;
}

/*
* is_matryoshka: determines whether a sequence of numbers represent a
*                matryoshka or not.
* parameters: dollInput: a vector containing the sequence of numbers.
              start: Index of the sequence to start checking from
			  end: Index of the sequence to end the checking on
* return value: 0 if it is a matryoshka; else -1.
*/
int is_matryoshka(const std::vector<int>& dollInput, size_t start, size_t end) {

    // check that the first & last numbers match & it isn't a base case
    if(abs(dollInput[start]) == dollInput[end] && end != start+1) {
    
        // check that the doll inside isn't larger than the one outside
        if(dollInput[end] > dollInput[end-1]) {
            start += 1;
            end -= 1;
            return is_matryoshka(dollInput, start, end);
        }
        
        // if inner sub-doll is larger than the outer doll
        else {
            return -1;
        }
    }

    // check if the first & last numbers match & it is a base case
    else if(abs(dollInput[start]) == dollInput[end] && end == start+1) {
        return 0;
    }

    else {
        // start looking for a matching end
        for(auto i = start+1; i < end; ++i) {
        
            if(dollInput[i] == abs(dollInput[start])) {
            
                // if found check that it is a valid matryoshka sub-doll
                if(is_matryoshka(dollInput, start, i) == 0) {
                    int max_size = dollInput[end+1];  //< Maximum size of doll
                    start = i + 1;
                    
                    // check that the remaining sub-doll is a matryoshka too
                    if(is_matryoshka(dollInput, start, end) == 0) {
                    
                        // compare the sum of the two sub-dolls to the outer matryoshka
                        return (max_size > dollInput[i] + dollInput[end]) ? 0 : -1;
                    }
                }
                
                // if inner sub-doll isn't a matryoshka
                else {
                    return -1;
                }
            }
        }
        
        // if there is no matching end
        return -1;
    }
}

/*EOF*/
