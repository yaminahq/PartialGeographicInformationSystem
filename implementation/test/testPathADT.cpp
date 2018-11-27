//Yaminah Qureshi
//qureshiy

#include "catch.h"

#include "PointADT.h"
#include "LineADT.h"
#include "PathADT.h"
#include "Exceptions.h"
#include "MapTypes.h"


bool pointsEqual(PointT a, PointT b){
  return (a.x() == b.x() and a.y() == b.y());
}

bool lineEqual(LineT a, LineT b){
  return ( pointsEqual(a.strt(),b.strt()) and a.orient() == b.orient() and a.len() == b.len());
}

/*  
 *  In catch2, you should use a single test case for each
 *  class you test:  catch2 allows you to break up a test 
 *  case into sections, so you can write your individual
 *  method tests as sections.  This makes it so that test cases
 *  are more like test suites.
 *
 *  Start test cases with
 *
 *    TEST_CASE( "name of test suite" , "[label]" )
 *
 *  You can just use "tests for <class name>" as the name of
 *  the test suite, and "[<class name>]" for the label.
 */ 
TEST_CASE( "tests for PathT" , "[PathT]" ) {
  
  /*
   *  At the start of your test case, you can set up variables
   *  that you will use in your tests.  These variables are reconstructed
   *  before every test, so if you modify some of them in a test
   *  they will be reset at the start of the next test.
   */
    PointT p1(0, 0); LineT l1(p1,S,2);
    PointT p2(1, -1); LineT l2(p2,E,3);
    PointT p3(3, -2); LineT l3(p3,S,3);
    PointT p4(4, -4); LineT l4(p4,E,3);
    PointT p5(6, -3); LineT l5(p5, N, 4);
    PointT p6(3, -5); LineT l6(p6, W, 4);

    PathT pth1(p1, S, 2);


  
  /*
   *  Start each test with 
   *   
   *    SECTION( "test name" )
   *
   *  where "test name" is a description of what you
   *  are testing for.
   */
  SECTION( "constructor for path 1" ){
    /*
     *  REQUIRE is the same as assert in pytest
     *
     *  If the argument of REQUIRE is true, the test continues.
     *  If the argument of REQUIRE is false, the test fails.
     *  The test succeeds when it reaches the end of the SECTION
     */

    REQUIRE( pointsEqual(pth1.line(0).strt(),p1));
    REQUIRE( pth1.line(0).orient() == S );
    REQUIRE( pth1.line(0).len() == 2);
  }
  
  SECTION( "append" ){
    pth1.append(E, 3);
    LineT checkL(p2, E, 3);
    REQUIRE(lineEqual(pth1.line(1), checkL));
  }
  
  SECTION( "strt" ){
    PointT startPoint(0,0);
    REQUIRE( pointsEqual(pth1.strt(), startPoint));
  }
  
  SECTION( "end" ){
    pth1.append(E, 3);
    pth1.append(S, 3);
    pth1.append(E, 3);
    pth1.append(N, 4);
    PointT endPoint(6,0);
    REQUIRE( pointsEqual(pth1.end(), endPoint) );
  }
  
  SECTION( "line" ){
    pth1.append(E, 3);
    pth1.append(S, 3);

    LineT checkL1(p2,E,3);
    LineT checkL2(p3,S,3);

    REQUIRE( lineEqual(pth1.line(1), checkL1));
    REQUIRE( lineEqual(pth1.line(2), checkL2));
  }
  
  SECTION( "size" ){
    pth1.append(E, 3);
    pth1.append(S, 3);

    REQUIRE( pth1.size() == 3);
  }
  
  SECTION( "len" ){
    pth1.append(E, 3);
    pth1.append(S, 3);
    pth1.append(E, 3);

    REQUIRE( pth1.len() == 11 );
  }

    SECTION( "translate" ){
    pth1.append(E, 3);
    PathT pth2 = pth1.translate(1,1);
    PointT translatedPoint(1,1);

    REQUIRE( pointsEqual(pth2.strt(), translatedPoint) );
  }

}

