/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Runtime: 8ms
Memory: 62MB
Top 85.95% of C submissions
*/

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    
    int xo = coordinates[0][0], yo = coordinates[0][1];
    float slope = (coordinates[1][0] - xo) / (float)(coordinates[1][1] - yo); 
    
    if (coordinatesSize == 2) return true;
    for (int i = 1; i < coordinatesSize; i++)
    {
        int x = coordinates[i][0], y = coordinates[i][1];
        if (y - yo != 0)
        {
            float slope_check = (x - xo) / (float)(y - yo);
            if (slope_check != slope) return false;
        }
        else
            if (y != yo) return false;
    }
    return true;
}
