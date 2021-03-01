/* syscall.c
 *
 * Call OS functions without using libc. The example `my_print` could be done in
 * different flavors:
 *
 * **my_print_64:**
 *   Using the SYSCALL instruction (successor to SYSENTER). Should work for both
 *   IA-64 and AMD64 CPUs, can be ported to `my_print_trap` (see there).
 *   Register usage:
 *
 *     - RAX: pass syscall number, hold return value from syscall execution
 *     - RDI: syscall argument 1
 *     - RSI: syscall argument 2
 *     - RDX: syscall argument 3
 *
 * **my_print_trap:**
 *   Using the trap interrupt to switch to kernel mode. Slower, but
 *   architecturally neutral. Register usage:
 *
 *     - EAX: pass syscall number, hold return value from syscall execution
 *     - EBX: syscall argument 1
 *     - ECX: syscall argument 2
 *     - EDX: syscall argument 3
 */

#include <asm/unistd.h> /* compile with -m32 for 32-bit syscall numbers,
                           without for 64-bit syscall numbers. */
/* simple inline assembler (asm) requires global symbols */
#define __NR_exit 60
// text buffer pointer
char *my_print_text;
// text buffer length, print return value
int my_print_len, my_print_ret;
// write() syscall number
int call_write;
int exitnum; 

int my_print_64(char *text) {
    my_print_text = text;

    /* strlen(my_print_text) manually */
    for (my_print_len = 0; my_print_text[my_print_len]; ++my_print_len);

    /* system call signature:
     * ssize_t write(int fd, const void *buf, size_t count);
     *
     * write() system call number is defined by __NR_write
     */
    call_write = __NR_write;
    /* stdout is file descriptor no. 1 */
    asm("mov call_write, %rax");    /* arg 0 (rax): syscall number  */
    asm("mov $1, %rdi");            /* arg 1 (rdi): file descriptor */
    asm("mov my_print_text, %rsi"); /* arg 2 (rsi): buffer          */
    asm("mov my_print_len, %rdx");  /* arg 3 (rdx): length          */
    asm("syscall");                 /* SYSCALL instruction          */
    asm("mov %rax, my_print_ret");  /* save return code (rax)       */

    return my_print_ret;
}

int my_print_trap(char *text) {
    /* system call signature: see my_print_64 */

    /* TODO */

    return 7;
}

/* simple inline assembler (asm) requires global symbols */

// exit return value
int my_exit_status;

void my_exit_64(int status) {
    my_exit_status = status;

    /* system call signature:
     * void exit(int status);
     *
     * exit() system call number is defined by __NR_exit
     */

    /* TODO */
    // Syscall
   //exitnum = __NR_exit;
   //asm("mov $60, %rax"); // verwende den exitnum / 60 Syscall
   //asm("mov my_exit_status, %rdi"); //status = myexitstatus oder 0 
   //asm("syscall");
   //TRAP 
   asm("mov $1, %eax");
   asm("mov my_exit_status, %ebx");
   asm("int $0x80"); 
   

  
}

int main(void) {
    my_print_64("Hello World!\n");

    my_exit_64(42);

    /* never come here, if my_exit_64 works */
    return 6;
}
