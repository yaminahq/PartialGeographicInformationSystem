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

bool pointsEqual1(PointT a, PointT b){
  return (a.x() == b.x() and a.y() == b.y());
}

bool lineEqual1(LineT a, LineT b){
  return ( pointsEqual1(a.strt(),b.strt()) and a.orient() == b.orient() and a.len() == b.len());
}

TEST_CASE( "tests for LineT" , "[LineT]" ) {
  
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


  SECTION( "constructor for l1" ){
    REQUIRE( pointsEqual1(l1.strt(), p1)) ;
    REQUIRE( l1.orient() == S) ;
    REQUIRE( l1.len() == 2) ;
  }

  SECTION( "strt" ){
    REQUIRE( pointsEqual1(l2.strt(),p2)) ;
  }

  SECTION( "end" ){
    REQUIRE( pointsEqual1(l3.end(),PointT(3, -4))) ;
  }

  SECTION( "orient" ){
    REQUIRE(l5.orient() == N) ;
  }

  SECTION( "len" ){
    REQUIRE(l6.len() == 4) ;
  }

  SECTION( "flip" ){
    l1 = l1.flip();
    REQUIRE(lineEqual1(l1, LineT(p1,N,2))) ;
  }

  SECTION( "rotate" ){
    l2 = l2.rotate(CW);
    REQUIRE(lineEqual1(l2, LineT(p2,S,3))) ;
  }
}