// Author: Benjamin Hilton

#include <gtest/gtest.h>
#include "physicsEngine.h"
#include "dynVector.h"

//Unit Tests for Vector class

TEST(oneVector, populate_returnsCorrectValues)
{
    dynVector vec1;
    vec1.setValues(2.1, 4, 1.3);
    EXPECT_EQ(vec1.x_value, 2.1);
    EXPECT_EQ(vec1.y_value, 4);
    EXPECT_EQ(vec1.z_value, 1.3);
}


TEST(twoFullVectors, addThem_returnsSum)
{
   dynVector vec1;
   vec1.setValues(1.4, 1.3, 1.2);
   dynVector vec2;
   vec2.setValues(1.0, 1.1, 2.24);
   dynVector vec3 = vec1 + vec2;
   EXPECT_DOUBLE_EQ(vec3.x_value, 2.4);
   EXPECT_DOUBLE_EQ(vec3.y_value, 2.4);
   EXPECT_DOUBLE_EQ(vec3.z_value, 3.44);
}

TEST(oneVector, multiplyByScalar_returnsCorrectAnswer)
{
    dynVector vec1;
    vec1.setValues(1.7, 0.3, 2.14);
    double scalar{1.3};
    dynVector vec2 = vec1 * scalar;
    EXPECT_DOUBLE_EQ(vec2.x_value, 2.21);
    EXPECT_DOUBLE_EQ(vec2.y_value, 0.39);
    EXPECT_DOUBLE_EQ(vec2.z_value, 2.782);
}

//Unit Tests for Physics Engine


TEST(defaultPhysics, givenUpdateTime_returnsDisplacement)
{
    PhysicsEngine engine;
    engine.update(0.5);
    EXPECT_DOUBLE_EQ(engine.displaceVec.x_value, 0);
    EXPECT_DOUBLE_EQ(engine.displaceVec.y_value, 0);
    EXPECT_DOUBLE_EQ(engine.displaceVec.z_value, -2.45);
}

TEST(PhysicsWithDisplacement, givenUpdateTime_returnsCorrectDisplacement)
{
    PhysicsEngine engine;
    engine.setDisplace(1.2, 0.45, 0.6);
    engine.update(0.4);
    EXPECT_DOUBLE_EQ(engine.displaceVec.x_value, 1.2);
    EXPECT_DOUBLE_EQ(engine.displaceVec.y_value, 0.45);
    EXPECT_DOUBLE_EQ(engine.displaceVec.z_value, -0.968);
}
