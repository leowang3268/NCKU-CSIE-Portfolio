#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
// using namespace std;

char str[20];
void Mode1(){
    ClearBuffer();
    UART_Write_Text(""); // TODO
    return ;
}
void main(void) 
{
    
    SYSTEM_Initialize() ;
    
    while(1) {
        strcpy(str, GetString());
        if(str[0]=='m' && str[1]=='o' && str[2] == 'd' && str[3] == 'e' && str[4] == '1'){ // Mode1
            Mode1();
            ClearBuffer();
        }
        else if(){ // Mode2
               // TODO     
        }
    }
    return;
}

void __interrupt(high_priority) Hi_ISR(void)
{

}