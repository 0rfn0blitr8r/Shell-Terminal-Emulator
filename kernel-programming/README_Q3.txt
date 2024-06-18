Operating Systems
Assignment 2
Ques 3
x------------------------------------------------------------------------------------------x
by Aaradhya Verma 2022004 | YaYa (2022004-2022028)

Thought Process:
	In order to count the number of running processes at an instant of time, one can use task_struct
	to iterate over tasks loaded and count the process which are running

Dependencies:
	module.h, kernel.h, init.h, syscalls.h, sched/signal.h in the linux include file-Directory

**In Arch Linux, task_struct has a property '__state' instead of '_state' in other linux distributions**

//Function to count running processes
/*
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
*/

>>>This function is used to count the number of processes with a condition, whether it is "running" or not
"for_each_process(task){..}" is used to iterate over the loaded processes

>>>It returns a count of running processes.

//Function running when moduke is loaded and initialised
/*
static int __init init_syscall_module(void) {
    printk(KERN_INFO "Loaded: Aaradhya's process counter kernel module & number of running processes is: %d\n", count_running_processes());
    return 0;
}

module_init(init_syscall_module);
*/

>>>When module is loaded and initialised this function runs and calls the previous function to print the running processes at that instant

//Function running when module is exiting upon deloading
/*
static void __exit exit_syscall_module(void) {
    printk(KERN_INFO "Unloaded: Aaradhya's process counter kernel module\n");
}
module_exit(exit_syscall_module);
*/

>>When module is deloaded and exiting, the function runs to mention that function is unloaded

>>initializing and exiting functions sre declared using
module_init(init_syscall_module);
module_exit(exit_syscall_module);