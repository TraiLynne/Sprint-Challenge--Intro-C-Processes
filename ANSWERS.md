**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Running - Process is running ro ready to run
- Suspended - Process is waiting in a waiting queue, like parent process waiting on child process
- Stopped - Process has been stopped but can be restarted by some other process
- Zombie - Process is terminated but there is still information in the process table


**2. What is a zombie process?**

Ok so normally a parent process is nice enough to listen to each child one by one in order until they are done with what they got to say. The parent process collects the exit status from the child and the child is dismissed. All the parent does is `wait()` for its child process to finish with some proper manners. In the end the child dies and the parent goes on about it's day. But it was kind enough to listen to the child processes last word right? But when a parent process is just rude and decides to go on to the next child process or task without `wait()`ing for the child process before it to terminate and give up the valuable exit status, that child becomes a zombie. In terms of zombie, the process is dead. It existed, was ran, then died. But the parent never collected the exit status so, the child still has a lifeline to the parent process because it can't detach until the parent gets that exit status. The child process is a good child and wants to give that code even after death but the rude parent just wouldn't wait. But no worries, the child process says "I'm still ready to give you this info although I am dead, But I ain't gone yet. I will haunt you til you accept this information." Thus making it a zombie.


**3. How does a zombie process get created? How does one get destroyed?**

A child process becomes a zombie until it's parent process waits for it.  Based on the information, when a parent process dies, if there are any zombie children, those are adopted by the next parent. 


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages are converted directly into machine-level code. This means that they can be read by the computer directly instead of having to be deciphered everytime the application is run. This makes running the program extremely fast.