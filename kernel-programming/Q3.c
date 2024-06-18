#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/syscalls.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aaradhya | YaYa");
MODULE_DESCRIPTION("A simple kernel module to count running processes");


// Function to count running processes
static int count_running_processes(void) {
    struct task_struct *task;
    int count = 0;

    // Traverse the process list
    for_each_process(task) {
        if (task->__state == TASK_RUNNING){
            count++;
		}
    }

    return count;
}

// System call implementation
asmlinkage long sys_count_processes(void) {
    int running_processes = count_running_processes();
    printk(KERN_INFO "Number of running processes: %d\n", running_processes);
    return running_processes;
}

// Module initialization
static int __init init_syscall_module(void) {
    printk(KERN_INFO "Loaded: Aaradhya's process counter kernel module & number of running processes is: %d\n", count_running_processes());
    return 0;
}

// Module cleanup
static void __exit exit_syscall_module(void) {
    printk(KERN_INFO "Unloaded: Aaradhya's process counter kernel module\n");
}

module_init(init_syscall_module);
module_exit(exit_syscall_module);
