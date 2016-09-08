#include <Vector.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace grain;

class VectorTest : public ::testing::Test {

	protected:
		virtual void SetUp()
		{
			v1 = Vector<double>();
			v2 = Vector<double>(4);
			v3 = Vector<double>(4);
			v2.set(0, 2.45);
			v2.set(3, 1.4);
			v3.set(1, -.4);

		}

		Vector<double> v1;
		Vector<double> v2;
		Vector<double> v3;

};

TEST_F(VectorTest, SetToZero)
{
	ASSERT_EQ(0, v2.at(1));
};

TEST_F(VectorTest, RetrieveElements)
{
	ASSERT_EQ(2.45, v2.at(0));
	ASSERT_EQ(0, v2.at(1));
	ASSERT_EQ(-.4, v3.at(1));
	ASSERT_THROW(v2.at(4), std::out_of_range);

};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}