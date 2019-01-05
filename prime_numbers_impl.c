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

PrimeNumbersStorage create_seed()
{
	PrimeNumbersStorage primes;

	primes.MaxCalculatedPrime = 5;
	primes.Count = 3;
	primes.CurrentSize = 3;
	primes.Numbers = calloc(primes.CurrentSize, sizeof(long int));
	primes.Numbers[0] = 2;
	primes.Numbers[1] = 3;
	primes.Numbers[2] = 5;

	return primes;
}


void  release(PrimeNumbersStorage *primes) 
{
	free(primes->Numbers);
}     


void print_primes(const PrimeNumbersStorage *const primes)
{
	printf("------ PrimeNumber Info ------\n");
	printf("Count: %d\n", primes->Count);
	printf("Current size: %d\n", primes->CurrentSize);
	printf("Max calculated prime: %d\n", primes->MaxCalculatedPrime);
	
	printf("------ Prime number: \n");
	for (int i = 0; i < primes->Count; ++i) {
		printf("%d, ", primes->Numbers[i]);
	}
	printf("\n");

	printf("------ PrimeNumber Info ------\n");
	printf("Count: %d\n", primes->Count);
	printf("Current size: %d\n", primes->CurrentSize);
	printf("Max calculated prime: %d\n", primes->MaxCalculatedPrime);
	printf("======== PrimeNumber Info ========\n");
}


int this_is_prime(long int number, PrimeNumbersStorage *primes) 
{
	if (!primes) {
		return ERR;
	}
	
	if (number <= 1) {
		return FALSE;
	}
		
	if (primes->MaxCalculatedPrime == number) {
		return TRUE;
	}

	if (primes->MaxCalculatedPrime < number) {		
		culc_primes_to_bound(number, primes);
	}     					     					   

	return find_number_in_list_of_primes(number, primes);
}