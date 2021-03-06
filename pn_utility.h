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

typedef long long Number;
static const int FALSE = 0;
static const int TRUE = 1;
static const int ERR = -1;

/*
Seeks for a number in the prime numbers storage.
If NOT found, returns 0.
If found, returns 1.
*/
int find_number_in_list_of_primes(
	Number number, // Seeked number. 
	const PrimeNumbersStorage *const primes // Primes storage.
);

/*
Calculates the prime numbers between the max of computed prime numbers and the specified number, inclusive.
*/
void culc_primes_to_bound(
	Number number,// The specified number.
	PrimeNumbersStorage *primes  // The prime numbers storage.
);
#endif