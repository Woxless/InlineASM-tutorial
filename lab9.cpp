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
        START:  CMP i, 10 // Сравниваем i и 10
                JE END // Если они равны, то прыгаем в END

                MOV EBX, key // Записываем key (Ключ массива) в индексируемый регистр EBX (все 32-х битные регистры подходят).
                MOV EAX, mass[EBX] // Записываем значение массива по ключу (key). mass[0] - 32; mass[4] - 10; mass[8] - 75; mass[12] - 41 и так далее

                // A*A=A^2 - Возводим в квадрат
                MOV temp, EAX
                MOV EDX, 0
                MOV ECX, EAX
                IMUL ECX

                MOV result1[EBX], EAX // Записываем значение EAX в массив result1 по ключу (key)

                // A*A*A=A^3 - Возводим в куб
                MOV EDX, 0
                MOV ECX, temp
                IMUL ECX

                MOV result2[EBX], EAX // Записываем значение EAX в массив result2 по ключу (key)

                INC i // Увеличиваем i на 1
                ADD key, 4 // Увеличиваем значение key на 4 каждую итерацию цикла. Почему 4-ре? int (Целое число) - 4 байта
                JMP START // Прыгаем в начало

        END:    NOP // Можно оставить пустым (Без NOP), а можно и вставить эту команду. Она означает, что здесь нет операций.
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
