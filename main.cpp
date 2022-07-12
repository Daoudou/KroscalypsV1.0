// KroscalypseV1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string.h>
#include <map>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// This enum serv us for the string values in the switch case
/*static enum StringValue {
    StringValue1,
    StringValue2
};

// Map to associate the strings with the enum values
static map<string, StringValue> s_mapStringValue;

static char ch[_MAX_PATH];

static void Initialize();*/

void getTimeKroscalypse() {

    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The date and time " << endl << dt << endl;

}

int main()
{
    system("cls");

    cout << "\t<############################ PERSONAL ASSISSTANT ##############################>" << endl << endl;

    string password;
    string commandUser;
    string nameProg;

    do
    {
        cout << "*******************************************************" << endl;
        cout << "| ENTER THE PASSWORD TO CONFIRM YOUR ARE MASTER" << endl;
        string phrase = "ENTER THE PASSWORD TO CONFIRM YOUR ARE MASTER";
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
                }
                else if(commandUser == "execute the music"){
                    cout << "Okay sir, launch to the hell fire" << endl;
                    string phrase = "Okay sir, launch to the hell fire";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    ShellExecute(NULL,"open","test1.mp3",NULL,NULL,SW_NORMAL);
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

                } else if(commandUser == "open som programm pls"){
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

                }else if(commandUser == "search a certain file"){
                    cout << "Okay sir, give me the name of the file" << endl;
                    string phrase = "Okay sir, give me the name of the file";
                    string command = "espeak \"" + phrase + "\"";
                    const char* charCommand = command.c_str();
                    system(charCommand);

                    if(getline(cin,nameProg)!= NULL){
                        systemt("dir "test1.mp3" /s");
                    }

                }
                else if(commandUser == "end of the programm" || commandUser == "bye" || commandUser == "i give you a break"){

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

    return 0;

}

/*
void Initialize()
{
    s_mapStringValue["First Value"] = StringValue1;
    s_mapStringValue["Second Value"] = StringValue2;
    cout << "s_mapStringValue containts"
        << s_mapStringValue.size()
    << " entries" << endl;

}*/
