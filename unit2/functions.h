
#ifndef HELLOWORLD_FUNCTIONS_H
#define HELLOWORLD_FUNCTIONS_H
#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_ip_pool(const vector<vector<string>>& ip_pool)
{
    for (std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
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

vector<vector<string>> filters_by_pos(const vector<vector<string>>& ip_pool)
{
    return ip_pool;
}

vector<vector<string>> filter_by_pos(const vector<vector<string>>& ip_pool, std::pair<uint8_t, uint8_t> pos_val_filter)
{
    auto [position, value] = pos_val_filter;
    if(position>ip_pool.front().size())
        throw std::invalid_argument("position max value 3");
    vector<vector<string>> filtered_ip;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(filtered_ip), [position, value_str = to_string(value)](const auto& ip_str) {
        return ip_str[position] == value_str;

    });
    return filtered_ip;
}

template <class First, class... Other>
vector<vector<string>> filters_by_pos(const vector<vector<string>>& ip_pool, First first, Other... other)
{
    auto res = filter_by_pos(ip_pool, first);
    // return filter_by_pos(res, other...);
    return filters_by_pos(res, other...);

}

bool comparator(const vector<string>& lhs_ip, const vector<string>& rhs_ip)
{
    for (size_t i = 0; i < lhs_ip.size(); i++)
    {
        if (lhs_ip[i] != rhs_ip[i])
            return atoi(lhs_ip[i].c_str()) > atoi(rhs_ip[i].c_str());
    }
    return false;
}

vector<vector<string>> filter_by_value(const vector<vector<string>>& ip_pool, uint8_t filter_value)
{
    string filter_val_str = to_string(filter_value);
    vector<vector<string>> filtered_ip;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(filtered_ip), [filter_val_str](const auto& ip_str) {
        auto find_iter = std::find(begin(ip_str), end(ip_str), filter_val_str);
        return find_iter != ip_str.end();

    });
    return filtered_ip;
}

#endif //HELLOWORLD_FUNCTIONS_H
