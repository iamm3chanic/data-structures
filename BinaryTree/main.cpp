#include "BinarySearchTree.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <chrono>
#include <vector>


int main(int argc, char** argv) {
    argc=argc;
    int size = atoi(argv[1]);

    BinarySearchTree<int> bs_tree;

    std::vector<int> numbers;
    for (int i = 0; i < size; i++) {
        numbers.push_back(i);
    }
    std::random_shuffle(numbers.begin(), numbers.end());

    auto start = std::chrono::system_clock::now();
    for (auto n : numbers) {
        bs_tree.insert(n);
    }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = end-start;
    std::cout << "Insertion: " << diff.count() << " s" << std::endl;

//    bs_tree.inorder_print();

    std::random_shuffle(numbers.begin(), numbers.end());

    start = std::chrono::system_clock::now();
    for (auto n : numbers) {
        bs_tree.remove(n);
    }
    end = std::chrono::system_clock::now();

    diff = end-start;
    std::cout << "Removal: " << diff.count() << " s" << std::endl;


    /*
    start = std::chrono::system_clock::now();
    for (auto n : numbers) {
        bs_tree.pop();
    }
    end = std::chrono::system_clock::now();
    diff = end-start;
    std::cout << "Pop: " << diff.count() << " s" << std::endl;
    */

    return 0;
}
