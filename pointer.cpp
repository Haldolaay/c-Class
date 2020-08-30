int main ( ){
	int a=10;
	int b=5;
	int *c;		
	float *f;
	int **e;

	printf("%p\n",&a);//Display the address using %p
                  		//format specifier.

	c=&b;			
	*c=20;		
      e=&c;		
	*e=&a;		
				
	**e=30;		
	cout<<&c<<” “<<c<<” “<<*c<<endl;
	cout<<&e<<” “<<e<<” “<<*e<<” “<<**e;

	//f=&a;			//INVALID
	//f=&b;			//INVALID
	//e=&a;			//INVALID
	//&a=&b;		      //Cannot modify an addresses
}
