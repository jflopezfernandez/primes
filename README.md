
# primes

Arbitrary precision command-line utility that generates the first N primes
greater than X written in C using GMP. The utility was designed to allow the use
of Gödelization in problem solving.

The generation of prime numbers is probabilistic, and uses the Miller-Rabin
primality test to ensure the generated numbers are prime. When verifying the
output, 50 repetitions are used as the parameter, which is the maximum the
library authors deemed "reasonable."

The calculation for the possibility of false positive prime numbers is:

```
1 / (4 ^ REPS)
```

With a `REPS` parameter of 50, this gives a false positive probability of
roughly `.00000000000000000000000000000079%`.

