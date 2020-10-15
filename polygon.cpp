
//Write a function that takes two arguments as a input and return True if 'p' lies inside the polygon else False.
#include <bits/stdc++.h> 
using namespace std; 
  
#define  inf INT_MAX
  
class Point 
{ public:
    int x; 
    int y;
    Point(int X,int Y):x(X),y(Y)
    {;} 
}; 
bool LiesOnSegment(Point a, Point b, Point c) 
{ 
    return (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
} 
int orientation(Point a, Point b, Point c) 
{ 
    int value = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y); 
  
    if (value)
    {
        if (value>0)
        {
            return 1;
        }
        return 2;
    }
    return 0;
} 
bool Intersect(Point a1, Point a2, Point a3, Point a4) 
{ 
    int o1 = orientation(a1, a2, a3); 
    int o2 = orientation(a1, a2, a4); 
    int o3 = orientation(a3, a4, a1); 
    int o4 = orientation(a3, a4, a2); 
    if (o1 != o2 && o3 != o4) 
        return true;  
    if ((o1 == 0 && LiesOnSegment(a1, a3, a2))||(o2 == 0 && LiesOnSegment(a1, a4, a2))||(o4 == 0 && LiesOnSegment(a3, a2, a4))) 
        return true; 
    return false;
} 
//draw line seg from point to infinity, even cuts outside or on, odd cuts inside  
bool Location(const vector<Point>& arr,Point p) 
{ 
    int n=arr.size();
    if (n < 3) 
         return false; 
    Point infLine(inf, p.y); 
    int count = 0, i = 0; 
    do
    { 
        int next = (i+1)%n; 
        if (Intersect(arr[i], arr[next], p, infLine)) 
        {  
            if (orientation(arr[i], p, arr[next]) == 0) 
               return LiesOnSegment(arr[i], p, arr[next]); 
            count++; 
        } 
        i = next; 
    } while (i != 0); 
  
    
    return (count%2 == 1);
}
