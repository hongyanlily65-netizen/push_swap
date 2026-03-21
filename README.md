*Este proyecto ha sido creado como parte del currículo de 42 por aykhan-i y hohu.*

# Push_swap

> *Because Swap_push doesn't sound as natural.*

---

## Description

**Push_swap** is an algorithmic project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, producing the **shortest possible sequence of instructions**.

The project explores algorithmic complexity in a concrete way: sorting numbers fast with only two stacks and a handful of allowed moves is a real challenge. The program implements **four distinct sorting strategies** of different complexity classes and selects the most appropriate one based on a disorder index computed from the initial state of the stack.

### Available operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap the top two elements of stack a / b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push top of b to a / top of a to b |
| `ra` / `rb` | Rotate stack a / b upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack a / b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Instructions

### Requirements

- C compiler (`cc`)
- `make`

### Compilation

```bash
# Clone the repository and enter the project directory
git clone <repo_url>
cd Push_swap

# Compile
make

# Clean object files
make clean

# Full clean (removes binary)
make fclean

# Recompile from scratch
make re


### Usage

```bash
# Basic usage (adaptive mode by default)
./push_swap 4 67 3 87 23

# Force a specific strategy
./push_swap --simple  5 4 3 2 1
./push_swap --medium  5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Count the number of operations
ARG=($(seq 1 100 | shuf)); ./push_swap --complex ${ARG[@]} | wc -l

# Verify correctness with the provided checker
 ARG=($(seq 1 100 | shuf)); ./push_swap --complex ${ARG[@]} | ./checker_linux ${ARG[@]}

# Benchmark mode: show metrics to stderr while piping ops to checker
./push_swap --bench --adaptive 4 67 3 87 23

# Generate 500 random numbers and sort them
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
```

### Error handling

The program prints `Error` to stderr and exits on:
- Non-integer arguments
- Integers out of range (`INT_MIN` / `INT_MAX`)
- Duplicate numbers

---

## Algorithms

### Disorder index

Before any move, the program computes a **disorder index** between `0` and `1` that measures how far the stack is from being sorted. It counts the number of *inversions* (pairs where a larger number appears before a smaller one) over the total number of pairs:

```
disorder = mistakes / total_pairs
```

- `0` → already sorted  
- `1` → maximally disordered

This index drives strategy selection in adaptive mode.

---

### Strategy 1 — Bubble Sort · O(n²) · `--simple`

**Algorithm:** An adaptation of bubble sort to the Push_swap operation model. The algorithm makes repeated passes through stack a, using `sa` to fix adjacent inversions and `ra`/`rra` to move elements into position. It terminates as soon as no swaps are needed.

**Why O(n²):** In the worst case, n passes of up to n comparisons each are needed — O(n²) operations.

**Best for:** Very small inputs (≤ 5 elements) or nearly-sorted sequences where few inversions exist.

---

### Strategy 2 — Chunk Sort · O(n√n) · `--medium`

**Algorithm:** The sorted index range `[0, n)` is divided into `√n` chunks of equal size. Elements belonging to the current chunk are pushed to stack b (using `ra`/`rra` to find them efficiently), from largest to smallest within each chunk. Once all chunks are processed, elements are pushed back from b to a in order.

**Why O(n√n):** There are `√n` chunks. Finding and pushing all elements of each chunk costs O(n) operations (one full scan per chunk), giving O(n · √n) total.

**Thresholds justification:** `√n` chunks balance the per-chunk scan cost against the number of chunks. Fewer chunks → longer scans; more chunks → too many push-back steps. `√n` is the empirical sweet spot minimising total operations.

**Best for:** Medium disorder (`0.2 ≤ disorder < 0.5`) and medium-sized inputs (≈ 100–500 numbers).

---

### Strategy 3 — Radix Sort (LSD) · O(n log n) · `--complex`

**Algorithm:** Elements are first assigned rank indices from `0` to `n-1` (normalisation). Then a standard LSD (Least Significant Bit first) radix sort is applied bit by bit. For each bit position, elements whose bit is `0` are pushed to b (`pb`), while elements whose bit is `1` stay and rotate to the bottom of a (`ra`). After processing the bit, all elements are pushed back from b to a (`pa`). After `log₂(n)` passes, stack a is fully sorted.

**Why O(n log n):** Each of the `⌈log₂(n)⌉` bit passes processes all `n` elements, giving O(n log n) total operations.

**Space:** O(n) — the second stack b is used as temporary storage, bounded by the input size.

**Best for:** High disorder (`disorder ≥ 0.5`) and large inputs (≈ 500+ numbers), where the consistent log-linear performance dominates.

---

### Strategy 4 — Adaptive · `--adaptive` *(default)*

The adaptive strategy selects one of the three algorithms above based on the disorder index computed at startup:

| Disorder range | Selected strategy | Complexity |
|---|---|---|
| `disorder < 0.2` | Bubble Sort (O(n) in near-sorted cases) | O(n) |
| `0.2 ≤ disorder < 0.5` | Chunk Sort | O(n√n) |
| `disorder ≥ 0.5` | Radix Sort (LSD) | O(n log n) |

**Threshold justification:**
- `0.2` separates nearly-sorted stacks (where bubble sort's early-exit property reduces it to O(n)) from moderately disordered ones.
- `0.5` separates moderate disorder (where chunk sort's block-based approach is efficient) from high disorder (where radix sort's predictable linear-time passes per bit are optimal).

These thresholds were determined empirically by benchmarking all three algorithms across disorder ranges and selecting the crossover points where each strategy outperforms the others.

---

## Performance targets

| Input size | Min (pass) | Good | Excellent |
|---|---|---|---|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Benchmark mode (`--bench`)

When the `--bench` flag is passed, the following metrics are printed to **stderr** after sorting:

```
[bench] disorder:   49.93%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  7997
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 4840  rb: 1098  rr: 0  rra: 0  rrb: 1059  rrr: 0
```

Operations are still printed to **stdout**, so they can be piped to the checker independently:

```bash
./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt | ./checker_linux 4 67 3 87 23
```

---

## Resources

### Algorithmic references
- [Google Search](https://www.google.com) — used to research sorting algorithm adaptations, Push_swap strategies and complexity analysis
- Classmates' GitHub repositories were consulted for reference during development

### 42-specific resources
- [push_swap visualiser](https://github.com/o-reo/push_swap_visualizer) — visual debugging tool
- [push_swap tester](https://github.com/gemartin99/Push-Swap-Tester) — automated performance testing

### AI usage

AI was used during this project for the following tasks:
- **Algorithm research:** Exploring and comparing approaches for chunk-based and radix-based sorting adapted to the Push_swap operation model.
- **Debugging assistance:** Discussing edge cases in the disorder index calculation and the adaptive strategy thresholds.

All AI-generated content was reviewed, tested, and validated by both team members before inclusion in the project.

---

## Contributions

| Login | Contributions |
|-------|--------------|
| `hohu` | Stack initialisation, parsing, adaptive strategy, disorder index, benchmark mode, index assignment, Makefile |
| `aykhan-i` | Sorting algorithms (bubble sort, chunk sort, radix sort), operation implementations (swap, push, rotate, reverse), error handling, create the structure and header  |
