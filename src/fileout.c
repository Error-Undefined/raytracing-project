#include <stdio.h>

#include "fileout.h"
#include "vector3.h"

int write_file(const char* path, color* color_data, int height, int width)
{
  FILE* fp;
  fp = fopen(path, "w+");

  if (fp == NULL)
  {
    return 1;
  }
  //Write .ppm file header
  fputs("P3\n", fp);
  fprintf(fp, "%d %d\n255\n", width, height);

  for(int h = 0;  h < height; h++)
  {
    for (int w = 0; w < width; w++)
    {
      int r = (int) color_data[256*h + w].x;
      int g = (int) color_data[256*h + w].y;
      int b = (int) color_data[256*h + w].z;
      fprintf(fp, "%d %d %d\n", r, g, b);
    }
  }

  fclose(fp);
  return 0;
}
