#include<stdio.h>
#include<math.h>
 
int compute(int a, int m, int n)
{
	int r;
	int y = 1;

	while (m > 0)
	{
		r = m % 2;

		// fast exponention
		if (r == 1)
			y = (y*a) % n;
		a = a*a % n;

		m = m / 2;
	}

	return y;
}


int main()
{
    long long int p, g, x, a, y, b, ka, kb, A, B; 
     
  
    
    printf("Enter value of P :\n");
    scanf("%lld",&p); 
 
   
    printf("Enter value of G : \n");
    scanf("%lld",&g); 
 
   
 printf("Enter value of A : \n");
    scanf("%lld",&a);

    printf("The private key a for Alice : %lld\n", a);
    A = compute(g, a, p);
	printf("Alice's public key is %lld\n",A);
     
   
 printf("Enter value of B : \n");
    scanf("%lld",&b);

    printf("The private key b for Bob : %lld\n", b);
    B = compute(g, b, p);
    printf("Bob's public key is %lld\n",B);
    
   	ka = compute(B, a, p);
	kb = compute(A, b, p);
     
    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);
     
    return 0;
}
