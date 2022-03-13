
#ifndef HELLOWORLD_FUNCTIONS_H
#define HELLOWORLD_FUNCTIONS_H
#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
const uint8_t  kBytesCount = 4;

std::array<uint8_t, kBytesCount> split(const std::string& str, char d)
{
    std::array<uint8_t, kBytesCount> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    uint8_t index = 0;
    while (stop != std::string::npos)
    {
        r[index++]=(std::stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r[index++]=(std::stoi(str.substr(start)));

    return r;
}

void print_ip_pool(const vector<std::array<uint8_t, kBytesCount>>& ip_pool)
{
    for (vector<std::array<uint8_t, kBytesCount>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for (std::array<uint8_t, kBytesCount>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

vector<std::array<uint8_t, kBytesCount>> filters_by_pos(const vector<std::array<uint8_t, kBytesCount>>& ip_pool)
{
    return ip_pool;
}

vector<std::array<uint8_t, kBytesCount>>filter_by_pos(const vector<std::array<uint8_t, kBytesCount>>& ip_pool, std::pair<uint8_t, uint8_t> pos_val_filter)
{
    auto [position, value] = pos_val_filter;
    if(position>ip_pool.front().size())
        throw std::invalid_argument("position max value 3");
    vector<std::array<uint8_t, kBytesCount>> filtered_ip;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(filtered_ip), [position, value](const auto& ip) {
        return ip[position] == value;

    });
    return filtered_ip;
}

template <class First, class... Other>
vector<std::array<uint8_t, kBytesCount>> filters_by_pos(const vector<std::array<uint8_t, kBytesCount>>& ip_pool, First first, Other... other)
{
    auto res = filter_by_pos(ip_pool, first);
    // return filter_by_pos(res, other...);
    return filters_by_pos(res, other...);

}

vector<std::array<uint8_t, kBytesCount>> filter_by_value(const vector<std::array<uint8_t, kBytesCount>>& ip_pool, uint8_t filter_value)
{
    //string filter_val_str = to_string(filter_value);
    vector<std::array<uint8_t, kBytesCount>> filtered_ip;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(filtered_ip), [filter_value](const auto& ip_str) {
        auto find_iter = std::find(begin(ip_str), end(ip_str), filter_value);
        return find_iter != ip_str.end();

    });
    return filtered_ip;
}

#endif //HELLOWORLD_FUNCTIONS_H
