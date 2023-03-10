#ifndef IO_HPP
#define IO_HPP

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>

bool output(const std::vector<std::vector<double>> data, const std::string& fileLocation) {
    std::ofstream out(fileLocation);

    for (uint64_t it = 0; it < data[0].size(); it++) {
        for (uint64_t column = 0; column < data.size(); column++) out << data[column][it] << ",";
        out << std::endl;
    }

    out.close();

    return true;
}

template <typename Container>
bool outputData(const Container& data, const std::string& fileLocation) {
    std::ofstream out(fileLocation);
    if (!out) return false;

    for (const auto& row : data) {
        std::copy(row.begin(), row.end() - 1, std::ostream_iterator<typename Container::value_type::value_type>(out, ","));
        out << row.back() << '\n';
    }

    return true;
}

template <typename T>
bool writeToFile(T begin, T end, const std::string fileLocation) {
    // Check for empty range
    if (begin == end) return true;

    std::ofstream out(fileLocation);
    while (begin++ != end) out << *begin << "," << std::endl;
    out.close();

    return true;
}

#endif
