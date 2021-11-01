#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<execution>
#include<typeinfo>

long long int mysize = 10000000;


template<typename T>
void compute_sort(std::vector<int> _myvec, T t, std::string s){
    auto start = std::chrono::system_clock::now();
    std::sort(t, _myvec.begin(), _myvec.end());
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> dur = end-start;
    std::cout << dur.count() << " seconds had been passed for " << s <<std::endl;
}


template<typename T>
void compute_reverse(std::vector<int> _myvec, T t, std::string s){
    auto start = std::chrono::system_clock::now();
    std::reverse(t, _myvec.begin(), _myvec.end());
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> dur = end-start;
    std::cout << dur.count() << " seconds had been passed for " << s <<std::endl;
}

int main(){
    
    std::vector<int> myvec(mysize, 1);
    
    typedef std::execution::sequenced_policy sequential_execution;
    typedef std::execution::parallel_policy  parallel_execution;
    typedef std::execution::parallel_unsequenced_policy parallel_unsequenced_execution;
    typedef std::execution::unsequenced_policy   unsequenced_execution;
    sequential_execution s;
    parallel_execution p;
    parallel_unsequenced_execution pus;
    unsequenced_execution u;
    
    
    //sort comparison
    std::cout << "sorting speed comparison" << std::endl;
    compute_sort(myvec, s,"sequential");
    compute_sort(myvec, p,"parallel");
    compute_sort(myvec, pus,"parallel unsequenced");
    compute_sort(myvec, u,"unsequenced_execution");
    

    //reverse comparison
    std::cout << "reverse speed comparison" << std::endl;
    compute_reverse(myvec, s,"sequential");
    compute_reverse(myvec, p,"parallel");
    compute_reverse(myvec, pus,"parallel unsequenced");
    compute_reverse(myvec, u,"unsequenced_execution");


    return 0;
}