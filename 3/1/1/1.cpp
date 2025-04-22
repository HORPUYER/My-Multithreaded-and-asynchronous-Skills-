#include <iostream>
#include<thread>
#include<future>
#include<vector>
#include<algorithm>

auto FindMin(std::vector<int>& fvec, int num) {
	std::future<int> fut;
	std::promise<int> p;
	fut = p.get_future();
	int min_index = num;
	for (int i = num + 1; i < fvec.size(); i++) {
		if (fvec[i]<fvec[min_index]) {
			min_index = i;
		}
	}
	p.set_value(min_index);
	return fut;
}

int main()
{
	std::vector<int> vec = { 2,4,3,1,7,5,6,9,8,0 };
	for(int& n : vec) {
		std::cout << n << ", ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < vec.size(); i++) {
		std::future<int> f = FindMin(vec,i);
		int min_index = f.get();
		std::swap(vec[i], vec[min_index]);
	}
	for (int& n : vec) {
		std::cout << n << ", ";
	}
}