/*
Copyright (c) 2019 Goncharov Andrey

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#ifndef PRIME_NUMBER_H
#define PRIME_NUMBER_H
/*
Структура для хранения расчитанных простых чисел.
*/
struct PrimeNumbers
{
	long int MaxCalculatedPrime; // Максимальное из рассчитанных простых.
	long int Count; // Число рассчитанных простых. 
	long int CurrentSize; // Размер буфера для хранения простых.
	long int* Numbers; // Массив с рассчитанными просытми.   
};

/*
Создает заготовку хранилища простых чисел.
*/
struct PrimeNumbers create_seed();

/*
Удаляет хранилище простых чисел.
*/
void  release(struct PrimeNumbers *primes);

/*
Выполняет проверку, является ли заданное число простым.
При проверке на простоту происходит расчет недостоющих простых числе, 
лежащих в интервале между максимальным уже расчитанным
и проверяемым числом, включительно.

Если *primes is null возвращает -1;
Если заданное число НЕ является простым, возвращает 0.
Если заданное число является простым, возвращает +1.
*/
int this_is_prime(
	long int number, // Проверяемое число. 
	struct PrimeNumbers *primes // Хранилище рассчитанных простых чисел.
);

/*
Выводит на печать информацию о хранилище простых чисел, включая все рассчитанные простые числа.
*/
void print_primes(const struct PrimeNumbers const *primes);
#endif