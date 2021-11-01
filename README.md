# compare_executions_parallel_stl

## Execution Policies[**#**]

The policy tag specifies whether an algorithm should run sequentially, in parallel, or in parallel with vectorization.

* **`std::execution::seq`** : runs the algorithm sequentially
* **`std::execution::par`** : runs the algorithm in parallel on multiple threads
* **`std::execution::par_unseq`** : runs the algorithm in parallel on multiple threads and allows the interleaving of individual loops; permits a vectorised version with [SIMD](https://en.wikipedia.org/wiki/SIMD) (**S** ingle **I** nstruction **M** ultiple **D** ata) extensions.

Unfortunately i can not confirm the above namespaces - compiler does compile only either with g++-20 flag using g++-10 compiler, or clang++-11 compiler as follows:

```bash
g++-10 -o 11_execution_policy -std=c++20 11_execution_policy.cpp 
clang++-11 -o 11_execution_policy -std=c++20 11_execution_policy.cpp 
```

Besides, the following namespaces seem to be the right ones: 
```cpp
#include<execution>
typedef std::execution::sequenced_policy sequential_execution;
typedef std::execution::parallel_policy  parallel_execution;
typedef std::execution::parallel_unsequenced_policy parallel_unsequenced_execution;
typedef std::execution::unsequenced_policy   unsequenced_execution;
```