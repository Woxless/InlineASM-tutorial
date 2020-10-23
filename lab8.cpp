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
        START:  CMP i, 30 // Сравниваем - i, 30
                JE END // Если равны, то прыгаем в END
                
                // Деление на i на 6. 
                MOV EDX, 0
                MOV EAX, i
                MOV ECX, 6
                DIV ECX
            
                // (EAX - результат, EDX - остаток)
                CMP EDX, 2 // Сравниваем - остаток
                JE CHECK // Если равны, то прыгаем в CHECK

                DEC i // Уменьшаем i на 1
                JMP START // Прыгаем в START

        CHECK:  INC check // Увеличиваем check на 1
                DEC i // Уменьшаем i на 1
                JMP START // Прыгаем в START

        END: NOP // Можно оставить пустым (Без NOP), а можно и вставить эту команду. Она означает, что здесь нет операций.

    }

    setlocale(LC_ALL, "rus");
    cout << "Количество чисел, которые при делении на 6 дают остаток 2: " << check << endl;
    system("pause");
}
