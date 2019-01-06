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
#include<stdlib.h>	 
#include<stdio.h>	
#include "prime_numbers.h"
#include "pn_utility.h"

int numbers_comparision(void const *lhs, void const *rhs)
{
	Number r = (*(Number*)lhs - *(Number*)rhs);
	if (r == 0) return 0;
	return r > 0 ? 1:-1;
}


int find_number_in_list_of_primes(Number number, const PrimeNumbersStorage *const primes)
{
	long int const *result = bsearch(
		&number,
		primes->Numbers,
		primes->Count,
		sizeof(Number),
		numbers_comparision);

	return result ? TRUE : FALSE;
}


void add_to_primes(Number new_prime, PrimeNumbersStorage *primes)
{
	if (primes->Count == primes->CurrentSize) {
		Number *buf = primes->Numbers;
		Number buf_size = primes->CurrentSize;

		primes->CurrentSize *= 2;
		primes->Numbers = (Number*)calloc(primes->CurrentSize, sizeof(Number));

		for (size_t i = 0; i < buf_size; ++i) {
			primes->Numbers[i] = buf[i];
		}

		free(buf);
	}

	primes->Numbers[primes->Count++] = new_prime;
	primes->MaxCalculatedPrime = new_prime;
}


void culc_primes_to_bound(Number number, PrimeNumbersStorage *primes)
{
	Number x = primes->MaxCalculatedPrime;

	while (++x <= number) {
		size_t i = 0;
		for (; i < primes->Count; ++i) {
			if (x % primes->Numbers[i] == 0) break;
		}

		if (i == primes->Count) {
			add_to_primes(x, primes);
		}
	}
}
