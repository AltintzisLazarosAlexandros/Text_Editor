#include "Declarations.h"
//TODO:

//Global variables
fstream fout;
string name;

//Functions
bool FileExists(string& filename){
    fstream fout(filename);
    return fout.good();
}
bool IfInString(string& string){
    for(int i = 0; i < string.size(); ++i){
        if(string.find(".") != string::npos){
            return true;
        }
    }
    return false;
}
void Menu(){
    string filename;
    cout << "Give me the name of your file or write 0 to quit the app:\n";
    cin >> filename;
    if(filename.compare("0") == 0){
        name = filename;
        return;
    }
    if(IfInString(filename)){
        name = filename;
    }else{
        cout << "Tell me what extension you are going to use:\n"
            << "1. C file (.c)\n"
            << "2. C++ file (.cpp)\n"
            << "3. Text file (.txt)\n"
            << "4. Java file (.java)\n";
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
        case 4:
            extension = ".java";
            break;
        }
        name = filename + extension; 
    }
}

//Main program
int main(){
    string input;//variable for writing into the file
    Menu();
    if(name.compare("0") == 0){
        cout << "Program succesfully closed";
        return 0;
    }
    if(FileExists(name)){
        fout.open(name, ios::out| ios::app);//Opening the file to append new input
        cout << "File Opened.\n";
    }else{
        fout.open(name, ios::out | ios::trunc);//Creating the file if it's new
        cout << "File Created.\n";
    }
    for(int i = 3; i > 0; --i){
        cout << "\rClearing screen in "<< i <<flush;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("cls");
    cout << "To quit the file use !quit\n";
    while(getline(cin,input) && input != "!quit"){
        fout << input << endl; 
    }
    fout.close();
    return 0;
}