//Yaminah Qureshi
//qureshiy

#include "catch.h"

#include "Seq2D.h"
#include "PointADT.h"
#include "LineADT.h"
#include "PathADT.h"
#include "Exceptions.h"
#include "DEM.h"
#include "LanduseMap.h"
#include "MapTypes.h"
#include <vector>

#include <iostream>


TEST_CASE( "tests for PointT" , "[PointT]" ) {
  
  /*
   *  At the start of your test case, you can set up variables
   *  that you will use in your tests.  These variables are reconstructed
   *  before every test, so if you modify some of them in a test
   *  they will be reset at the start of the next test.
   */

    PointT p1(0, 0); 
    PointT p2(1, 0); 
    PointT p3(2, 0); 
    PointT p4(0, 1); 
    PointT p5(1, 1); 
    PointT p6(2, 1); 
    PointT p7(0, 2); 
    PointT p8(1, 2); 
    PointT p9(2, 2); 


  SECTION( "constructor for p1" ){
    REQUIRE( p1.x() == 0) ;
    REQUIRE( p1.y() == 0) ;
  }

  SECTION( "x()" ){
    REQUIRE( p2.x() == 1) ;
    REQUIRE( p3.x() == 2) ;
    REQUIRE( p4.x() == 0) ;
  }

  SECTION( "y()" ){
    REQUIRE( p2.y() == 0) ;
    REQUIRE( p3.y() == 0) ;
    REQUIRE( p4.y() == 1) ;
  }

  SECTION( "translate point" ){
    p1 = p1.translate(2,3);
    REQUIRE(p1.x() == 2) ;
    REQUIRE(p1.y() == 3) ;
  }

}