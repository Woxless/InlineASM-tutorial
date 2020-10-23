#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void main()
{
    /*  В данном варианте отсутствует номер 12.
        Поэтому взял число, которое бы использовалось при системе раздачи
        вариантов у преподавателя
        Выбранный вариант: 2        */
    int mass[10] = { 32, 10, 75, 41, -12, 52, 48, 61, 10, 11 };
    int result1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int result2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int i = 0;
    int key = 0;
    int temp = 0;
    
    __asm
    {
        START:  CMP i, 10
                JE END

                MOV EBX, key
                MOV EAX, mass[EBX]

                // A*A=A^2 - Возводим в квадрат
                MOV temp, EAX
                MOV EDX, 0
                MOV ECX, EAX
                IMUL ECX

                MOV result1[EBX], EAX

                // A*A*A=A^3 - Возводим в куб
                MOV EDX, 0
                MOV ECX, temp
                IMUL ECX

                MOV result2[EBX], EAX

                INC i
                ADD key, 4
                JMP START

        END:    NOP
    }

    setlocale(LC_ALL, "rus");
    cout << "Исходный массив: ";
    for (int counter = 0; counter < 10; counter++)
    {
        cout << mass[counter] << " ";
    }

    cout << "\n" << "Квадраты: ";
    for (int counter = 0; counter < 10; counter++)
    {
        cout << result1[counter] << " ";
    }

    cout << "\n" << "Кубы: ";
    for (int counter = 0; counter < 10; counter++)
    {
        cout << result2[counter] << " ";
    }
    cout << "\n";

    system("pause");
}
