#include "gtest/gtest.h"
#include "functions.h"

const std::vector<std::vector<std::string>> kIpPool=
        {
                {"1", "2", "3", "4"},
                {"79", "180", "73", "190"},
                {"194" , "106" , "3", "214"},
                {"1" ,"133" , "114", "4"}
        };

TEST(unit2, split)
{
    std::string input_str{"column1\tcolumn2\tcolumn3"};
    auto  splited_stings = split(input_str,'\t');
    ASSERT_EQ(splited_stings.size(), 3);
    ASSERT_EQ(*splited_stings.begin(), "column1");
}

TEST(unit2, comparator)
{
    bool comparsion_result = comparator(kIpPool[0], kIpPool[1]);
    ASSERT_NE(comparsion_result, true);
}


TEST(unit2, filter_by_value)
{
    auto filtere_pool = filter_by_value(kIpPool, 1);
    ASSERT_EQ(filtere_pool.size(), 2);
    ASSERT_EQ(filtere_pool[1][1], "133");
}

TEST(unit2, filters_by_pos)
{
    auto filter_pool = filters_by_pos(kIpPool,  make_pair( 2,3 ));
    ASSERT_EQ(filter_pool.size(), 2);
    ASSERT_EQ(filter_pool[1][0], "194");

    filter_pool = filters_by_pos(kIpPool, make_pair(0,1), make_pair(3,4));
    ASSERT_EQ(filter_pool.size(), 2);
    ASSERT_EQ(filter_pool[1][1], "133");
}
