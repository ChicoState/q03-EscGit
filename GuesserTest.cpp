/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest, true_test)
{
  Guesser g("Dragon");
  ASSERT_TRUE (g.match("Dragon") );
}

TEST(GuesserTest, length_test)
{
  Guesser g("C o o k i e");
  ASSERT_TRUE(g.match("Cookie"));
}

TEST(GuesserTest, length_test_v2)
{
  Guesser g("Cookie");
  ASSERT_TRUE(g.match("C o o k i e"));
}

TEST(GuesserTest, False_test)
{
  Guesser g("Paper");
  ASSERT_FALSE(g.match("Paber"));
}

TEST(GuesserTest, Multiple_test_matching_correct)
{
  Guesser g("Luffy");
  g.match("Laffy");
  g.match("Laffy");
  ASSERT_EQ(g.remaining(), 1);
  g.match("Luffy");
  ASSERT_EQ(g.remaining(), 3);
}

TEST(GuesserTest, Multiple_test_matching_wrong)
{
  Guesser g("Pikachu");
  g.match("Pikachy");
  g.match("Pikachy");
  g.match("Pikachy");
  ASSERT_EQ(g.remaining(), 0);
  ASSERT_EQ(g.match("Pikachu"), false);
}

TEST(GuesserTest, Distance_Greater_Than_Two)
{
  Guesser g("test");
  ASSERT_FALSE(g.match("abcd"));
  ASSERT_FALSE(g.match("test"));
}

TEST(GuesserTest, Secret_Longer_Than_32)
{
  Guesser g("abcdefghijklmnopqrstuvwxyz1234567890LONGSECRET");
  ASSERT_FALSE(g.match("abcdefghijklmnopqrstuvwxyz123456"));
}


TEST(GuesserTest, Short_Test)
{
  Guesser g("hi");
  ASSERT_TRUE(g.match("hi"));
}

TEST(GuesserTest, Empty_Test)
{
  Guesser g("bye");
  ASSERT_FALSE(g.match(""));
}

TEST(GuesserTest, Boundary_Limit)
{
  Guesser g("xyz");
  ASSERT_FALSE(g.match("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
  ASSERT_EQ(g.remaining(), 2);
}