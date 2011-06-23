#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
  int l_type, l_whence, l_start, l_len;
} flock;

int main(int argc, char **argv) {

  int sleepTime;
  char *fileName;

  int fd;

  // Some quick arg handling
  if(argc != 3) {
    perror("Unexpected number of args: `./lock <file name> <sleep seconds>`.");
    return EXIT_FAILURE;
  }

  fileName = argv[1];
  sleepTime = atoi(argv[2]);

  // Open the file
  fd = open(fileName, O_RDWR);

  if(fd < 0) {
    perror("Couldn't open the file");
    return EXIT_FAILURE;
  }

  // Lock the file
  flock fileLocker = { F_WRLCK, SEEK_SET, 0, 0 };

  if(fcntl(fd, F_SETLK, &fileLocker) < 0) {
    perror("Unable to lock the file");
    return EXIT_FAILURE;
  }

  // Sleep for X seconds (long enough for node to finish)
  printf("Got lock! Going to sleep for %i seconds.\n", sleepTime);
  sleep(sleepTime);

  // Close the file
  close(fd);

  return EXIT_SUCCESS;
}
