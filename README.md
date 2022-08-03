# The Monty Hall Problem

The Monty Hall problem is a famous game show problem named after the original host, Monty Hall.

Let's suppose that there are three doors. Behind one of these doors is something valuable. Behind the other two doors are nothing
or something undesirable. You get the initial pick of what door you want to open. After you have chosen your door, one of the doors
that contains nothing is revealed to you. Now you have the option to change to the other door or stay with the one you initially chose.

Is it to your advantage to change your pick to the other door?

## Answer

Yes, it is always to your advantage to change your pick to the other door. Reason being that your initial guess has a 1 in 3 chance of being correct.
When one undesirable door is revealed you have a opportunity to make your 1 in 3 chance a 1 in 2 chance. If you keep you guess then the action of a door being
revealed as bad has no effect on the outcome.

## Problem Simulation

```Output
How many games would you like to play? 1000
The probability of winning if you change your choice is 0.655
The probability of winning if you keep your choice is 0.341
There where 341 wins if you keep your choice and 655 wins if you change your choice.
```

## License

Copyright (c) Brandon Pacewic

SPDX-License-Identifier: MIT
