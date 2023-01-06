#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int userInput = 0;
    int maxNumber = 0;
    int minNumber = 100;
    int sumTotal = 0;
    float average = 0;
    ifstream myFile("input.txt");
    string str;
    // get the numbers from the user
    if (myFile.is_open())
    {
        while (myFile >> userInput)
        {
            
            if (userInput > maxNumber)
            { // the biggest number entered so far is the max number
                maxNumber = userInput;
            }
            if (userInput < minNumber)
            { // the lowest number entered so far is the min number
                minNumber = userInput;
            }
            sumTotal = sumTotal + userInput;
        }
        myFile.close();
    }

    std::cout << "Maximum number = " << maxNumber << "\n";
    std::cout << "Minimum number = " << minNumber << "\n";
    average = sumTotal / 15;
    std::cout << "Average = " << average << "\n";
    return 0;
}