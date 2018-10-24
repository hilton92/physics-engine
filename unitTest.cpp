// Author: Benjamin Hilton

#include <gtest/gtest.h>
#include "physicsEngine.h"
#include "dynVector.h"
#include "object3d.h"

//Unit Tests for Vector class

TEST(oneVector, populate_returnsCorrectValues)
{
    dynVector vec1;
    vec1.set_values(2.1, 4, 1.3);
    EXPECT_EQ(vec1.xValue, 2.1);
    EXPECT_EQ(vec1.yValue, 4);
    EXPECT_EQ(vec1.zValue, 1.3);
}


TEST(twoFullVectors, addThem_returnsSum)
{
   dynVector vec1;
   vec1.set_values(1.4, 1.3, 1.2);
   dynVector vec2;
   vec2.set_values(1.0, 1.1, 2.24);
   dynVector vec3 = vec1 + vec2;
   EXPECT_DOUBLE_EQ(vec3.xValue, 2.4);
   EXPECT_DOUBLE_EQ(vec3.yValue, 2.4);
   EXPECT_DOUBLE_EQ(vec3.zValue, 3.44);
}

TEST(oneVector, multiplyByScalar_returnsCorrectAnswer)
{
    dynVector vec1;
    vec1.set_values(1.7, 0.3, 2.14);
    double scalar{1.3};
    dynVector vec2 = vec1 * scalar;
    EXPECT_DOUBLE_EQ(vec2.xValue, 2.21);
    EXPECT_DOUBLE_EQ(vec2.yValue, 0.39);
    EXPECT_DOUBLE_EQ(vec2.zValue, 2.782);
}

//Unit Tests for Physics Engine

TEST(defaultPhysics, givenUpdateTime_returnsDisplacement)
{
    Object3D object;
    object.set_gravity(0, 0, -9.8);
    object.update(0.5);
    EXPECT_DOUBLE_EQ(object.displaceVec.xValue, 0);
    EXPECT_DOUBLE_EQ(object.displaceVec.yValue, 0);
    EXPECT_DOUBLE_EQ(object.displaceVec.zValue, -2.45);
}

TEST(physicsWithDisplacement, givenUpdateTime_returnsCorrectDisplacement)
{
    Object3D object;
    object.set_gravity(0, 0, -9.8);
    object.set_displace(1.2, 0.45, 0.6);
    object.update(0.4);
    EXPECT_DOUBLE_EQ(object.displaceVec.xValue, 1.2);
    EXPECT_DOUBLE_EQ(object.displaceVec.yValue, 0.45);
    EXPECT_DOUBLE_EQ(object.displaceVec.zValue, -0.968);
}

TEST(emptyEnvironment, addObject_returnsCorrectDisplacement)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.2, 0.45, 0.6, 0, 0, 0);
    engine.update(0.4);
    EXPECT_DOUBLE_EQ(engine.ObjList[0].displaceVec.xValue, 1.2);
    EXPECT_DOUBLE_EQ(engine.ObjList[0].displaceVec.yValue, 0.45);
    EXPECT_DOUBLE_EQ(engine.ObjList[0].displaceVec.zValue, -0.968);
}

TEST(initialObject, setVelocity_returnsCorrectDrag)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.2, 0.45, 0.6, 1.6, 2.4, 1.1);
    engine.update(0.4);
    EXPECT_NEAR(engine.ObjList[0].dragForce.xValue, -2.5635, 0.001);
    EXPECT_NEAR(engine.ObjList[0].dragForce.yValue, -5.7679, 0.001);
    EXPECT_NEAR(engine.ObjList[0].dragForce.zValue, -1.2116, 0.001);
}

TEST(initialObject, setVelocityOneStep_returnsCorrectDisplacement)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.2, 0.45, 0.6, 1.6, 2.4, 1.1);
    engine.update(0.4);
    EXPECT_NEAR(engine.ObjList[0].displaceVec.xValue, 1.4298, 0.001);
    EXPECT_NEAR(engine.ObjList[0].displaceVec.yValue, 0.48712, 0.001);
    EXPECT_NEAR(engine.ObjList[0].displaceVec.zValue, -0.7218, 0.001);
}

TEST(initialObject, setVelocityOneStep_returnsCorrectDrag)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.2, 0.45, 0.6, 1.6, 2.4, 1.1);
    engine.update(0.4);
    engine.update(0.4);
    EXPECT_NEAR(engine.ObjList[0].dragForce.xValue, -0.3306, 0.001);
    EXPECT_NEAR(engine.ObjList[0].dragForce.yValue, -0.0086, 0.001);
    EXPECT_NEAR(engine.ObjList[0].dragForce.zValue, 10.935, 0.001);
}

TEST(twoVectors, calculateDotProduct_returnsDotProduct)
{
    dynVector Vec1;
    dynVector Vec2;
    Vec1.set_values(2.4, 3.0, 2.0);
    Vec2.set_values(1.0, 2.0, 3.1);
    double dotProduct = Vec1 || Vec2;
    EXPECT_DOUBLE_EQ(dotProduct, 14.6);
}

TEST(engineWithObjects, clearEngine_returnsSizeZero)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.2, 2.4, 4.1, -1.1, 2.1, -0.4);
    engine.add_sphere(1, 1, 2.1, 1.2, 2.4, 4.1, -1.1, 2.1, -0.4);
    engine.add_sphere(1, 1, 1.5, 1.2, 2.4, 4.1, -1.1, 2.1, -0.4);
    engine.clear();
    EXPECT_EQ(engine.ObjList.size(), 0);
    engine.add_sphere(1, 1, 2.1, 1.2, 2.4, 4.1, -1.1, 2.1, -0.4);
    engine.add_sphere(1, 1, 1.5, 1.2, 2.4, 4.1, -1.1, 2.1, -0.4);
    EXPECT_EQ(engine.ObjList.size(), 2);
}

TEST(objectWithVelocity, requestUnitVector_returnsCorrectUnitVector)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.2, 2.4, 4.1, -1.1, 2.1, -0.4);
    dynVector unitVec = engine.ObjList[0].get_velocity_unit_vector();
    dynVector trueVal{-0.457, 0.8735, -0.1664};
    EXPECT_NEAR(unitVec.xValue, trueVal.xValue, 0.001);
    EXPECT_NEAR(unitVec.yValue, trueVal.yValue, 0.001);
    EXPECT_NEAR(unitVec.zValue, trueVal.zValue, 0.001);
}

TEST(sphereWithVelocity, collisionWithWallOccurs_sphereBounces)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 3.5, 0, 0, 6.0, 0, 0);
    engine.ObjList[0].includeDrag = false;
    for (int i{0}; i < 10; i++)
    {
        engine.update(1.0 / 30);
    }
    EXPECT_NEAR(engine.ObjList[0].velocityVec.xValue, -4.8, 0.01);
}

TEST(collisionAlgorithm, suppliedValues_calculatesCollision)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 1, 1.0, 0, 0, -2.0, 0, 0);
    engine.add_sphere(1, 1, 1, -1.0, 0, 0, 2.0, 0, 0);
    engine.collision_occurred(0,1);
    EXPECT_NEAR(engine.ObjList[0].velocityVec.xValue, 2, 0.01);
    EXPECT_NEAR(engine.ObjList[1].velocityVec.xValue, -2, 0.01);
}

TEST(collisionAlgorithm3D, suppliedValues_calculatesCollision)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.0, 1.0, 1.0, -2.0, -2.0, -2.0);
    engine.add_sphere(1, 1, 0.8, -1.0, -1.0, -1.0, 2.0, 2.0, 2.0);
    engine.collision_occurred(0,1);
    EXPECT_NEAR(engine.ObjList[0].velocityVec.xValue, 2*0.8, 0.01);
    EXPECT_NEAR(engine.ObjList[1].velocityVec.xValue, -2*0.8, 0.01);
    EXPECT_NEAR(engine.ObjList[0].velocityVec.yValue, 2*0.8, 0.01);
    EXPECT_NEAR(engine.ObjList[1].velocityVec.yValue, -2*0.8, 0.01);
    EXPECT_NEAR(engine.ObjList[0].velocityVec.zValue, 2*0.8, 0.01);
    EXPECT_NEAR(engine.ObjList[1].velocityVec.zValue, -2*0.8, 0.01);
}


TEST(twoObjectsWithOppositeVelocity, collisionOccurrs_spheresBounce)
{
    PhysicsEngine engine;
    engine.add_sphere(1, 1, 0.8, 1.5, 0, 0, -2.0, 0, 0);
    engine.add_sphere(1, 1, 0.8, -1.5, 0, 0, 2.0, 0, 0);
    engine.ObjList[0].includeDrag = false;
    engine.ObjList[1].includeDrag = false;
    for (int i = 0; i < 16; i++)
    {
        engine.update(1.0 / 30);
    }
    EXPECT_NEAR(engine.ObjList[0].velocityVec.xValue, (2.0*0.8), 0.01);
    EXPECT_NEAR(engine.ObjList[1].velocityVec.xValue, (-2.0*0.8), 0.01);
}

