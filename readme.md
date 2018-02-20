# CLI Human Task Priority Scheduler

<img src="screenshot_09112017.png" height="248px" align="right">

_A prioritization program for the unorganized_

Humans are being reprogrammed. 

### The Project

1. The goal is to build a user-friendly lightweight program that will allow a user to feed in Deadlines. Tasks, homework, or anything.

### Basic Use

_The Main Menu will show the next task that is due, the one you **should** be working on. When it doubt, look at this top task and get to work. Stay Focused!_

* Keep adding in new tasks along with their deadline as they come up.
* Remove tasks as completed.

### Install (linux command line)

1. ````git clone https://github.com/bytePro17124/D34DL1NE_Task_Priority/````
2. ````cd D34DL1NE_Task_Priority````
3. ````make````
4. ````sudo make install```` (must have sudo unless you already rooted yourself)
5. you can now run the program at any time in your terminal window by typing in ````dtpriority````

### Uninstall (2 options from the same makefile used to install)

* ````make uninstall```` removes the program
* ````make purge```` removes the program and all saved data

### ToDo List / Idea List (in no particular order) (revise frequently) / Feel free to work on this

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
	* Live Clock Ticker - sort of work, updates anytime the program changes
	* Build Terminal Graphic Library (scrapped, using cli) 
	* Show Time Left on a task

4. Humans are being reprogrammed.

I made this because I am terrible at routine. I will not remember to do things that are on a schedule - like monthly or yearly tasks. Most people I know will only do them if they are reminded. It's not like the old days when the time of year and day was significant and the enviornment was our reminder. Now most of us get used to a routine of being at computer screens and learning and updating non-stop. Looking for the new daily fix. With D34DL1NE (deadline, task priority), your schedule is set by you, for you
