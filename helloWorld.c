#include <linux/init.h>             // Macros used to mark up functions e.g., __init __exit
#include <linux/module.h>           // Core header for loading LKMs into the kernel
#include <linux/kernel.h>           // Contains types, macros, functions for the kernel

MODULE_LICENSE("GPL");              ///< The license type -- this affects runtime behavior
MODULE_AUTHOR("Jeff Ledin");      ///< The author -- visible when you use modinfo
MODULE_DESCRIPTION("A simple Linux driver for the RPi.");  ///< The description -- see modinfo
MODULE_VERSION("0.1");              ///< The version of the module

static int __init helloRPi_init(void){
   printk(KERN_INFO "Hello world!\n");
   return 0;
}

/** @brief The LKM cleanup function
 *  Similar to the initialization function, it is static. The __exit macro notifies that if this
 *  code is used for a built-in driver (not a LKM) that this function is not required.
 */
static void __exit helloRPi_exit(void){
   printk(KERN_INFO "Goodbye cruel world!\n");
}

/** @brief A module must use the module_init() module_exit() macros from linux/init.h, which
 *  identify the initialization function at insertion time and the cleanup function (as
 *  listed above)
 */
module_init(helloRPi_init);
module_exit(helloRPi_exit);
