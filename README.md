# Philosophers

<div align="center">
  <img src="./assets/example.gif"/>
</div>  


## What is it?
A project to solve the 42 version of the classic [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), used in concurrent algorithm design, to illustrate synchronization issues and techniques for resolving them. 

### The 42 problem statement
- One or more philosophers dine together at the same table.  
- Each philosopher has their own plate at the table.  
- There is a fork between each plate.  
- The dish served is a kind of spaghetti that has to be eaten with two forks.  
- Each philosopher can only alternately eat, think or sleep.  
- Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork, and it will eat for x milliseconds.    
- After an individual philosopher finishes eating, they will put down both forks and start sleeping for x milliseconds.
- After sleeping, the philosopher will start thinking, and it will try to eat. If it cannot eat in x milliseconds, it will die.
- If a philosopher dies, a message mentioning it must be displayed with no more than 10 milliseconds of delay.
- All philosophers must eat a specified number of times (optional).

The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will starve, i.e., each can forever continue to alternate between eating, sleeping and thinking, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).  

**Succeeded with 100%**

## Skills
- Rigor
- Unix
- Imperative programming

## How to use it
Requirements:
```shell
sudo apt install gcc
```

Clone the repository and run:
```shell
cd philo && make
```
The binary will be created and must be executed as follows:

```shell
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Where:
- number_of_philosophers: The number of philosophers and also the number of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

Example:
```shell
./philo 5 500 100 300
```

## Found any bugs?
Feel free to contact me or create an issue!

## License
This project is licensed under the GNU General Public License v3.0 - see the [COPYING](https://github.com/hde-oliv/minitalk/blob/master/COPYING) file for details.

