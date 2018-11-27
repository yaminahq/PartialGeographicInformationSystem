//Yaminah Qureshi
//qureshiy
/**
 *  \file PathADT.h
 *  \brief generates a abstract data type to represent a path
 */

#ifndef PATHADT_H
#define PATHADT_H

#include <vector>
#include <set>
#include "LineADT.h"
#include "Exceptions.h"

/**
 *  \brief Class representing a path on a 2D plane
 *  \details comprised by a sequence of lines
 */

class PathT
{
  private:
    // the path or sequence of lines
    std::vector<LineT> s;
/**
 *  \brief Returns the point adjacent to end of the path
 *  \param ornt desired orientation of the adjacent point with respect to end of path
 *  \return The adjacent point
 */
    PointT adjPt(CompassT ornt);
/**
 *  \brief Returns a set of the points in a line
 *  \param l the line
 *  \return a set of points in the line
 */

    std::vector<PointT> pointsInLine(LineT l);
/**
 *  \brief Returns whether a point is in a set of points
 *  \param p the point you are looking for
 *  \return True if p is contained in the set of points
 */
    bool contains(std::vector<PointT> points, PointT p);

  public:

/**
 *  \brief Constructs a new path
 *  \param st The first point of the path
 *  \param ornt The orientation of the first line in the path
 *  \param l The length of the first line in the path
 *  \return The created path
 */
    PathT(PointT st, CompassT ornt, int l);
/**
 *  \brief adds a line to a path
 *  \param ornt The orientation of the new line in the path
 *  \param l The length of the new line in the path
 */
    void append(CompassT ornt, int l);
/**
 *  \brief return the first point in a path
 *  \return The first point of the path
 */
    PointT strt();
/**
 *  \brief returns the last point of the path
 *  \return The last point of the path
 */
    PointT end();
/**
 *  \brief returns the ith line of the path
 *  \param i The index of the line to be retrieved
 *  \return The ith line
 */
    LineT line(int i);
/**
 *  \brief Returns the number of lines in a path
 *  \return The number of lines in the path
 */
    int size();
/**
 *  \brief returns the number of points in a path
 *  \return The number of points in the path
 */
    int len();
/**
 *  \brief Translates a path
 *  \param deltaX the shift in x-values
 *  \param deltaX the shift in y-values
 *  \returns the shifted path
 */
    PathT translate(int deltaX, int deltaY);

};

#endif