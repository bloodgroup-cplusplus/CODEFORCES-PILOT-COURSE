#include<iostream>

int main()
{
	int n;

	std::cout<<"Enter the size of the array"<<std::endl;
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the values in the array"<<std::endl;
	for(auto &y:a) std::cin>>y;
	std::cout<<"Enter the element to search " <<std::endl;
	int x;
	bool found=false;
	std::cin>>x;
	for(int i=0;i<n;++i)
	{
		if (a[i]==x)

		{
			found=true;	
			std::cout<<"found " << x<< " at  index " << i+1<<std::endl;
			break;
		}
			
			
	}
	if (found==false)
		std::cout<<"Element not present in array"<<std::endl;
	return 0;
}


		
