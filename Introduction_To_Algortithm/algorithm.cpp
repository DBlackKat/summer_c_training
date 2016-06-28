#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
void find_function(){
	int n1 = 6;
	int n2 = 5;
	vector<int> v{0, 1, 2, 3, 6};
	int c[6] = {1,3,4,5,8,9};
	auto result1 = find(begin(v),end(v),n1);
	auto result2 = find(begin(v),end(v),n2);
	if(result1 != end(v)){
		printf("%d is in vector\n",n1);
	}
	else{
		printf("%d is not in vector\n",n1);	
	}
	if(result2 != end(v)){
		printf("%d is in vector\n",n2);
	}
	else{
		printf("%d is not in vector\n",n2);	
	}

	auto find1 = find(c,c+3,n1);
	if(find1 != c+3){
		printf("%d is in array c",n1);
	}
	else{
		printf("%d is NOT in array c",n1);	
	}
}
void for_each_function(){
	struct class1{
		void operator()(int x){
			printf("%d ",x);
		}
	}obj1;

	int arr[5] = {3,1,6,7,10};
	for_each(arr,arr+5,obj1);
}
void fill_function(){
	int c[5] = {43,5,12,4,2};
	for(int i=0;i<5;i++)
		printf("%d ",c[i]);
	fill(c,c+5,-1);
	for(int i=0;i<5;i++)
		printf("%d ",c[i]);
}	
int main(){
	fill_function();
	return 0;
}