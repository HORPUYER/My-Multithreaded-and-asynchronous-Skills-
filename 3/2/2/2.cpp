#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>

void For_each(std::vector<int>::iterator begin, std::vector<int>::iterator end, void (*function)(int&)) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        function(*it);
    }
}

void print(int& num) {
    std::cout << num << " ";
}

void divide_container(std::vector<int>& container) {
    if (container.size() == 1) {
        std::function<void(int&)> func = print;
        std::future<void> f = std::async(std::launch::async, For_each, container.begin(), container.end(), &print);
        f.get();
        return;
    }
    if (container.empty()) {
        return;
    }

    int n_size = container.size() / 2;
    std::vector<int> left, right;

    for (int i = 0; i < n_size; i++) {
        left.push_back(container[i]);
    }
    for (int i = n_size; i < container.size(); i++) {
        right.push_back(container[i]);
    }

    divide_container(left);
    divide_container(right);
}

int main()
{
    std::vector<int> vec = { 1,2,3,4,5,6,7,8,9,0,51,55,32,87,90 };

    divide_container(vec);

    return 0;
}