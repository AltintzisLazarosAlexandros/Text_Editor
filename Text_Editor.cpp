#include "Declarations.h"
//TODO: Make a way to delete files while the program is running
//TODO: Add a method to list all Files

//Global variables
fstream fout,fin;
string filename,command;

//Functions
void ClearScreen(){
    for(int i = 3; i > 0; --i){
        cout << "\rClearing screen in "<< i <<flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    system("cls");
}
bool FileExists(string& filename){
    fstream fout(filename);
    return fout.good();
}
bool IfInString(string& string){
    for(size_t i = 0; i < string.size(); ++i){
        if(string.find(".") != string::npos){
            return true;
        }
    }
    return false;
}
pair<string, string> SplitFilename(const string& filename) {
    size_t dotIndex = filename.find_last_of('.'); // Finds the index where the extension begins
    // If there is one then we split the filename to 2 strings to manage it better
    if (dotIndex != string::npos && dotIndex > 0 && dotIndex < filename.length() - 1) {
        string name = filename.substr(0, dotIndex);
        string extension = filename.substr(dotIndex + 1);
        return make_pair(name, extension);
    }
    return make_pair(" "," ");
}
void Menu(){
    string name;
    cout << "Welcome to the Text_Editor app. Select a command:\n"
         << "!Make (To make a file)\n"
         << "!Reset (To reset a file)\n"
         << "!List (To list all file)\n"
         << "!Exit (To exit the program)\n";
        do{
            cin >> command;
            if(command.compare("!Exit") != 0 && command.compare("!exit") != 0 && command.compare("!Reset") != 0 && command.compare("!reset") != 0 && command.compare("!Make") != 0 && command.compare("!make") != 0 && command.compare("!List") != 0 && command.compare("!list") != 0){
                 cout << "Wrong command. Please try again.\n";
            }
        }while(command.compare("!Exit") != 0 && command.compare("!exit") != 0 && command.compare("!Reset") != 0 && command.compare("!reset") != 0 && command.compare("!Make") != 0 && command.compare("!make") != 0 && command.compare("!List") != 0 && command.compare("!list") != 0);
    if(command.compare("!Exit") == 0 || command.compare("!exit") == 0){
        return;
    }else if(command.compare("!Make") == 0 || command.compare("!make") == 0){
        cout << "Give me the name of your file:\n";
        cin >> name;
        if(IfInString(name)){
            filename = name;
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
            filename = name + extension; 
        }
    }else if(command.compare("!Reset") == 0 || command.compare("!reset") == 0){
        cout << "Give me the name of the file you want to reset:\n";
        cin >> name;
        if(IfInString(name)){
            filename = name;
        }else{
            cout << "Tell me what the extension your file has:\n"
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
            filename = name + extension; 
        }
    }
}

//Main program
int main(){
    string input;//variable for writing into the file
    char opt;
    int flag = 1;
    do{
        Menu();
        if(command.compare("!Exit") == 0 || command.compare("!exit") == 0){
            cout << "Program succesfully closed.\n";
            flag = 0;
        }else if(command.compare("!Reset") == 0 || command.compare("!reset") == 0){
            if(FileExists(filename)){
                cout << "File Found.\n"
                     << "Reseting it...\n";
                fout.open(filename, ios::out | ios::trunc);
                fout.close();
                cout << "Your File has been reset.\n";
            }else{
                cout << "Make sure file exists!\n";
            }
        }else{
            if(FileExists(filename)){
                cout << "File Found.\n"
                    <<"Do you want to open the found file or make a new one ?\t"
                    <<"(Y or y for Opening the file, N or n for No For making a new one)\n";
                do{
                    cin >> opt;
                    if(opt != 'Y' && opt!='y' && opt != 'N' && opt != 'n'){
                        cout << "Wrong option. Please try again.\n";
                    }
                }while(opt != 'Y' && opt!='y' && opt != 'N' && opt != 'n');
                if(opt == 'N' || opt == 'n'){
                    int i = 1;
                    pair<string,string> parts = SplitFilename(filename);
                    const string BaseFilename = parts.first; //FIXME: Make it simplier later :)
                    while(FileExists(filename)){
                        pair<string,string> parts = SplitFilename(filename);
                        filename = BaseFilename + "_" + to_string(i) + "."+ parts.second;
                        ++i;
                    }
                    fout.open(filename, ios::out | ios::trunc);//Opening the file to append new input
                    cout << "File Created.\n";
                }else{
                    fin.open(filename, ios::in | ios::app);
                    fout.open(filename, ios::out | ios::app);
                    cout << "File Opened.\n";
                }
            }else{
                fout.open(filename, ios::out | ios::trunc);//Creating the file if it's new
                cout << "File Created.\n";
            }
            ClearScreen();
            cout << "To quit the file use !quit\n";
            if(bool(fin.good())){
                while(getline(fin,input) && !fout.eof()){
                    cout << input << endl;
                }
                fin.close();
            }
            while(getline(cin,input) && input != "!quit"){
                fout << input << endl; 
            }
            fout.close();
            ClearScreen();
            if(flag != 0){
                cout << "Wanna run the program again ? (1 for Yes/ 0 for No)\n";
                cin >> flag;
            }
            if(flag == 0){
                cout << "Program succesfully closed.\n";
            }
        }
    }while(flag == 1);
    return 0;
}