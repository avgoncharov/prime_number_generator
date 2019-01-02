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
Prime numbers storage.
*/
struct PrimeNumbersStorage
{
	long int MaxCalculatedPrime; // Maximum of calculated prime numbers.
	long int Count; // Number of calculated prime numbers. 
	long int CurrentSize; // Size of bufer.
	long int* Numbers; // Array with prime numbers.   
};

/*
Creates an instance of prime numbers storage.
*/
struct PrimeNumbersStorage create_seed();

/*
Releases the instance of prime numbers storage.
*/
void  release(struct PrimeNumbersStorage *primes);

/*    
Checks if a number is a prime number.
The verification process also calculates prime numbers between the maximum of the computed prime number and the verified number inclusive.

If *primes is null, returns -1;
If the verified number is not prime, returns 0.
If the verified number is prime, returns +1.
*/
int this_is_prime(
	long int number, // The checked number. 
	struct PrimeNumbersStorage *primes // Storage of primes.
);

/*
Prints all primes in the storage and the storage summary.
*/
void print_primes(const struct PrimeNumbersStorage const *primes);
#endif