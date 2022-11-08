#include <stdio.h>
#include <inttypes.h>

#define LIMIT 1000000
int phi[LIMIT+1];

void init()
{
    phi[1] = 1;
    int n, p, f, i;
    for(i = 2; i*i <= LIMIT; i++){
        p = phi[i];
        if(!p){//prime
            phi[i] = i-1;
            for(int j = i*i; j <= LIMIT; j+= i){
                phi[j] = i;
            }
        }else{//p is a prime factor
            n = i/p;            
            f = p;
            while(n%f == 0){
                f*=p;
            }
            n = i/f;
            f = (f/p)*(p-1);
            phi[i] = f*phi[n];
        }
    }
    
    //every prime is marked
    for(; i <= LIMIT; i++){
        p = phi[i];
        if(!p){//prime
            phi[i] = i-1;
        }else{//p is a prime factor
            n = i/p;            
            f = p;
            while(n%f == 0){
                f*=p;
            }
            n = i/f;
            f = (f/p)*(p-1);
            phi[i] = f*phi[n];
        }
    }
}


int main()
{
    init();

    int64_t sum = 0;

    for(int i = 2; i<= LIMIT; i++){
        sum += phi[i];
    }

    printf("%" PRId64 "\n", sum);

}