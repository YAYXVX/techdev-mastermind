# USER_I/O BRANCH

The user_i/o branch separates in multiple functions.
* demande_user_gmode.c
* user_input.c

## Function explanation

### How it's coordinated

#### Step-1

It all starts with the selection of the difficulty by the user in **demande_user_gmode.c**, presenting two options which are:
- [**_EASY_**](#easy)
- [**_HARD_**](#hard)

#### Step-2

Then the program proceeds to ask the user for a specific color code input in the range of 4 letters with the 6 given colors that are **R** for <span style="color:red;">Red</span>, **C** for <span style="color:Cyan;">Cyan</span>, **Y** for <span style="color:#edfa00;">Yellow</span>, **G** for <span style="color:green;">Green</span>, **B** for <span style="color:#0969DA;">Blue</span> and **P** for <span style="color:#ec3ca5;">Pink</span>.

#### Step-3

If the color combination matches to 4 slots and each input is a valid input meaning that it's within the given color codes enumerated in [<u>step 2</u>](#step-2)

## Modes

### Easy

If the user input is **`e`**, **`E`**, **`Easy`** or **`EASY`**. The program will take anything starting with **e** as a valid input for the **_EASY_** mode and will announce to the user that the mode selection was successful.

### Hard

If the user input is **`h`**, **`H`**, **`Hard`** or **`HARD`**. The program will take anything starting with **h** as a valid input for the **_HARD_** mode and will announce to the user that the mode selection was successful.

<span style="background-color: yellow;">This text will be highlighted</span>
