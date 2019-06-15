#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *pDirent;
  struct stat buf;

  DIR *pDir;

  // Open directory
  if (argc < 2)
  {
    pDir = opendir("./");
  } else {
    pDir = opendir(argv[1]);
  }
  
  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }
  
  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL)
  {
    stat(pDirent->d_name, &buf);
    printf("%s %10lld bytes\n", pDirent->d_name, buf.st_size);
  }

  // Close directory
  closedir(pDir);
  return 0;
}