/*
  An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

  Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

  To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

  At the end, return the modified image.
  
  Runtime: 20ms
  Memory: 7.5MB
  Top 85.45% of C submissions
*/

void color(int** image, int sr, int sc, int newColor, int imageSize, int* imageColSize, int ogColor);

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    
    color(image, sr, sc, newColor, imageSize, imageColSize, image[sr][sc]);
    
    *returnSize = imageSize;
    *returnColumnSizes = (int*) malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; ++i) {
        (*returnColumnSizes)[i] = (*imageColSize);
    }
    return image;
    
}

void color(int** image, int sr, int sc, int newColor, int imageSize, int* imageColSize, int ogColor)
{
    if (image[sr][sc] == newColor) return;
    if (image[sr][sc] != ogColor) return;
    image[sr][sc] = newColor;
    if (sr - 1 >= 0) 
    {
        if (image[sr - 1][sc] == ogColor) color(image, sr - 1, sc, newColor, imageSize, imageColSize, ogColor);
    }
    if (sr + 1 < imageSize)
    {
        if (image[sr + 1][sc] == ogColor) color(image, sr + 1, sc, newColor, imageSize, imageColSize, ogColor);
    }
    if (sc - 1 >= 0)
    {
        if (image[sr][sc - 1] == ogColor) color(image, sr, sc - 1, newColor, imageSize, imageColSize, ogColor);
    }
    if (sc + 1 < *imageColSize) 
    {
        if (image[sr][sc + 1] == ogColor) color(image, sr, sc + 1, newColor, imageSize, imageColSize, ogColor);
    }
    return;
    
}
