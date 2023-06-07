#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

bool isUpper(char& c){
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool isLower(char& c){
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

bool isSpecial(char& c){
    if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
        return true;
    return false;
}

bool pwd_strong(string& text){
    int p_len = text.length();

    bool hasLow, hasUp, hasNum, hasChar = false;

    for (int i = 0; i<p_len; i++){
        if (isUpper(text[i]))
            hasUp = true;

        if (isLower(text[i]))
            hasLow = true;
        
        if (isdigit(text[i]))
            hasNum = true;

        if (isSpecial(text[i]))
            hasChar = true;
    }
    
    if(p_len >= 12 && hasLow && hasUp && hasNum && hasChar){
        return true;
    }
    return false;
}

unordered_set<string> loadRockYou(string& filename){
    unordered_set<string> passwordSet;
    ifstream file(filename);
    if(!file){
        cerr << "error opetining file" ;
        return passwordSet;
    }
    string line;
    while(getline(file, line)){
        passwordSet.insert(line);
    }

    return passwordSet;
}


bool pwd_common(const string& text, string& filename) {
    if (filename.empty())
        filename = "rockyou-25.txt";

    unordered_set<string> pwdSet = loadRockYou(filename);

    return pwdSet.count(text) > 0;
}


int main(int argc, char** argv) {
    if (argc > 1) {
        string password = argv[1]; // Access the first command-line argument
        string filename;

        if (argc > 2) {
            filename = argv[2]; // Access the second command-line argument
        }

        // Call the functions and display the results
        bool isStrong = pwd_strong(password);
        bool isCommon = pwd_common(password, filename);

        cout << "Password: " << password << endl;
        cout << "Strong: " << (isStrong ? "Yes" : "No") << endl;
        cout << "Common: " << (isCommon ? "Yes" : "No") << endl;
    }
    else {
        cout << "No password provided as a command-line argument." << endl;
    }

    return 0;
}