
Your shall should pass the following tests

1) Pipe full

Run the command line

$ fillpipe | wc -c
q
The output should probably be two lines

131087
131087

The first number is twice the size of the kerne's pipe buffer (unless your kernel has a different configuration, but this is not a problem).
The second number is how many bytes fillpipe was able to output to wc command.

Program fillpipe writes more bytes than it can fit in the kernel's pipe buffer. If you have implemented the shell pipe functionality correctly, fillpipe and wc will be executed in parallel and everything will work as expected.   If, however, you have implemented your shell such that both commands run in sequence, then fillpile will fill in the buffer completely and will block; since wc will not run before fillpipe completes, you will have a so feared deadlock: your pipeline will stuck. Get back to your code and redesign your program to run pipes in parallel (one form/exec for each command in a pipeline).

If you get the second number lower than first number, you have probably done something wrong. Check your code.

If you get a "broken pipe", you have certainly made some mistake. Check your code.

2) Long pipe

Run the command

$ ./fillpipe | cat | cat | cat | cat | wc -c

The output should be

31087
131087

The sequence of cat commands will just cause fillpipe's output to pass through the pipeline, to be counted by wc.
The same considerations of test 1) apply.

3) Output redirection

Run the command

$ cat Hello > out.txt
$ cat out.txt 

The answer shall be

Hello

It this is not what you get, check your code.

4) Redirect both input and output

Run the command

$ cat Hello > in.txt
$ cat < in.txt > out.txt
$ cat out.txt

The output shall be 

Hello

It this is not what you get, check your code.

5) Pipe and IO redirection

Run the command 

$ echo Hello | wc -c > out.txt
$ cat out.txt

The answer should be 

6

If this is not what you get, you may have a problem with your pipe or output redirection. Check your code.

6) Kill the zombies

Run the command

$ echo x | cat | cat | ./busy 

The pipeline shall stuck, as busy does nothing but pause. When all previous commands in the pipeline have been finished, they must be removed by the kernel from the list of process. In order to verify if this is happening, in another terminal, with bash, run the command

$ ps uf

You should not see zombie cats.  If you do, it is because your shell is not calling syscall wait for the cat commands when they terminate. Check your code. Tip: set up a handler for SIGCHLD signal where you go thought list of child process, calling waitpid in nonblocking mode.  

7) Background execution

Run the command

$ ./back &

You should see it counting from 1 to 15. Before it hits 15, run the built-in command

$ jobs

You should see information on the status of the command 'back' (the syntax of the output will depend on your implementation).

If you can't run the command jobs because it don't have the prompt, then back is running in foreground instead of background. Check your code.

If you can run the command jobs but you don't see the 1-to-15 count, then 'back' is probably stopped and not in background. Run ps uf command to verify. Check your code.

8) Terminal control

Run the command

$ cat &

then run

$ jobs

You should see that jobs is stopped rather than running in background. Confirm is ps uf to see that the process status: you should see that the process controlling the terminal is your shell (on the column STAT, the '+' symbol indicates who has the control).  If this is not happening, check your code. Tip, see libc manual, section "Job Control", and specially the subsection "Implementing a Job Control Shell").

Them, run the built-in command fg (possibly passing the job number of program cat, syntax will depend on your implementation).

You should now "loose" the prompt. Everything you type should be read by cat and echoed back on the terminal.

Run ps command again and ensure that the '+' sign is with cat process.

9) Current directory

Run the built-in

$ cd <some-other-directory>

and check if the current directory changes with the (external) command pwd. If it is not working, check your code.

Verify also if the environment variable PWD is changed accordingly

$ echo $PWD

If value of $PWD does not match the output of command pwd, check your code: you should manually change the value of PWD variable.

10) Killing from outside

Run command 

$ ./busy &

Go to another terminal and command ps uf to verify that is running on background (status S ou R, without '+' symbol)

At the other terminal run

$ kill -n SIGTERM <PID_OF_CAT>

replacing PID_OF_CAT of cat process' pid.

Now, get back to your shell and run built-in command jobs.  Verify if the command was removed from the list of jobs.

11) Pipeline job

Run the command

$ echo x | busy &

Then run

$ jobs

The pipeline 'echo x | busy &' should appear as single job (as it happens in bash). You will have two process, one for echo and another for busy; however, the job shall be associated with the whole pipeline, not the processes.  Run the same command in bash and ensure your shell is performing accordingly.





