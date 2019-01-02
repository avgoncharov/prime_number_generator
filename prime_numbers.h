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
��������� ��� �������� ����������� ������� �����.
*/
struct PrimeNumbers
{
	long int MaxCalculatedPrime; // ������������ �� ������������ �������.
	long int Count; // ����� ������������ �������. 
	long int CurrentSize; // ������ ������ ��� �������� �������.
	long int* Numbers; // ������ � ������������� ��������.   
};

/*
������� ��������� ��������� ������� �����.
*/
struct PrimeNumbers create_seed();

/*
������� ��������� ������� �����.
*/
void  release(struct PrimeNumbers *primes);

/*
��������� ��������, �������� �� �������� ����� �������.
��� �������� �� �������� ���������� ������ ����������� ������� �����, 
������� � ��������� ����� ������������ ��� �����������
� ����������� ������, ������������.

���� *primes is null ���������� -1;
���� �������� ����� �� �������� �������, ���������� 0.
���� �������� ����� �������� �������, ���������� +1.
*/
int this_is_prime(
	long int number, // ����������� �����. 
	struct PrimeNumbers *primes // ��������� ������������ ������� �����.
);

/*
������� �� ������ ���������� � ��������� ������� �����, ������� ��� ������������ ������� �����.
*/
void print_primes(const struct PrimeNumbers const *primes);
#endif