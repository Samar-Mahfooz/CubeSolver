//
// Created by Samar on 06-07-2025.
//

#include "math.h"

uint32_t factorial(uint32_t n){
    return n <= 1 ? 1 : n * factorial(n - 1);
}

uint32_t pick(uint32_t n, uint32_t k){
    return factorial(n) / factorial(n - k);
}

uint32_t choose(uint32_t n, uint32_t k){
    return (n < k)
           ? 0
           : factorial(n) / (factorial(n - k) * factorial(k));
}
