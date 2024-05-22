#include "../include/Declarations.hpp"
//TODO: Access whatever the file has in and manipulate it 
//TODO:  

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
void FilenameCreation(string& name){
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
        do{
           opt = Exception();
        }while(opt <= 0 || opt >= 5);
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
//Take the command to do the action required
void Menu(){
    string name;
    cout << "Welcome to the Text_Editor app. Select a command:\n"
         << "!Make (To make a file)\n"
         << "!Open (To open a file)\n"
         << "!Reset (To reset a file)\n"
         << "!List (To list all file)\n"
         << "!Help (To show all the commands)\n"
         << "!Delete (To delete a file)\n"
         << "!Exit (To exit the program)\n";
    //FIXME:Make it a bit better :)
    do{
        cin >> command;
        if(command.compare("!Exit") != 0 && command.compare("!exit") != 0 && command.compare("!Reset") != 0 && command.compare("!reset") != 0 && command.compare("!Make") != 0 && command.compare("!make") != 0 && command.compare("!List") != 0 && command.compare("!list") != 0 && command.compare("!Delete") != 0 && command.compare("!delete") != 0 && 
        command.compare("!Help") != 0 && command.compare("!help") != 0 && command.compare("!Open") != 0 && command.compare("!open") != 0 && command.compare("!E") != 0 && command.compare("!e") != 0 && command.compare("!D") != 0 && command.compare("!d") != 0 && command.compare("!R") != 0 && command.compare("!r") != 0 && command.compare("!M") != 0 && 
        command.compare("!m") != 0 && command.compare("!H") != 0 && command.compare("!h") != 0 && command.compare("!L") != 0 && command.compare("!l") != 0 && command.compare("!LS") != 0 && command.compare("!ls") != 0 && command.compare("!O") != 0 && command.compare("!o") != 0){
            cout << "Wrong command. Please try again.\n";
        }
    }while(command.compare("!Exit") != 0 && command.compare("!exit") != 0 && command.compare("!Reset") != 0 && command.compare("!reset") != 0 && command.compare("!Make") != 0 && command.compare("!make") != 0 && command.compare("!List") != 0 && command.compare("!list") != 0 && command.compare("!Delete") != 0 && command.compare("!delete") != 0 && 
    command.compare("!Help") != 0 && command.compare("!help") != 0 && command.compare("!Open") != 0 && command.compare("!open") != 0 && command.compare("!E") != 0 && command.compare("!e") != 0 && command.compare("!D") != 0 && command.compare("!d") != 0 && command.compare("!R") != 0 && command.compare("!r") != 0 && command.compare("!M") != 0 && 
    command.compare("!m") != 0 && command.compare("!H") != 0 && command.compare("!h") != 0 && command.compare("!L") != 0 && command.compare("!l") != 0 && command.compare("!LS") != 0 && command.compare("!ls") != 0 && command.compare("!O") != 0 && command.compare("!o") != 0);
    if(command.compare("!Exit") == 0 || command.compare("!exit") == 0 || command.compare("!E") == 0 || command.compare("!e") == 0 ){
        return;
    }else if(command.compare("!Make") == 0 || command.compare("!make") == 0 || command.compare("!M") == 0 || command.compare("!m") == 0){
        cout << "Please enter the name of the file you want to create:\n";
        cin >> name;
        FilenameCreation(name);
        return;
    }else if(command.compare("!Reset") == 0 || command.compare("!reset") == 0 || command.compare("!R") == 0 || command.compare("!r") == 0){
        cout << "Give me the name of the file you want to reset:\n";
        cin >> name;
        FilenameCreation(name);
        return;
    }else if(command.compare("!Delete") == 0 || command.compare("!delete") == 0 || command.compare("!D") == 0 || command.compare("!d") == 0){
        cout << "Give me the name of the file you want to delete:\n";
        cin >> name;
        FilenameCreation(name);
        return;
    }else if(command.compare("!List") == 0 || command.compare("!list") == 0 || command.compare("!L") == 0 || command.compare("!l") == 0 || command.compare("!list") == 0 || command.compare("!LS") == 0 || command.compare("!ls") == 0){
        return;
    }else if(command.compare("!Help") == 0 || command.compare("!help") == 0 || command.compare("!H") == 0 || command.compare("!h") == 0){
        return;
    }else if(command.compare("!Open") == 0 || command.compare("!open") == 0 || command.compare("!O") == 0 || command.compare("!o") == 0){
        /*cout << "Please enter the name of the file you want to modify:\n";
        cin >> name;
        FilenameCreation(name);*/
        return;
    }
}

//Main program
int main(){
    string input;//variable for writing into the file
    //Next to lines are used as flags
    char opt;
    int flag = 1;
    do{
        Menu();
        if(command.compare("!Exit") == 0 || command.compare("!exit") == 0 || command.compare("!E") == 0 || command.compare("!e") == 0 ){
            flag = 0;
        }else if(command.compare("!Reset") == 0 || command.compare("!reset") == 0 || command.compare("!R") == 0 || command.compare("!r") == 0){
            if(FileExists(filename)){
                cout << "File Found.\n"
                     << "Reseting it...\n";
                fout.open(filename, ios::out | ios::trunc);
                fout.close();
                cout << "Your File has been reset.\n";
            }else{
                cout << "Make sure file exists!\n";
            }

        }else if(command.compare("!Make") == 0 || command.compare("!make") == 0 || command.compare("!M") == 0 || command.compare("!m") == 0){
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
        }else if(command.compare("!Delete") == 0 || command.compare("!delete") == 0 || command.compare("!D") == 0 || command.compare("!d") == 0){
            if(FileExists(filename)){
                cout << "File Found.\n"
                     << "Deleting it..."<<flush;
                remove(filename.c_str());
                cout << "Your File has been deleted.\n";
            }else{
                cout << "Make sure file exists!\n";
            }
        }else if(command.compare("!List") == 0 || command.compare("!list") == 0 || command.compare("!L") == 0 || command.compare("!l") == 0|| command.compare("!LS") == 0 || command.compare("!ls") == 0){
            cout << "Which kind of list do you need ?\n"
                 << "!Simple\n"
                 << "!Detailed\n";
            do{
                cin >> command;
                if(command.compare("!Detailed") != 0 && command.compare("!detailed") != 0 && command.compare("!Simple") != 0 && command.compare("!simple") != 0 && command.compare("!S") != 0 && command.compare("!s") != 0 && command.compare("!D") != 0 && command.compare("!d") != 0){
                    cout << "Wrong command. Please try again.\n";
                }
            }while(command.compare("!Detailed") != 0 && command.compare("!detailed") != 0 && command.compare("!Simple") != 0 && command.compare("!simple") != 0&& command.compare("!S") != 0 && command.compare("!s") != 0 && command.compare("!D") != 0 && command.compare("!d") != 0);
            if(command.compare("!Detailed") == 0 || command.compare("!detailed") == 0 || command.compare("!D") == 0 || command.compare("!d") == 0) system("dir");
            else system("dir /B");  
        }else if(command.compare("!Help") == 0 || command.compare("!help") == 0 || command.compare("!H") == 0 || command.compare("!h") == 0){
            string opt;
            system("cls");
            cout << "!Delete: To delete a file (!D/!d/!Delete/!delete)\n"
                 << "!Exit: To exit the program (!E/!e/!Exit/!exit)\n"
                 << "!Help: To show this list (!H/!h/!Help/!help)\n"
                 << "!List: To list all the files and directories in the place where the application is located (!L/!l/!LS/!ls/!List/!list)\n"
                 << "When you use the list command, you will be asked in what kind of list you want to see.\n"
                 << "!Simple: It's a really simple list with just the names of the files and the directories (!S/!s/Simple/!simple)\n"
                 << "!Detailed: It's a really detailed list with the date, space and name of the files and directories (!D/!D/!Detailed/!detailed)\n"
                 << "!Make: To create a file with some already extesions or with the one the user desires -by typing when giving the name \"filename.extension\" - (!M/!m/!Make/!make)\n"
                 << "!Open: To open a file for editing (!O/!o/!Open/!open)\n"
                 << "!Reset: To reset whatever is written in a file without recreating a new file (!R/!r/!Reset/!reset)"<< endl;
            cout << "\nDo you want the list on a text file ? (Y,y or N,n)\n";
            cin >> opt;
            if(opt.compare("Y") == 0 || opt.compare("y") == 0){
                fout.open("Help_List.txt", ios::out | ios::trunc);
                    for(int i = 3; i > 0; --i){
                        cout << "\rCreating the file in "<< i <<flush;
                        this_thread::sleep_for(chrono::seconds(1));
                    }
                    fout << "!Delete: To delete a file (!D/!d/!Delete/!delete)\n"
                         << "!Exit: To exit the program (!E/!e/!Exit/!exit)\n"
                         << "!Help: To show this list (!H/!h/!Help/!help)\n"
                         << "!List: To list all the files and directories in the place where the application is located (!L/!l/!LS/!ls/!List/!list)\n"
                         << "When you use the list command, you will be asked in what kind of list you want to see.\n"
                         << "!Simple: It's a really simple list with just the names of the files and the directories (!S/!s/Simple/!simple)\n"
                         << "!Detailed: It's a really detailed list with the date, space and name of the files and directories (!D/!D/!Detailed/!detailed)\n"
                         << "!Make: To create a file with some already extesions or with the one the user desires -by typing when giving the name \"filename.extension\" - (!M/!m/!Make/!make)\n"
                         << "!Open: To open a file for editing (!O/!o/!Open/!open)\n"
                         << "!Reset: To reset whatever is written in a file without recreating a new file (!R/!r/!Reset/!reset)\n";
                    cout << "File \"Help_List.txt\" created !\n";
                    fout.close();
            }
        }else if(command.compare("!Open") == 0 || command.compare("!open") == 0 || command.compare("!O") == 0 || command.compare("!o") == 0){
            cout << "Not ready yet please use another function\n";
            ClearScreen();
            // fin.open(filename, ios::in);
            // if(bool(fin.good())){
            //     cout << "File Found!\n";
            //     ClearScreen();
            //     cout << "To quit the file use !quit\n";
            //     while(getline(fin,input) && !fout.eof()){
            //         cout << input << endl;
            //     }
            //     fin.close();
            // }            
            // fout.open(filename, ios::out | ios::trunc);
        }
        if(flag != 0){
            cout << "Wanna run the program again ? (1 for Yes/ 0 for No)\n";
            cin >> flag;
        }
        if(flag == 0){
            cout << "Program succesfully closed.\n";
        }else{
            system("cls");
        }
    }while(flag == 1);
    this_thread::sleep_for(chrono::seconds(1));
    return 0;
}