// KroscalypseV1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string.h>
#include <map>
#include <windows.h>
#include <vector>
#include <mmsystem.h>
#include <stdio.h>
#include <strsafe.h>
#include <cstdlib>
#include <ctime>

#pragma comment(lib,"User32.lib")
#define YES 1
#define NO 0

using namespace std;

void getTimeKroscalypse() {

    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The date and time " << endl << dt << endl;

}

string exec(const char* cmd){

    char buffer[128];
    string result = "";
    FILE* pipe = _popen(cmd,"r");
    if(!pipe) throw runtime_error("popen() failed!");
    try{
        while(fgets(buffer,sizeof buffer, pipe) !=NULL){
            result+= buffer;
        }
    }
    catch(exception e){
        _pclose(pipe);
        throw;
    }

    _pclose(pipe);
    return result;
}

int main()
{
    system("cls");

    cout << "\t<############################ ASTOLFO ASSISSTANT ##############################>" << endl << endl;

    string password;
    string commandUser;
    string nameProg;
    string system32 = "cd C:/Users/Daoudou";
    string todo;
    string deleteTodo;
    vector<string> todolist;

    ofstream fileTest;
    fileTest.open("testGetCmd.txt");

   WIN32_FIND_DATA ffd;
   LARGE_INTEGER filesize;
   TCHAR szDir[MAX_PATH];
   size_t length_of_arg;
   HANDLE hFind = INVALID_HANDLE_VALUE;
   DWORD dwError=0;

    do
    {
        cout << "*******************************************************" << endl;
        cout << "| ENTER THE PASSWORD TO CONFIRM YOUR ARE MASTER" << endl;
        string phrase = "ENTER THE PASSWORD TO CONFIRM YOUR ARE MY MASTER";
        string command = "espeak \"" + phrase + "\"";
        const char* charCommand = command.c_str();
        system(charCommand);

        getline(cin,password);

        STARTUPINFO startInfo = { 0 };
        PROCESS_INFORMATION processInfo = { 0 };

        if (password == "dada")
        {
            cout << "\n<******************************************>" << endl;
            do
            {
                cout << "\n<******************************************>" << endl;
                cout << endl << "How can i help you boss" << endl;

                string phrase = "How can i help you boss";
                string command = "espeak \"" + phrase + "\"";
                const char* charCommand = command.c_str();
                system(charCommand);

                cout << "Enter your command ===>";
                getline(cin,commandUser);

                cout << endl;
                cout << "Answer to your command ===>";

                if (commandUser == "hello" || commandUser == "hi")
                {
                    cout << "Hello boss..." << endl;
                    string phrase = "Hello boss...";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                }
                else if (commandUser == "who are you" || commandUser == "who is speaking") {

                    cout << "I'm a personnal assisstant, nothing helse" << endl;
                    string phrase = "I'm a personnal assisstant, nothing helse";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                }
                else if(commandUser == "give me the time pls"){
                    getTimeKroscalypse();
                }else if(commandUser == "find file for me"){
                    string ext="";
                    string answer ="";
                    cout << "Okay sir, give me the name of the file" << endl;
                    string phrase = "Okay sir, give me the name of the file";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    getline(cin,nameProg);
                    cout << "Do you have a specific extension, sir?" <<endl;
                    getline(cin,answer);
                    if(answer == "Yes"){
                        cout << "Give me the extension" << endl;
                        getline(cin,answer);
                        ext = answer;
                    }
                    string str = exec((""+system32+" && dir ""\*."+ext+""+nameProg+"* /s/d").c_str());
                    fileTest << str ;
                    cout << str << endl;

                }
                else if(commandUser == "execute somme music"){
                    cout << "Okay sir, tell me what music you want to play" << endl;
                    string phrase = "Okay sir, tell me what music you want to play";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    getline(cin,nameProg);
                    ShellExecute(NULL,"open",(""+nameProg+".mp3").c_str(),NULL,NULL,SW_NORMAL);
                }
                else if(commandUser == "let's play somme video"){
                    cout <<"Okay sir, tell me what video you want to play" << endl;
                    string phrase = "Okay sir, tell me what video you want to play";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    getline(cin,nameProg);
                    ShellExecute(NULL,"open",(""+nameProg+".mp4").c_str(),NULL,NULL,SW_NORMAL);

                }
                else if(commandUser == "open notepad"){
                    cout << "Okay sir, opening of the IDE in process" << endl;
                    string phrase = "Okay sir, opening of the IDE in process";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    CreateProcess(TEXT("C:\\Program Files\\Notepad++\\notepad++.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&startInfo,&processInfo);

                }
                else if(commandUser == "open google"){
                    cout << "Okay sir, opening in process" << endl;
                    string phrase = "Okay sir, opening in process";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    system("start http://www.google.com");

                }else if(commandUser == "search for me"){
                    cout <<"Tell me what you want to search sir :" << endl;
                    string phrase = "Tell me what you want to search sir";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    getline(cin,nameProg);
                    system(("start https://www.google.com/search?q="+nameProg+"").c_str());

                }else if(commandUser == "open my todolist"){
                    cout<< "Okay sir, give me somme second" << endl;
                    string phrase = "Okay sir, give me somme second";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    cout << "Enter what you want to do with your todolist ? ===>";
                    getline(cin,commandUser);

                    if(commandUser == "Add somme thing in my todolist"){
                    cout <<"Okay sir :" << endl;
                    string phrase = "Okay sir";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    getline(cin,todo);

                    todolist.push_back(todo.c_str());

                    }else if(commandUser == "Export my todolist"){

                            cout << "Enter a name of file" << endl;
                            string fileExp = "";

                            getline(cin,fileExp);

                            string fileExt = "";
                            int choice = 0;
                            cout << "Choose a extension" << endl;

                            cout << "1. Text file" << endl;
                            cout << "2. PDF file" << endl;
                            cout << "3. Excel file" << endl;
                            cin >> choice;

                            switch(choice){
                            case 1:
                                cout << "You choice a Text file" << endl;
                                fileExt = "txt";
                                break;
                            case 2:
                                cout << "You choice a PDF file" << endl;
                                fileExt = "pdf";
                                break;
                            case 3:
                                cout << "You choice a Excel file" << endl;
                                fileExt = "xlsx";
                                break;
                            default:
                                 cout << "Choice a number" <<endl;
                                break;
                            }

                            ofstream todolistExp(""+fileExp+"."+fileExt+"",ios::app | ios::binary);

                            for(int i = 0; i < todolist.size(); i++){
                                todolistExp << todolist[i] << endl;
                            }

                            string phrase = "Todolist exported";
                            cout << "Todolist exported" << endl;
                            string command = "espeak \""+ phrase +"\"";
                            const char* charCommand = command.c_str();
                            system(charCommand);

                    }else if (commandUser == "Show me my todolist"){

                            if(todolist.size() == NULL){
                                cout<<"You're todolist is empty sir"<< endl;
                                string phrase = "You're todolist is empty sir";
                                string command = "espeak \"" + phrase + "\"";
                                const char* charCommand = command.c_str();
                                system(charCommand);
                            }else{
                                cout<<"This is what you will do"<< endl;
                                string phrase = "This is what you will do";
                                string command = "espeak \"" + phrase + "\"";
                                const char* charCommand = command.c_str();
                                system(charCommand);
                                for(unsigned int i = 0; i < todolist.size(); i++){
                                    cout << endl;
                                    cout << todolist[i] << endl;
                                }
                            }
                    }else if(commandUser == "delete my todolist"){
                        cout<<"Tell what you want to delete"<< endl;
                        string phrase = "Tell what you want to delete";
                        string command = "espeak \"" + phrase + "\"";
                        const char* charCommand = command.c_str();
                        system(charCommand);

                        todolist.clear();

                    }
                }else if(commandUser == "List me all programm"){
                        cout<<"Okay sir, list in progress"<< endl;
                        string phrase = "Okay sir, list in progress";
                        string command = "espeak \"" + phrase + "\"";
                        const char* charCommand = command.c_str();
                        system(charCommand);
                        system((""+system32+" && tasklist").c_str());

                }else if(commandUser == "open som programm pls"){
                    cout << "Okay sir, give me the name of the programm" << endl;
                    string phrase = "Okay sir, give me the name of the programm";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    getline(cin,nameProg);

                    if(nameProg == "steam"){
                        cout << "Okay sir, opening of the programm in process" << endl;
                        string phrase = "Okay sir, opening of the programm in process";
                        string command = "espeak \"" + phrase + "\"";
                        const char* charCommand = command.c_str();
                        system(charCommand);
                        CreateProcess(TEXT("C:\\Program Files (x86)\\Steam\\steam.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&startInfo,&processInfo);
                    }

                }else if(commandUser == "end of the programm" || commandUser == "bye" || commandUser == "i give you a break"){

                    cout << "Okay thanks sir. See you next time" << endl;
                    string phrase = "Okay thanks sir. See you next time";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    exit(0);
                }
                else {

                    cout << "Sorry could not understand your comnmand please try again !!!" << endl;
                    string phrase = "Sorry could not understand your comnmand please try again !!!";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                }

            } while (1);
        }
        else {

            system("cls");

            cout << "\t<############################ PERSONAL ASSISSTANT ##############################>" << endl;
            cout << "*******************" << endl;
            cout << "X Incorrect Password X" << endl;
            cout << "*******************" << endl;

            string phrase = "Incorrect Password, please enter correct password";
            string command = "espeak \"" + phrase + "\"";
            const char* charCommand = command.c_str();
            system(charCommand);

        }

    } while (1);

    fileTest.close();
    return 0;

}
