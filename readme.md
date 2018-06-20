# CLI Human Task Priority Scheduler

<img src="screenshot_09112017.png" height="248px" align="right">

_A prioritization program for busy students with many assignments and deadlines. Never forget to do an assignment again!_

### The Project

1. The goal is to build a user-friendly lightweight program that will allow a user to feed in all sorts Deadlines - Tasks, homework, or anything - and have a list of things to do that is automatically prioritized based on Due Date.

### Basic Use

* Keep adding in new tasks as they come up - a sure way to never forget to do it in time.
* Remove tasks when completed.
* When in doubt, look at the item at the top of your to-do list and get to work. Progress on any item is good time spent.

### Install (linux command line)

1. clone repo, go to the directory
2. run ````make install```` to build and set up the program on your linux machine (also works in Cygwin for Windows)
	* installs the executable globally, but each linux account user has their own save file
3. you can now run the program at any time in your terminal by typing in ````dtpriority````

### Uninstall (2 options from the same makefile used to install)

* ````make uninstall```` removes the program
* ````make purge```` removes the program and all saved data

### Dev Todo List and Ideas

1. Additional Useful Functions
    1. Add Task Breakdown Feature (idea mainly credited to @ebitikofer) (not implemented yet)
	    * creates subtasks with default names (section/chapter/anything)
	    * user determines subtask size
		    * even divides or custom
	    * resplit based on what is left at any point
	    * great for **big** tasks due way in the future
	2. Add Autosave at certain time intervals
	    * separate file that is used upon load if it is newer than the manual save file
	3. Add command line options that don't fully run the program
	    * option to add/remove tasks
	    * option to revise tasks
	        * these first 2 do the thing then save the file, and give the end user a success or failure message
	    * option to see Top Tasks (or any or all)
	4. Repeating Yearly, Monthly, Weekly, <specified day count> tasks can be set up to permantly repeat until removed. 
		* this allows for users to keep their whole life on specific routines and never forget to renew that yearly or monthly thing that must be upkept. I can see this being used as bill reminders, meeting reminders for groups, really the sky is the limit. The key thing here is that in any case, it remains super simple and straightforward and you just work on the thing at the top of the list in any case.

2. Working Concept
	* Terminal Version in the works (working, prealpha)
	* Load/Save Tasks from file (working, prealpha)
	* Add/Remove Tasks features (working, prealpha)
	* Proper Date Comparison Checks (working, prealpha)
	* Make the program Installable on Linux (working, prealpha)
    * Build a flowchart structure
    * Clean Feature - prompts to all remove out of date tasks one by one or all at once
    * Logs & Reports
        * Past Data from completed tasks
            * could save time on list(entry time - remove time), when completed(removed), and other statistics 

3. Interface Clarity
	* Clean up / make clearer
	* Live Clock Ticker - sort of works, updates anytime the program changes
	* Build Terminal Graphic Library (scrapped, using cli) 
	* Show Time Left on a task
