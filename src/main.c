
#include "primes.h"

// ./primes -n N --from X
int main(int argc, char *argv[])
{
	const char* N = "10";
	const char* X = "1";

	if (argc == 2) {
		if ((strcmp(argv[1],"--help") == 0) || (strcmp(argv[1],"-h") == 0)) {
			fprintf(stdout, "Usage: primes -n <HowMany> --from <LargerThan>\n");

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
		while (mpz_probab_prime_p(p, 50) == FALSE) {
			mpz_nextprime(p, p);
		}

		// Print to stdout
		gmp_printf("%Zu\n", p); 

		// Decrease counter
		mpz_sub_ui(n, n, 1);
	}

	// Deallocate memory
	mpz_clear(p);
	mpz_clear(n);

    return EXIT_SUCCESS;
}

