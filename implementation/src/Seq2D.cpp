//Yaminah Qureshi
//qureshiy

#include "Seq2D.h"
#include "PathADT.h"
#include "Exceptions.h"
#include <vector>
#include <iostream>


template <class T>
Seq2DT<T>::Seq2DT(std::vector<std::vector<T>> S, float scl) : s(S), scale(scl), nCol(S[0].size()), nRow(S.size())
{
    if (this->scale <= 0 or this->s.size() == 0 or this->s[0].size() == 0 )
        throw invalid_argument();
    for (int i = 0; i < this->s.size(); i++){
        if (s[i].size() != s[0].size())
            throw invalid_argument();
    }
}

template <class T>
void Seq2DT<T>::set(PointT p, T v) 
 {
    if (not validPoint(p))
        throw outside_bounds();
    this->s[p.y()][p.x()] = v;
 }

template <class T>
T Seq2DT<T>::get(PointT p)
{
    if (not validPoint(p))
        throw outside_bounds();
    return this->s[p.y()][p.x()];
}

template <class T>
int Seq2DT<T>::getNumRow()
{
    return this->nRow;
}

template <class T>
int Seq2DT<T>::getNumCol()
{
    return this->nCol;
}

template <class T>
float Seq2DT<T>::getScale()
{
    return this->scale;
}

template <class T>
int Seq2DT<T>::count(T t)
{
    int sum = 0;
    for(int i = 0; i < this->nRow; i = i + 1) {
        for(int j = 0; j < this->nCol; j = j + 1) {
            if(this->s[i][j] == t)
                sum = sum + 1;
        }
    }
    return sum;
}

template <class T>
int Seq2DT<T>::count(LineT l, T t)
{
    if (not validLine(l))
        throw invalid_argument();
    int sum = 0;
    std::vector<PointT> myset = pointsInLine(l);
    for (std::vector<PointT>::iterator it=myset.begin(); it!=myset.end(); ++it)
        if(this->get(*it) == t) {
            sum = sum + 1;
        }

    return sum;
}

template <class T>
int Seq2DT<T>::count(PathT pth, T t)
{
    if (not validPath(pth))
        throw invalid_argument();
    int sum = 0;
    std::vector<PointT> myset = pointsInPath(pth);
    for (std::vector<PointT>::iterator it=myset.begin(); it!=myset.end(); ++it)
        if(this->get(*it) == t) {
            sum = sum + 1;
        }

    return sum;
}

template <class T>
float Seq2DT<T>::length(PathT pth)
{
    if (not validPath(pth))
        throw invalid_argument();
    return (pth.len() * this->scale);
}

template <class T>
bool Seq2DT<T>::connected(PointT p1, PointT p2)

{
/*    if (not validPoint(p1) or not validPoint(p2))
        throw invalid_argument();

    for (PointT p = p1; validPoint(p) and (this->get(p) == this->get(p1)); p = p.translate(0, 1)){
        if(p.x() == p2.x() and p.y() == p2.y())
            return true;
    }
    for (PointT p = p1; validPoint(p) and (this->get(p) == this->get(p1)); p = p.translate(0, -1)){
        if(p.x() == p2.x() and p.y() == p2.y())
            return true;
    }
    for (PointT p = p1; validPoint(p) and (this->get(p) == this->get(p1)); p = p.translate(-1, 0)){
        if(p.x() == p2.x() and p.y() == p2.y())
            return true;
    }
        for (PointT p = p1; validPoint(p) and (this->get(p) == this->get(p1)); p = p.translate(1, 0)){
        if(p.x() == p2.x() and p.y() == p2.y())
            return true;
    }

    return false;*/
    std::cout << p1.x() << std::endl;
    std::cout << p1.y() << std::endl;
    if (this->get(p1) != this->get(p2)) {
        std::cout << "f1" << std::endl;
        return false;
    }
    if (p1.x() == p2.x() and p1.y() == p2.y()) {
        std::cout << "t1" << std::endl;
        return true;
    }
    // if (validPoint(p1.translate(0,1))) {
    //     std::cout << "m" << std::endl;
    //     if (connected(p1.translate(0,1), p2))
    //         return true;
    // }
    // if (validPoint(p1.translate(0,-1))) {
    //     if (connected(p1.translate(0,-1), p2))
    //         return true;
    // }
    if ( validPoint(p1.translate(1,0)) and not (p1.translate(1,0).x() == p1.x() and p1.translate(1,0).y() == p1.y()) ) {
        if (connected(p1.translate(1,0), p2))
            return true;
     }
    if ( validPoint(p1.translate(-1,0)) and not (p1.translate(-1,0).x() == p1.x() and p1.translate(-1,0).y() == p1.y()) ) {
        if (connected(p1.translate(-1,0), p2))
            return true;
    }
    std::cout << "f2" << std::endl;
    return false;
}

template <class T>
bool Seq2DT<T>::validRow(int i)
{
    return (i >= 0 and i <= this->nRow - 1);
}

template <class T>
bool Seq2DT<T>::validCol(int j) 
{
    return (j >= 0 and j <= this->nCol - 1);
}

template <class T>
bool Seq2DT<T>::validPoint(PointT p)
{
    return (validRow(p.y()) and validCol(p.x()));
}

template <class T>
bool Seq2DT<T>::validLine(LineT l)
{
    std::vector<PointT> myset = pointsInLine(l);
    for (std::vector<PointT>::iterator it=myset.begin(); it!=myset.end(); ++it) {
        if(not validPoint(*it)) {
            return false;
        }
    }
    return true;
}

template <class T>
bool Seq2DT<T>::validPath(PathT pth)
{
    std::vector<PointT> myset = pointsInPath(pth);
    for (std::vector<PointT>::iterator it=myset.begin(); it!=myset.end(); ++it)
        if(not validPoint(*it)) {
            return false;
        }
    return true;
}

template <class T>
std::vector<PointT> Seq2DT<T>::pointsInLine(LineT l)
{
    std::vector<PointT> setOfPoints;

    for(int i = 0; i < l.len(); i = i + 1) {
        if(l.orient() == W and not contains(setOfPoints, l.strt().translate(-i, 0))) {
            setOfPoints.push_back(l.strt().translate(-i, 0));
        }
        else if(l.orient() == E and not contains(setOfPoints, l.strt().translate(i, 0))) {
            setOfPoints.push_back(l.strt().translate(i, 0));
        }
        else if(l.orient() == N and not contains(setOfPoints, l.strt().translate(0, i))) {
            setOfPoints.push_back(l.strt().translate(0, i));            
        }
        else if (l.orient() == S and not contains(setOfPoints, l.strt().translate(0, -i))){
            setOfPoints.push_back(l.strt().translate(0, -i));
        }
    }

    return setOfPoints;
}

template <class T>
bool Seq2DT<T>::contains(std::vector<PointT> points, PointT p)
{
    for(std::vector<PointT>::iterator it = points.begin(); it != points.end(); ++it) {
    if(p.x() == (*it).x() and p.y() == (*it).y())
      return true;
    }
  return false;
}

template <class T>
std::vector<PointT> Seq2DT<T>::pointsInPath(PathT pth)
{
  std::vector<PointT> myset;
  for(int i = 0; i < pth.size(); i = i + 1) {
    std::vector<PointT> points = pointsInLine(pth.line(i));
    for(int j = 0; j < points.size(); j++){
        if (not contains(myset, points[i]))
            myset.push_back(points[i]);
    }
}
  return myset;
}

template class Seq2DT<LanduseT>;
template class Seq2DT<int>;
