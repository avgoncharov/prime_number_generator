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
#ifndef UTILITY_H
#define UTILITY_H

static const int FALSE = 0;
static const int TRUE = 1;
static const int ERR = -1;

/*
Функция сравнения двух чисел, для бинарного поиска.
Возвращает стандартный результат(-1, 0, 1)
*/
int numbers_comparision(void const *lhs, void const *rhs);

/*
Выполняет поиск числа в списке простых чисел.
0 - если искомого числа НЕТ в списке простых.
1 - если искомое число ЕСТЬ в списке простых.
*/
int find_number_in_list_of_primes(
	long int number, // Проверяемое число. 
	const struct PrimeNumbers const *primes // Хранилище рассчитанных простых чисел.
);

/*
Добавляет новое простое число в хранилище простых чисел.
*/
void add_to_primes(
	long int new_prime, // Новое простое число.
	struct PrimeNumbers *primes  // Хранилище рассчитанных простых чисел.
);

/*
Вычисляет недостоющие простые числа, лежащие в интервале между максимальным уже расчитанным
и проверяемым числом, включительно.
*/
void culc_primes_to_bound(
	long int number,// Проверяемое число. 
	struct PrimeNumbers *primes  // Хранилище рассчитанных простых чисел.
);
#endif