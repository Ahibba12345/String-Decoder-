#include <string>
#include "StackType.h"
#include "QueType.h"


std::string decode(std::string exp, std::string code)
{
    QueType<char> normalChars;  // Queue for normal characters
    StackType<char> codedChars; // Stack for coded characters

    // Step 1: Go through each character in exp
    for (size_t i = 0; i < exp.length(); i++)
    {
        char ch = exp.at(i);

        // Step 2: Check if ch is in code
        if (code.find(ch) != std::string::npos)
        {
            // It's a coded character — push to stack
            codedChars.Push(ch);
        }
        else
        {
            // It's a normal character — enqueue
            normalChars.Enqueue(ch);
        }
    }

    // Step 3: Build the output string
    std::string result = "";

    // Add normal characters from queue
    while (!normalChars.IsEmpty())
    {
        char ch;
        normalChars.Dequeue(ch);
        result += ch;
    }

    // Add coded characters from stack (reversed)
    while (!codedChars.IsEmpty())
    {
        result += codedChars.Pop();
    }

    return result;
}
