#include <benchmark/benchmark.h>

#include "include/my_add.h"

static void BenchMarkAdd (benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(my_add(state.range(0), state.range(1)));
    }
}

BENCHMARK(BenchMarkAdd)->Args({2, 2})->Args({2, 3})->Args({-42, 3});

BENCHMARK_MAIN();