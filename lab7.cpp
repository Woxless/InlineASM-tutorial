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
        CMP number, 0 // Сравниваем number и 0
        JL NEGATIVE // Если (number < 0), то прыгаем в NEGATIVE

        START:  CMP number, 9 // Cравниваем number и 9
                JBE FIRST // Если (number <= 0), то прыгаем в FIRST
                
                // Получение последней цифры
                MOV EDX, 0
                MOV EAX, number
                MOV ECX, 10
                DIV ECX
                MOV number, EAX

                // Суммирование цифр (Начиная с конца)
                ADD sum, EDX
                MOV temp, EDX
                
                // Проверка на чётность
                MOV EDX, 0
                MOV EAX, temp
                MOV ECX, 2
                DIV ECX

                CMP EDX, 0 // Сравниваем EDX (Остаток от деления на 2) и 0
                JE EVENS // Если (EDX = 0), то прыгаем в EVENS
                
                INC i  // Увеличиваем i на 1
                CMP number, 0 // Сравниваем number и 0
                JNE START // Если (number не равен 0), то прыгаем обратно в START

        FIRST:  MOV EAX, number 
                MOV first, EAX // Записываем первое число в first

                MOV EAX, number
                MOV temp, EAX
                
                // Получаем его значение
                MOV EDX, 0
                MOV EAX, number
                MOV ECX, 10
                DIV ECX
                MOV number, EAX
                
                // Суммируем
                ADD sum, EDX
                
                // Проверяем на чётность
                MOV EDX, 0
                MOV EAX, temp
                MOV ECX, 2
                DIV ECX

                CMP EDX, 0 // Остаток и 0
                JE EVENS // Если остаток равен 0, то прыгаем в Evens

                INC i
                JMP END // Дошло выполнение сюда? Прыгаем в END

        NEGATIVE:   NEG number // NEG 1 = -1; NEG -1 = 1;
                    JMP START

        EVENS:  CMP temp, 0 // temp, 0
                JE ZERO // Если равны, то прыгаем в ZERO
                INC eveni

                INC i
                CMP number, 0 // number, 0
                JNE START // Если не равны, то обратно в START
                JMP END // Дошло сюда? Прыгаем в конец
        
        ZERO:   INC i
                CMP number, 0 // number, 0
                JNE START // Если не равны, то обратно в START
                JMP END // Дошло сюда? Прыгаем в конец
        
        END:

    }

    setlocale(LC_ALL, "rus");
    cout << "Сумма чисел: " << sum << endl;
    cout << "Количество чётных чисел: " << eveni << endl;
    cout << "Количество чисел: " << i << endl;
    cout << "Первое число: " << first << endl;
}
