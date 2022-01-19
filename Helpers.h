#include "DEFS.h"
class Helpers
{
public:
    static bool onSegment(Point p, Point q, Point r)
    {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
            return true;
        return false;
    }
    static int orientation(Point p, Point q, Point r)
    {
        int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);

        if (val == 0) return 0; // collinear 
        return (val > 0) ? 1 : 2; // clock or counterclock wise 
    }
    static bool doIntersect(Point p1, Point q1, Point p2, Point q2)
    {
        // Find the four orientations needed for general and 
        // special cases 
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        // General case 
        if (o1 != o2 && o3 != o4)
            return true;

        // Special Cases 
        // p1, q1 and p2 are collinear and p2 lies on segment p1q1 
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;

        // p1, q1 and p2 are collinear and q2 lies on segment p1q1 
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;

        // p2, q2 and p1 are collinear and p1 lies on segment p2q2 
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;

        // p2, q2 and q1 are collinear and q1 lies on segment p2q2 
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;

        return false; // Doesn't fall in any of the above cases 
    }
    static Point getMidPoint(Point p1, Point p2) {
        Point p;
        p.x = (p2.x + p1.x) / 2;
        p.y = (p2.y + p1.y) / 2;
        return p;
    }
    static string getColorName(color c) {
        if (c == NULL)      return "UNFILLED";
        if (c == BLACK)     return "Black";
        if (c == RED)       return "RED";
        if (c == YELLOW)    return "YELLOW";
        if (c == GREEN)     return "GREEN";
        if (c == NAVY)      return "NAVY";
        if (c == DEEPPINK)  return "DEEPPINK";
        if (c == GRAY)      return "GRAY";
        if (c == ORANGE)    return "ORANGE";
        return "Unknown Color";
    }
    static color getColorFromString(string c) {
        if (c == "Black")     return BLACK;
        if (c == "RED")       return RED;
        if (c == "YELLOW")    return YELLOW;
        if (c == "NAVY")      return NAVY;
        if (c == "DEEPPINK")  return DEEPPINK;
        if (c == "GRAY")      return GRAY;
        if (c == "ORANGE")    return ORANGE;
        if (c == "UNFILLED")    return NULL;
        return GREEN;
    }
};