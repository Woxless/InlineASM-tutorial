#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void main()
{
    int i = 97;
    int check = 0;
    __asm
    {
        START:  CMP i, 30
                JE END

                MOV EDX, 0
                MOV EAX, i
                MOV ECX, 6
                DIV ECX

                CMP EDX, 2
                JE CHECK

                DEC i
                JMP START

        CHECK:  INC check
                DEC i
                JMP START

        END: NOP

    }

    setlocale(LC_ALL, "rus");
    cout << "Количество чисел, которые при делении на 6 дают остаток 2: " << check << endl;
    system("pause");
}
