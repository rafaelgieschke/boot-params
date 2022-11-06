// https://www.kernel.org/doc/html/latest/x86/boot.html
// https://www.kernel.org/doc/html/latest/x86/zero-page.html
// https://github.com/torvalds/linux/blob/master/arch/x86/include/uapi/asm/bootparam.h

#include <asm/bootparam.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct boot_params boot_params;
  read(open(argv[1] ?: "/sys/kernel/boot_params/data", O_RDONLY), &boot_params,
       sizeof boot_params);
  __builtin_dump_struct(&boot_params, &printf);
}
