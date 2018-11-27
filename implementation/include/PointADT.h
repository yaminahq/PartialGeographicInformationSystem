//Yaminah Qureshi
//qureshiy
/**
 *  \file PointADT.h
 *  \brief generates an ADT for representing Points
 */

#ifndef POINTADT_H
#define POINTADT_H

/**
 *  \brief Class representing a point in the 2D plane
 *  \details Coordinates are integer values
 */
class PointT 
{
  public:
/**
 *  \brief Constructs a Point object, representing a point in 2D space
 *  \param x the x-coordinate of the point
 *  \param y the y-coordinate of the point
 */
    PointT(int x, int y);
/**
 *  \brief Returns the x-coordinate of a point
 *  \return The x-coordinate of a point
 */
    int x();
/**
 *  \brief Returns the y-coordinate of a point
 *  \return The y-coordinate of a point
 */
    int y();
/**
 *  \brief shifts a point in 2D space
 *  \param deltaX the shift in the x-direction
 *  \param deltaY the shift in the y-direction
 *  \return The shifted point
 */
    PointT translate(int deltaX, int deltaY);
    
  private: 
  	// the x-coordinate
    int xc;
    // the y-coordinate
    int yc;
};

#endif