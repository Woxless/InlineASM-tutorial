#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void main()
{
    int y = 0;
    int y1 = 0;
    int y2 = 0;

    int x = 8;
    int a = 2;
    __asm
    {
        /*  В этой лабораторной заданы условия (x > 7) и (x <= -7).
            Подобные условия приводят к серьёзным проблемам в программе.
            Именно по этой причине я считаю, что здесь таится опечатка.
            
            В этом примере используются условия: (x > -7) и (x <= -7)   */

        START:  CMP x, -7 // Какие числа сравниваем?
                JG ONE_START  // Если x > -7, то прыгаем в ONE_START
                JLE TWO_START // Если x <= -7, то прыгаем в TWO_START

                ONE_START:  MOV EAX, x
                            ADD EAX, 15
                            MOV y1, EAX
                            JMP END // Прыгает в точку END по достижению этой строки

                TWO_START:  MOV EAX, a
                            CMP EAX, 0 // Сравниваем a (Записан в EAX) и 0
                            JL NEGATIVE_START // Если (а < 0), то прыгаем в NEGATIVE_START
                            ADD EAX, 9
                            MOV y1, EAX
                            JMP END

        NEGATIVE_START: NEG a // Изменяем значение а на положительное
                        JMP TWO_START // возвращаемся на точку TWO_START

        END:    CMP x, 2 // Сравниваем x и 2
                JG ONE_END // (x > 2) --> ONE_END
                JLE TWO_END // (x <= 2) --> TWO_END

                ONE_END:    MOV y2, 3
                            JMP FINAL

                TWO_END:    MOV EAX, x
                            CMP EAX, 0
                            JL NEGATIVE_END
                            SUB EAX, 5
                            MOV y2, EAX
                            JMP FINAL

                NEGATIVE_END:   NEG x
                                JMP TWO_END

        FINAL:  MOV EDX, 0
                MOV EAX, y1
                MOV ECX, y2
                DIV ECX

                MOV y, EAX
    }

    cout << "y: " << y << endl;
    system("pause");
}
