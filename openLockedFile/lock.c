#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

const int SLEEP_SEC = 10;

typedef struct {
  int l_type, l_whence, l_start, l_len;
} flock;

int main(void) {

  // Open the file
  int fd = open("bwah", O_RDWR);

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
  printf("Got lock! Going to sleep for %i seconds.\n", SLEEP_SEC);
  sleep(SLEEP_SEC);

  // Close the file
  close(fd);

  return EXIT_SUCCESS;
}
