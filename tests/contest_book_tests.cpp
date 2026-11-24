// Tests for a selection of the programs in "Programming contest Book 00".
//
// Every program is a stand-alone .cpp file with its own main(), so each one is
// included here unchanged inside its own namespace, with its main() renamed.
//
// Run from the repository root:
//   g++ -std=c++17 tests/contest_book_tests.cpp -o tests/contest_book_tests.out && ./tests/contest_book_tests.out
//
// Every standard header used by the programs has to be included here first,
// so that their own #include lines do nothing once inside a namespace.

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define main programMain
// a real main() may end without "return 0;"; renamed, it would draw a warning
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

namespace stackDs {
#include "../Programming contest Book 00/Data Structure/Stack.cpp"
}
namespace queueDs {
#include "../Programming contest Book 00/Data Structure/Queue.cpp"
}
namespace dequeDs {
#include "../Programming contest Book 00/Data Structure/Dequeu.cpp"
}
namespace monotonicStack {
#include "../Programming contest Book 00/Data Structure/Monotomic Stack.cpp"
}
namespace binarySearch {
#include "../Programming contest Book 00/Searching and sorting/Searching/Binary search.cpp"
}
namespace ternarySearch {
#include "../Programming contest Book 00/Searching and sorting/Searching/Ternary search.cpp"
}
namespace interpolationSearch {
#include "../Programming contest Book 00/Searching and sorting/Searching/Interpolation Search.cpp"
}
namespace linearSieve {
#include "../Programming contest Book 00/Number Theory/LinearSieve.cpp"
}
namespace arrayRotate {
#include "../Programming contest Book 00/Number Theory/ArrayRotate.cpp"
}
namespace gcdLcm {
#include "../Programming contest Book 00/Number Theory/LCM.cpp"
}
namespace extendedGcd {
#include "../Programming contest Book 00/Number Theory/ExtendedGCD.cpp"
}
namespace trie {
#include "../Programming contest Book 00/TREE/Tri.cpp"
}
namespace subsetSum {
#include "../Programming contest Book 00/Dynamic Programming/Subset Sum.cpp"
}
namespace slidingWindow {
#include "../Programming contest Book 00/Advance/Sliding Window Technique.cpp"
}
namespace kadane {
#include "../Programming contest Book 00/Tecnique/Kadane's.cpp"
}
namespace prefixSum {
#include "../Programming contest Book 00/Tecnique/PrefixSum.c++"
}

#pragma GCC diagnostic pop
#undef main

typedef std::vector<int> V;

static int checks = 0;
static int failures = 0;

#define CHECK(cond)                                                          \
    do {                                                                     \
        checks++;                                                            \
        if (!(cond)) {                                                       \
            failures++;                                                      \
            std::cerr << "FAIL line " << __LINE__ << ": " << #cond << "\n"; \
        }                                                                    \
    } while (0)

// runs f() and returns what it printed with cout
template <class F>
static std::string printed(F f) {
    std::ostringstream out;
    std::streambuf *old = std::cout.rdbuf(out.rdbuf());
    f();
    std::cout.rdbuf(old);
    return out.str();
}

static bool contains(const std::string &text, const std::string &part) {
    return text.find(part) != std::string::npos;
}

static void testStackQueueDequeue() {
    stackDs::Stack s;
    CHECK(s.isEmpty());
    s.push(10);
    s.push(20);
    CHECK(s.top() == 20);
    CHECK(s.pop() == 20);
    CHECK(s.size() == 1);

    queueDs::Queue q;
    q.enqueue(1);
    q.enqueue(2);
    CHECK(q.front() == 1);
    CHECK(q.dequeue() == 1);
    CHECK(q.size() == 1);

    dequeDs::Dequeue d;
    d.enqueueBack(10);
    d.enqueueFront(5);
    CHECK(d.front() == 5);
    CHECK(d.back() == 10);
    CHECK(d.dequeueBack() == 10);
    CHECK(d.dequeueFront() == 5);
    CHECK(d.isEmpty());
}

static void testNextGreaterAndSmaller() {
    CHECK(monotonicStack::NextGreaterElement(V{4, 5, 2, 25}) == (V{5, 25, 25, -1}));
    CHECK(monotonicStack::NextSmallerElement(V{4, 5, 2, 25}) == (V{2, 2, -1, -1}));
}

// The three searches must agree with a plain look-up, also for targets that
// are absent, below or above the range, and for empty and one-element arrays
// (ternary and interpolation search used to read outside the array there).
static void testSearches() {
    std::vector<V> arrays = {{}, {5}, {1, 3}, {4, 4, 4}, {1, 3, 5, 7, 9, 11, 13}, {10, 20, 30, 40, 50, 60}};
    int mismatches = 0;
    for (V &arr : arrays) {
        for (int target = -100; target <= 100; target++) {
            bool expected = std::find(arr.begin(), arr.end(), target) != arr.end();
            if (binarySearch::isfound(arr, target) != expected) mismatches++;
            if (ternarySearch::isfound(arr, target) != expected) mismatches++;
            if (interpolationSearch::isfound(arr, target) != expected) mismatches++;
        }
    }
    CHECK(mismatches == 0);
}

static void testLinearSieve() {
    CHECK(linearSieve::Linear_Sieve(30) == (V{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}));
    CHECK(linearSieve::Linear_Sieve(2) == (V{2}));
    // nothing below 2 (these used to touch a vector that was too small)
    CHECK(linearSieve::Linear_Sieve(1).empty());
    CHECK(linearSieve::Linear_Sieve(0).empty());
    CHECK(linearSieve::Linear_Sieve(-1).empty());
}

static void testArrayRotateOnTinyArrays() {
    V empty, one = {7};
    arrayRotate::ArrayRotate(empty, 3); // used to compute 3 % 0
    arrayRotate::ArrayRotate(one, 5);
    CHECK(empty.empty());
    CHECK(one == (V{7}));
}

static void testGcdAndLcm() {
    CHECK(gcdLcm::findGCD(12, 18) == 6);
    CHECK(gcdLcm::findGCD(17, 5) == 1);
    CHECK(gcdLcm::findLCM(4, 6) == 12);

    int x = 0, y = 0;
    CHECK(extendedGcd::extendedGCD(30, 20, x, y) == 10);
    CHECK(30 * x + 20 * y == 10);
}

static void testTrie() {
    trie::TrieNode *root = trie::createNode();
    trie::insert(root, "flower");
    trie::insert(root, "flow");
    CHECK(trie::isfound("flow", root));
    CHECK(trie::isfound("flower", root));
    CHECK(!trie::isfound("flo", root)); // only a prefix

    // BOX[] has 26 slots: other characters must be refused, not used as an index
    CHECK(!trie::isfound("Flow", root));
    CHECK(!trie::isfound("fl0w", root));
    std::string message = printed([&] { trie::insert(root, "Hello"); });
    CHECK(contains(message, "Skipped Hello"));
    CHECK(!trie::isfound("ello", root));

    // an empty trie has nothing to follow
    trie::TrieNode *emptyRoot = trie::createNode();
    CHECK(printed([&] { trie::found(emptyRoot); }).empty());
}

static void testInputThatDoesNotFitIsRefused() {
    // a negative number would index dp[] below zero
    CHECK(contains(printed([] { subsetSum::SubsetSum(V{-5, 3}, 10); }), "must not be negative"));
    CHECK(contains(printed([] { subsetSum::SubsetSum(V{2, 3}, -4); }), "must not be negative"));
    std::string sums = printed([] { subsetSum::SubsetSum(V{2, 3}, 5); });
    CHECK(sums == "subset sum possible for 0\nsubset sum possible for 2\n"
                  "subset sum possible for 3\nsubset sum possible for 5\n");

    // a window larger than the array would read past its end
    V numbers = {1, 2, 3};
    CHECK(contains(printed([&] { slidingWindow::Window(numbers, 10); }), "Window size must be"));
    CHECK(contains(printed([&] { slidingWindow::Window(numbers, 0); }), "Window size must be"));
}

static void testKadaneAndPrefixSum() {
    V nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    CHECK(kadane::kadane(nums) == 6);

    V arr = {1, 2, 3, 4};
    CHECK(prefixSum::PrefixSum(arr) == (V{1, 3, 6, 10}));
    CHECK(prefixSum::PrefixSumOffset(arr) == (V{0, 1, 3, 6, 10}));
}

int main() {
    testStackQueueDequeue();
    testNextGreaterAndSmaller();
    testSearches();
    testLinearSieve();
    testArrayRotateOnTinyArrays();
    testGcdAndLcm();
    testTrie();
    testInputThatDoesNotFitIsRefused();
    testKadaneAndPrefixSum();

    std::cout << (checks - failures) << "/" << checks << " checks passed\n";
    return failures == 0 ? 0 : 1;
}
