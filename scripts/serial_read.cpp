#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
 
int main()
{
    int fd;
    printf("serial test setup...\n");
    if(wiringPiSetup() < 0)return 1;
    printf("serial open...\n");
    //if((fd = serialOpen("/dev/serial0",9600)) < 0)return 1;
    fd = serialOpen("/dev/serial0",9600);
    printf("serial test start ...\n");
// serialPrintf(fd,"Hello World!!!\n");
    while (1){
    char ch = serialGetchar(fd);
    istringstream str("test\n1");
    string line;

    while(ch != '$')
    {  
        str << serialGetchar(fd);
        ch =  serialGetchar(fd);
	//line.push_back(ch);
    } 

    while(getline(str,line,'\n')){

    cout << line << endl;
    };
    	
    }
    serialClose(fd);
    return 0;
}
