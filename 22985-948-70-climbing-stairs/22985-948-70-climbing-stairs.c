double factorial(int n){
    double factorial = 1; 
    while (n > 0){
        factorial *= n;
        n--;
    }
    return factorial;
}

int climbStairs(int n) {
    double n_ways = 0;
    int count = 0;
    while (count <= n/2){
        n_ways += factorial(n-count)/(factorial(n-2*count)*factorial(count));
        count++;
    } 
    return n_ways;
}