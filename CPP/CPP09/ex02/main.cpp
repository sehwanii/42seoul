#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

template <typename Container>
typename Container::iterator binaryInsertPosition(Container& sorted, int value) {
    typename Container::iterator low = sorted.begin();
    typename Container::iterator high = sorted.end();

    while (low < high) {
        typename Container::iterator mid = low + (high - low) / 2;
        if (*mid < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

template <typename Container>
void fordJohnsonSort(Container& arr) {
    int n = arr.size();
    if (n <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i + 1 < n; i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    Container bigs;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].second);
    fordJohnsonSort(bigs); // 재귀 호출

    Container result(bigs.begin(), bigs.end());
    for (std::size_t i = 0; i < pairs.size(); ++i) {
        int small = pairs[i].first;
        typename Container::iterator pos = binaryInsertPosition(result, small);
        result.insert(pos, small);
    }

    if (n % 2 == 1) {
        int leftover = arr[n - 1];
        typename Container::iterator pos = binaryInsertPosition(result, leftover);
        result.insert(pos, leftover);
    }

    arr = result;
}

bool isPositiveInteger(const std::string& s) {
    for (std::size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return !s.empty() && s != "0";
}

void printContainer(const std::vector<int>& v) {
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        std::istringstream iss(arg);
        int num;
        iss >> num;
        input.push_back(num);
    }

    // 출력 전 백업
    std::vector<int> vecInput = input;
    std::deque<int> deqInput(input.begin(), input.end());

    std::cout << "Before: ";
    printContainer(input);

    // vector 정렬
    clock_t startVec = clock();
    fordJohnsonSort(vecInput);
    clock_t endVec = clock();

    // deque 정렬
    clock_t startDeq = clock();
    fordJohnsonSort(deqInput);
    clock_t endDeq = clock();

    std::cout << "After: ";
    printContainer(vecInput);

    double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double deqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vecInput.size()
              << " elements with std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deqInput.size()
              << " elements with std::deque: " << deqTime << " us" << std::endl;

    return 0;
}
