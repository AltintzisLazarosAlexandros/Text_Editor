#include "Declarations.h"
//Global variables
fstream fout;
string name;
//Functions
bool FileExists(string& filename){
    fstream fout(filename);
    return fout.good();
}
void Menu(){
    cout << "Give me the name of your file:\n";
    cin >> name;
    cout << "Tell me what extension you are going to use:\n"
         << "1. C file (.c)\n"
         << "2. C++ file (.cpp)\n"
         << "3. Text file (.txt)\n";
    int opt;
    string extension;
    cin >> opt;
    switch (opt)
    {
    case 1:
        extension = ".c";
        break;
    case 2:
        extension = ".cpp";
        break;
    case 3:
        extension = ".txt";
        break;
    }
    name = name + extension; 
}

//Main program
int main(){
    Menu();
    if(FileExists(name)){
        fout.open(name, ios::out| ios::app);
        cout << "File Opened.\n";
    }else{
        fout.open(name, ios::out | ios::trunc);
        cout << "File Created.\n";
    }
    return 0;
}