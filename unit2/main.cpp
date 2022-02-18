
#include "functions.h"

int main()
{
    std::vector<std::vector<std::string> > ip_pool;

    for (std::string line; std::getline(std::cin, line); )
    {
        std::vector<std::string> v = split(line, '\t');
        ip_pool.push_back(split(v.at(0), '.'));
    }

    std::sort(ip_pool.begin(), ip_pool.end(), comparator);
    print_ip_pool(ip_pool);

    auto res_1 = filters_by_pos(ip_pool,  make_pair( 0,1 ));
    print_ip_pool(res_1);

    auto res_46_70 = filters_by_pos(ip_pool, make_pair(0,46), make_pair(1,70));
    print_ip_pool(res_46_70);

    auto res_any = filter_by_value(ip_pool, 46);

   // auto res = filter_by_value(ip_pool, 46);
    print_ip_pool(res_any);
    // print_ip_pool(ip_pool);
}