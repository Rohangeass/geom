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
int dist(Point a,Point b)
{
return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) * 1.0); 
}
int ExtraLengthy(Point p,Point p1,Point p2)
{
    int angle=atan((p.y-p2.y)/(p.x-p2.x));
    return (p1.x-p2.x)*tan(angle);
}
//assuming array sorted by x coord of points
int sunlight(const vector<Point>& arr,Point p)
{
    int n=arr.size();
    int lengthexposed=0;
    for(int i=0;i<n-3;++i)
    {
        //sun extreem left
        if(arr[i].x>p.x&&p.y>arr[i].y)
        {
            if(arr[i].y>arr[i+1].y)
            {
                lengthexposed+=dist(a[i],a[i+1])+dist(a[i+1],a[i+2]);
                if(i>3)
                {
                    lengthexposed+=ExtraLengthy(p,a[i],a[i-2]);
                }
                i+=4;
            }
            else
            {
                lengthexposed+=dist(a[i],a[i+1])+dist(a[i],a[i+2]);
                if(i>3)
                {
                    lengthexposed+=ExtraLengthy(p,a[i-1],a[i-3]);
                }
                i+=4;
            }
            
        }
    }
}