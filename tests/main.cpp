#include <exception>
#include <iostream>

#include <gtest/gtest.h>


TEST(FirstTest, test)
{
    ASSERT_TRUE(true);
}


int main(int argc, char* argv[])
{
    try
    {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Uncaught exception of unknown type" << std::endl;
    }

    return 1;
}
