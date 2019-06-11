
#include "primes.h"

enum {
	UNDEFINED            = -1,
	DEFINITELY_NOT_PRIME =  0,
	PROBABLY_PRIME       =  1,
	DEFINITELY_PRIME     =  2
};

// ./primes -n N --from X
int main(int argc, char *argv[])
{
	const char* N = "10";
	const char* X = "1";

	if (argc == 2) {
		if ((strcmp(argv[1],"--help") == 0) || (strcmp(argv[1],"-h") == 0)) {
			fprintf(stdout, "Usage: primes [OPTIONS]\n\n");
			fprintf(stdout, "Options:\n\n");
			fprintf(stdout, "  -n INTEGER          Number of primes to generate\n");
			fprintf(stdout, "  --from INTEGER      Start with prime larger than this value\n\n\n");

			return EXIT_SUCCESS;
		}

		N = argv[1];
	}

	if (argc >= 3) {
		if (strcmp(argv[1],"-n") == 0) {
			N = argv[2];
		} else {
			fprintf(stderr, "Could not understand input.\n");

			return EXIT_FAILURE;
		}
	}

	if (argc >= 5) {
		if (strcmp(argv[3],"--from") == 0) {
			X = argv[4];
		} else {
			fprintf(stderr, "Could not understand input.\n");

			return EXIT_FAILURE;
		}
	}

	// Declare GMP variables and initialize them

	mpz_t n;

	// Hold on the generation return value

	int is_prime = -1;

	if (mpz_init_set_str(n, N, 10) == -1) {
		fprintf(stderr, "[Error] Invalid number of primes requested: %s\n", N);

		mpz_clear(n);

		return EXIT_FAILURE;
	}

	mpz_t p;

	if (mpz_init_set_str(p, X, 10) == -1) {
		fprintf(stderr, "[Error] Invalid infimum value: %s\n", X);

		mpz_clear(n);
		mpz_clear(p);

		return EXIT_FAILURE;
	}

	while (mpz_cmp_ui(n,0)) {
		// Get next prime
		mpz_nextprime(p, p);

		// Validate prime number. If it's definitely not prime, get another one
		while ((is_prime = mpz_probab_prime_p(p, 500)) == DEFINITELY_NOT_PRIME) {
			mpz_nextprime(p, p);
		}

		// Print to stdout, indicating if a prime is definitely or just only
		// probably prime.
		gmp_printf("%Zu%s\n", p, (is_prime == PROBABLY_PRIME) ? "*" : ""); 

		// Decrease counter
		mpz_sub_ui(n, n, 1);
	}

	// Deallocate memory
	mpz_clear(p);
	mpz_clear(n);

    return EXIT_SUCCESS;
}

