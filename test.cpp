#include <gtest/gtest.h>
#include "Application.h"
#pragma warning(push)
#pragma warning(disable: 4996)

TEST(equaltests, corectfind)
{
	Json_Data_Manager server;
	std::shared_ptr<User> testunit;
	bool file_opened = server.Data_include("New.txt");
	EXPECT_EQ(true, file_opened);
	if (file_opened)
	{
		testunit = server.find("Anna");
		EXPECT_EQ("Oozb9912.", testunit->show_password());
	}
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#pragma warning(pop)