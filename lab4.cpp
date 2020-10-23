#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void main()
{
    int result = 0;
    int temp1 = 0;
    int temp2 = 0;
    __asm
    {
        // 14*3=42
        MOV EAX, 0
        MOV EBX, 0

        MOV AL, 14
        MOV BL, 3
        MUL BL

        MOV temp1, EAX
        
        // 47/5=9,4
        MOV EDX, 0
        MOV EAX, 47
        MOV ECX, 5
        DIV ECX

        MOV temp2, EAX
        
        // 2*3=6
        MOV EAX, 0
        MOV EBX, 0

        MOV AL, 2
        MOV BL, 3
        MUL BL

        // 9-6=3
        SUB temp2, EAX

        // 42/3=14
        MOV EDX, 0
        MOV EAX, temp1
        MOV ECX, temp2
        DIV ECX

        MOV temp1, EAX
        
        // 24/4=6
        MOV EDX, 0
        MOV EAX, 24
        MOV ECX, 4
        DIV ECX

        MOV temp2, EAX

        // 5-3=2
        MOV EBX, 5
        SUB EBX, 3

        // 6/2=3
        MOV EDX, 0
        MOV EAX, temp2
        MOV ECX, EBX
        DIV ECX

        MOV temp2, EAX

        // 14-3=11
        MOV EAX, temp1
        SUB EAX, temp2

        MOV result, EAX
    }

    cout << "result: " << result << endl;
}
