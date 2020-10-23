#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void main()
{
    int x = 4;
    int y1 = 0;
    int y2 = 0;
    __asm
    {
        /*  В данном варианте отсутствует номер 12.
            Поэтому взял число, которое бы использовалось при системе раздачи
            вариантов у преподавателя
            Выбранный вариант: 2        */

        // Вариант с циклом FOR
        FOR:    MOV EAX, x
                ADD EAX, 2
                ADD y1, EAX
                
                DEC x // Уменьшаем х на 1
                CMP x, 0 // Сравниваем х и 0
                JNE FOR // Если x не равен 0, то прыгаем на метку FOR (Выполняем цикл заново)

        // Вариант с циклом LOOP
        MOV CX, 4
        M:  MOV EAX, ECX
            ADD EAX, 2
            ADD y2, EAX

        LOOP M // CX уменьшается на 1. Если он не равен 0, то прыгает на метку М        
    }

    cout << "For: " << y1 << endl;
    cout << "Loop: " << y2 << endl;
    system("pause");
}
