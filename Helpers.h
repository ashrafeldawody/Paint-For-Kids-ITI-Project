#include "DEFS.h"
class Helpers
{
public:
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
        if (c == LIGHTGOLDENRODYELLOW)    return "LIGHTGOLDENRODYELLOW"; //main background
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
        if (c == "LIGHTGOLDENRODYELLOW")    return LIGHTGOLDENRODYELLOW; //main background
        if (c == "UNFILLED")    return NULL;
        return LIGHTGOLDENRODYELLOW;
    }
    static bool checkPointInsideDrawArea(int x, int y) {
        if (y < UI.ToolBarHeight || y > UI.height - UI.StatusBarHeight || x > UI.width || x < 0) {
            return false;
        }
        return true;
    }
};