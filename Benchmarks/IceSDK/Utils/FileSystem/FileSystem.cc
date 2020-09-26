#include "Utils/FileSystem.h"

#include <benchmark/benchmark.h>

using namespace IceSDK;

static void BM_FileSystem_JoinPath(benchmark::State& state)
{
    // Perform setup here
    for (auto _ : state)
    {
        // This code gets timed
        FileSystem::JoinPath("C:\\Path\\To\\IceSDK", "out");
    }
}

// Register the function as a benchmark
BENCHMARK(BM_FileSystem_JoinPath);

// Run the benchmark
BENCHMARK_MAIN();
