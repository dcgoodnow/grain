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
			v4 = Vector<double>(4);
			v5 = Vector<double>(2);
			v2.set(0, 2.45);
			v2.set(3, 1.4);
			v3.set(0, 0);
			v3.set(1, -.4);
			v3.set(2, 2);
			v3.set(3, 5);
			v4[0] = 1;
			v4[1] = 5;
			v4[2] = 2;
			v4[3] = 3;
		}

		Vector<double> v1;
		Vector<double> v2;
		Vector<double> v3;
		Vector<double> v4;
		Vector<double> v5;
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
	ASSERT_EQ(2.45, v2[0]);
	ASSERT_EQ(0, v2[1]);
	ASSERT_EQ(-.4, v3[1]);
	ASSERT_THROW(v2[4], std::out_of_range);
};

TEST_F(VectorTest, SetElements)
{
	v2.set(1, 2.5);
	ASSERT_EQ(2.5, v2[1]);
	v2[2] = 3.54;
	ASSERT_EQ(3.54, v2[2]);
	ASSERT_THROW(v2[4] = 5, std::out_of_range);
	ASSERT_THROW(v2.set(16, 2), std::out_of_range);
}

TEST_F(VectorTest, DotProduct)
{
   double result = v3.dot(v4);
   ASSERT_EQ(result, 17);
   result = v3 * v4;
   ASSERT_EQ(result, 17);
   ASSERT_THROW(v3 * v5, IncompatibleSizeException);
   ASSERT_THROW(v3.dot(v5), IncompatibleSizeException);
}

TEST_F(VectorTest, ScalarProduct)
{
   Vector<double> result = v3 * 2;
   ASSERT_EQ(result[0], 0);
   ASSERT_EQ(result[1], -.8);
   ASSERT_EQ(result[2], 4);
   ASSERT_EQ(result[3], 10);
   result = 2 * v3;
   ASSERT_EQ(result[0], 0);
   ASSERT_EQ(result[1], -.8);
   ASSERT_EQ(result[2], 4);
   ASSERT_EQ(result[3], 10);
}

TEST_F(VectorTest, CopyConstructor)
{
   Vector<double> copied(v3);
   ASSERT_EQ(copied[0], v3[0]);
   ASSERT_EQ(copied[1], v3[1]);
   ASSERT_EQ(copied[2], v3[2]);
   ASSERT_EQ(copied[3], v3[3]);
   v3[2] = 7;
   ASSERT_NE(copied[2], v3[2]);
}
TEST_F(VectorTest, AssignmentOp)
{
   Vector<double> copied = v3;
   ASSERT_EQ(copied[0], v3[0]);
   ASSERT_EQ(copied[1], v3[1]);
   ASSERT_EQ(copied[2], v3[2]);
   ASSERT_EQ(copied[3], v3[3]);
   v3[2] = 7;
   ASSERT_NE(copied[2], v3[2]);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
