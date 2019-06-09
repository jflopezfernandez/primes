
#ifndef primes_H_
#define primes_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <signal.h>
#include <time.h>

#include <gmp.h>
#include <mpfr.h>

#if !defined(FALSE) || !defined(TRUE)
enum { FALSE, TRUE };
#endif // FALSE || TRUE

#if !defined(SUCCESS) || !defined(FAILURE)
enum { SUCCESS, FAILURE };
#endif // SUCCESS || FAILURE

#endif // primes_H_

