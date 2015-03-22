/* vim: set filetype=cpp: */

#include "Segment.h"

template <typename T>
Segment<T>::Segment(Point<T> const& p1, Point<T> const& p2){
    endpoints.push_back(p1);
    endpoints.push_back(p2);
}

template <typename T>
Point<T> Segment<T>::p1(void) const{
    return endpoints[0];
}

template <typename T>
Point<T> Segment<T>::p2(void) const{
    return endpoints[1];
}

template <typename T>
bool operator==(Segment<T> s1, Segment<T> s2){
    return ( (s1.p1() == s2.p1() && s1.p2() == s2.p2()) ||
             (s1.p1() == s2.p2() && s1.p2() == s2.p1()) );
}

