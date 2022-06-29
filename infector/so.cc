#include "common/string.hh"
#include "std/sys.hh"
// Move _start() to the beginning of the text.
int main() __attribute__((section(".text.A")));
void func() {
  vt::common::String txt;
  txt += 'i';
  txt += 'n';
  txt += 'f';
  txt += 'e';
  txt += 'c';
  txt += 't';
  txt += 'e';
  txt += 'd';
  txt += '!';
  txt += '\n';
  write(1, txt.c_str(), txt.length() + 1);
}

int main() {
  func();
#if defined(__x86_64__)
  asm volatile(
      "pop %rbx\n"
      "pop %rbx\n"
      "pop %rbx\n"

      "pop %rsp\n"
      "pop %r12\n"
      "pop %r11\n"
      "pop %rdi\n"
      "pop %rdx\n"
      "pop %rcx\n"
      "pop %rax\n"

      "nop\n"
      "nop\n"
      "nop\n"
      "nop\n"
      "nop\n"
      "nop\n"
      "nop\n"
      "nop\n");
#elif defined(__aarch64__)
  asm volatile("nop\n");
#endif

  return 0;
}
