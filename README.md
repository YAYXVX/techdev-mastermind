# PROJET MASTERMIND

> [!NOTE]
>The user_i/o branch separates in multiple functions [^1].

## How it's coordinated

It all starts with the selection of the difficulty by the user in **demande_user_gmode.c**, presenting two options which are EASY and HARD.  

Then the program proceeds to ask the user for a specific color code input in the range of 4 letters with the given 6 color codes that are **R** for <span style="color:red;">Red</span>, **C** for <span style="color:Cyan;">Cyan</span>, **Y** for <span style="color:#edfa00;">Yellow</span>, **G** for <span style="color:green;">Green</span>, **B** for <span style="color:#0969DA;">Blue</span> and **P** for <span style="color:#ec3ca5;">Pink</span>.  