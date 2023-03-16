#ifndef ARRAY_UTIL
#define ARRAY_UTIL

#include <vector>
using namespace std;

// GetHighest is a recursive function that returns the highest value in an array (O(n log n))
template <class T>

// signature for array
T getHighest(T * buffer, int size) {
    if (size == 1) {
        return buffer[0];
    } else if (size == 2) {
        return buffer[0] > buffer[1] ? buffer[0] : buffer[1];
    } else {
        T left = getHighest(buffer, size / 2);
        T right = getHighest(buffer + size / 2, size - size / 2);
        return left > right ? left : right;
    }
};

template <class T>
// signature for vector
T getHighest(vector<T> buffer) {
    return getHighest(buffer.data(), buffer.size());
};

#endif