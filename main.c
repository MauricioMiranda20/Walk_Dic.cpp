#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <windows.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

using namespace std;
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::ifstream;


char *findfile(LPCSTR Name){
    string filepath;
    DWORD attr;

    WIN32_FIND_DATA file;
    HANDLE fha;
    fha = FindFirstFile(Name,&file);
    if(fha == INVALID_HANDLE_VALUE){
        printf("invalid file handle\n");
    }
    while(FindNextFile(fha,&file) != 0){
        attr = GetFileAttributes(file.cFileName);
        PTSTR psz = file.cFileName;
        switch(attr){     
            case FILE_ATTRIBUTE_DIRECTORY:                           
                cout << "DIR " << psz << endl;
                break;
            
            default:
                cout << "FILE :" << file.cFileName << endl;
                break;
        }
    }
    cout << Name << endl;
}


int main(){

    LPCSTR sr = "C:\\Users\\User\\Documents\\des\\*";
    string s = sr;
    findfile(sr);
}
