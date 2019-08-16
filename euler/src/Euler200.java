// Brute Force Approach. Did not give solution faster enough

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Euler200 {
    private static long pow2(long a, long b) {
        long re = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                re *= a;
            }
            b >>= 1;
            a *= a;
        }
        return re;
    }

    public static void main(String[] args) {
        Boolean[] primes = generatePrimes(1000000);
        ArrayList<Integer> properPrimes = new ArrayList<Integer>();
        for(int i=0; i<primes.length; i++) {
            if(primes[i]) properPrimes.add(i);
        }
        int cnt = 0;
        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                long sqube = pow2(properPrimes.get(i), 2) * pow2(properPrimes.get(j), 3);
                if(isPrimeProof(sqube, primes)) {
                    cnt = cnt + 1;
                    System.out.println(sqube + " , " + cnt);
                }
                if(cnt == 200) System.out.println(sqube);
            }
        }
    }

    private static boolean isPrimeProof(Long sqube, Boolean[] primes) {
        ArrayList<Integer> squbeArr = new ArrayList<Integer>();
        while(sqube > 0) {
            squbeArr.add((int) (sqube % 10));
            sqube = sqube / 10;
        }
        Collections.reverse(squbeArr);
        Boolean isPrime = false;
        for(int i=0; i<squbeArr.size(); i++) {
            for(int number = 0; number <= 9; number++) {
                int prevValue = squbeArr.get(i);
                squbeArr.set(i, number);
                int newSqube = 0;
                for(Integer val: squbeArr) { newSqube = (newSqube * 10) + val; }
                if(checkPrime(newSqube)) {
                    isPrime = true;
                    break;
                }
                squbeArr.set(i, prevValue);
            }
            if(isPrime) break;
        }
        if(!isPrime && contains200(squbeArr)) return true;
        else return false;
    }

    private static boolean contains200(ArrayList<Integer> squbeArr) {
        for(int i=0; i < squbeArr.size() - 2; i++) {
            int first = squbeArr.get(i), second = squbeArr.get(i+1), third = squbeArr.get(i+2);
            int number = (first * 100) + (second * 10) + third;
            if(number == 200) return true;
        }
        return false;
    }

    private static boolean checkPrime(int number) {
        if(number < 2) return false;
        for(int i=2; i<number; i++) {
            if(number % i == 0) return  false;
        }
        return true;
    }

    private static Boolean[] generatePrimes(int max_limit) {
        // Implement Sieve of Erosthenes to get all primes
        Boolean[] primes = new Boolean[max_limit+1];
        Arrays.fill(primes, true);
        primes[0] = false; primes[1] = false;

        for(int i = 2; i <= Math.sqrt(max_limit); i++) {
            if(primes[i]) {
                for(int j = i*i; j <= max_limit; j = j+i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
}
