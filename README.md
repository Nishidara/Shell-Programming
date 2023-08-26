# Shell-Programming
recreating a terminal in c

(We had limited authorize function).

Mnishell 1 - We had to program a UNIX command interpreter.
The interpreter is expected to display a prompt ( $> for example ) and then wait for the user to write a command
line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.
If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
We must correctly handle the PATH and the environment (by copying and restoring the initial env).
We must implement the following builtins: cd, setenv, unsetenv, env, exit.
Our env builtin hasn’t to take any argument. Your unsetenv builtin hasn’t to support the “*” wildcard.

Mnishell 2 - The goal of the project is to enrich your minishell1 project by adding semicolons (‘;’), pipes (‘|’), and the four
redirections (‘>’, ‘<’, ‘»’, ‘«’) management
