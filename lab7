#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void main()
{
    /*  В данной задаче используется значение 00110890, но в С++ оно невозможно.
        Причинной данной проблемы является тот факт, что на ноль начинается 8-ричная система.
        В ней попросту не имеется возможности использования 9-ти

        Возможные решения: 1) Изменить число
                           2) Использовать механизм строк

        Видоизменим число, добавив 1 в начало   */

    int number = 100110890;
    
    int temp = 0;
    int first = 0;
    int eveni = 0;
    int sum = 0;
    int i = 0;
    __asm
    {
        CMP number, 0
        JL NEGATIVE

        START:  CMP number, 9
                JBE FIRST
                
                MOV EDX, 0
                MOV EAX, number
                MOV ECX, 10
                DIV ECX
                MOV number, EAX

                ADD sum, EDX
                MOV temp, EDX

                MOV EDX, 0
                MOV EAX, temp
                MOV ECX, 2
                DIV ECX

                CMP EDX, 0
                JE EVENS
                
                INC i
                CMP number, 0
                JNE START

        FIRST:  MOV EAX, number
                MOV first, EAX

                MOV EAX, number
                MOV temp, EAX

                MOV EDX, 0
                MOV EAX, number
                MOV ECX, 10
                DIV ECX
                MOV number, EAX

                ADD sum, EDX

                MOV EDX, 0
                MOV EAX, temp
                MOV ECX, 2
                DIV ECX

                CMP EDX, 0
                JE EVENS

                INC i
                JMP END

        NEGATIVE:   NEG number
                    JMP START

        EVENS:  CMP temp, 0
                JE ZERO
                INC eveni

                INC i
                CMP number, 0
                JNE START
                JMP END
        
        ZERO:   INC i
                CMP number, 0
                JNE START
                JMP END
        
        END:

    }

    setlocale(LC_ALL, "rus");
    cout << "Сумма чисел: " << sum << endl;
    cout << "Количество чётных чисел: " << eveni << endl;
    cout << "Количество чисел: " << i << endl;
    cout << "Первое число: " << first << endl;
}
