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

#define ADMISS_ERR 1e-20

// remember to define and use some sort of
// approximately equals function if you are
// testing floating point equality.
bool approx(double a, double b) {
  return std::abs(a - b) < ADMISS_ERR;
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
TEST_CASE( "tests for Seq2DT" , "[Seq2DT]" ) {
  
  /*
   *  At the start of your test case, you can set up variables
   *  that you will use in your tests.  These variables are reconstructed
   *  before every test, so if you modify some of them in a test
   *  they will be reset at the start of the next test.
   */

    std::vector<std::vector<int>> seq1 = { 
      {1, 2, 3} 
    , {4, 5, 3}
    , {3, 7, 3} 
    };


    std::vector<std::vector<LanduseT>> seq2 = { 
      {Transport, Transport, Transport} 
    , {Commercial, Commercial, Commercial}
    , {Recreational, Residential, Transport} 
    };

    DEMT d(seq1, 1.0);
    LanduseMapT m(seq2, 1.0);

    PointT p1(0, 0); 
    PointT p2(1, 0); 
    PointT p3(2, 0); 
    PointT p4(0, 1); 
    PointT p5(1, 1); 
    PointT p6(2, 1); 
    PointT p7(0, 2); 
    PointT p8(1, 2); 
    PointT p9(2, 2); 

    PathT pth1(p7, E, 2); 
    PathT pth2(p1, W, 2); 



  SECTION( "constructor for d" ){
    REQUIRE( d.getScale() == 1.0) ;
    REQUIRE( d.getNumCol() == 3) ;
    REQUIRE( d.getNumRow() == 3) ;
  }
  SECTION( "constructor for m" ){
    REQUIRE( m.getScale() == 1.0) ;
    REQUIRE( m.getNumCol() == 3) ;
    REQUIRE( m.getNumRow() == 3) ;
  }

  SECTION( "scale less than 0" ){
    REQUIRE_THROWS_AS( DEMT(seq1, -1.0), invalid_argument );
  }

  SECTION( "length of first element of sequence is 0" ){
     std::vector<std::vector<LanduseT>> seq3 = {{}};
    REQUIRE_THROWS_AS( LanduseMapT(seq3, 1.0), invalid_argument );
  }

  SECTION( "length of elements in sequence is unequal" ){
     std::vector<std::vector<int>> seq3 = {{1},{1,2}};
    REQUIRE_THROWS_AS( DEMT(seq3, 1.0), invalid_argument );
  }

  SECTION( "set" ){
    d.set(p1, 5);
    REQUIRE(d.get(p1) == 5);
    m.set(p3, Residential);
    REQUIRE(m.get(p3) == Residential);
  }

  SECTION( "point lies outside of the map" ){
    REQUIRE_THROWS_AS( d.set(PointT(5,5), 6), outside_bounds );
  }
  

  SECTION( "get" ){
    REQUIRE(d.get(p1) == 1);
    REQUIRE(m.get(p1) == Transport);
  }

  SECTION( "point lies outside of the map" ){
    REQUIRE_THROWS_AS( m.get(PointT(5,5)), outside_bounds );
  }
  
  SECTION( "getNumRow" ){
    REQUIRE( d.getNumRow() == 3) ;
    REQUIRE( m.getNumRow() == 3) ;
  }

  SECTION( "getNumCol" ){
    REQUIRE( d.getNumCol() == 3) ;
    REQUIRE( m.getNumCol() == 3) ;
  }
  
  SECTION( "getScale" ){
    REQUIRE( d.getScale() == 1.0) ;
    REQUIRE( m.getScale() == 1.0) ;
  }


  SECTION( "count 1" ){
    REQUIRE( d.count(1) == 1) ;
    REQUIRE( m.count(Transport) == 4) ;
  }

  SECTION( "count 2" ){
    REQUIRE( d.count(LineT(p3, N, 2), 3) == 2) ;
    REQUIRE( m.count(LineT(p1, E, 3), Transport) == 3) ;
  }

  SECTION( "line lies outside of the map" ){
    REQUIRE_THROWS_AS( d.count(LineT(p3, S, 5), 3), invalid_argument );
  }

  SECTION( "count 3" ){
    REQUIRE( d.count(pth1, 3) == 1) ;
    REQUIRE( m.count(pth2, Transport) == 1) ;
  }

  SECTION( "path lies outside of the map" ){
    pth2.append(W, 4);
    REQUIRE_THROWS_AS( m.count(pth2, Transport), invalid_argument );
  }

  SECTION( "length" ){

    REQUIRE( d.length(pth1) == 2.0);
    REQUIRE( m.length(pth2) == 2.0);
  }

  SECTION( "path lies outside of the map" ){
    pth2.append(W, 4);
    REQUIRE_THROWS_AS( m.length(pth2), invalid_argument );
  }

  SECTION( "connected" ){
    REQUIRE( d.connected(p3,p9) == true);
    REQUIRE( d.connected(p1,p3) == false);
    REQUIRE( m.connected(p1,p3) == true);
    REQUIRE( m.connected(p2,p8) == false);
  }
  SECTION( "point lies outside of the map" ){
    REQUIRE_THROWS_AS( d.connected(PointT(5,5), PointT(0,0)), invalid_argument );
  }

  SECTION( "point lies outside of the map" ){
    REQUIRE_THROWS_AS( d.connected(PointT(0,0), PointT(3,4)), invalid_argument );
  }

}
