// Usage: ./GetFileLength  <file to calculate length>
// Read a file as given as the first parameter, count the length of the file and output it
// Here, length of a line is the number of characters in the line (i.e., ignoring special characters like newline)
// Length of the file is the sum of the lengths of all lines
// If no file or bad file is provided, just quit

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    // Your code goes here	
    using namespace std;

    if(argc > 2) {
        cout << "Wrong number of arguments." << '\n';
        return -1;
    }

    int count = 0;
    ifstream f(argv[1]);
    // your code here

    char c;

    if(f.is_open()) {
        fstream fin(argv[1], fstream::in);
        while(fin >> noskipws >> c) {
            if(c != '\n' || f.eof()) {
                count++;
            }
        }
        f.close();
    }
    else cout << "Bad file" << '\n';

    cout << count << '\n';

    return 0;
    // note: when you read from file, if you reach the end of the file, f.eof() will be true
}
