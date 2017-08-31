# D34DL1NE Task Priority

<img src="res/cli_screenshot_mm.png" height="325px" align="right">

_A prioritization program for the unorganized_

### The Project

1. The goal is to build a user-friendly lightweight program that will allow a user to:
	* Feed in Deadlines. Tasks, homework, or anything.
	* Based on this data, the program will display the most **urgent** task that needs completed.

### Basic Use

_This Main Menu will show the next task that is due, the one you **should** be working on. When it doubt, look at this top task and get to work. Stay Focused!_

* Keep adding in new tasks along with their deadline as they come up.
* Remove tasks as completed.

### Install (linux command line)

1. ````git clone https://github.com/bytePro17124/D34DL1NE_Task_Priority/````
2. ````cd D34DL1NE_Task_Priority````
3. ````make````
4. ````make install```` (run this with sudo if permission is denied)
5. you can now run the program at any time in your terminal window by typing in ````dtpriority````

### Uninstall (2 options from the same makefile used to install)

* ````make uninstall```` removes the program
* ````make purge```` removes the program and all saved data

### ToDo List / Idea List (in no particular order) (revise frequently) / Feel free to work on this

1. Additional Useful Functions
    * Task Breakdown Feature (idea mainly credited to @ebitikofer) (not implemented yet)
	    * creates subtasks with default names (section/chapter/anything)
	    * user determines subtask size
		    * even divides or custom
	    * resplit based on what is left at any point
	    * great for big tasks due way in the future

2. Working Concept
	* Terminal Version in the works (working, prealpha)
	* Load/Save Tasks from file (working, prealpha)
	* Add/Remove Tasks features (working, prealpha)
	* Proper Date Comparison Checks (working, prealpha)
	* Make the program Installable on Linux (working, prealpha)
    * Build a flowchart structure
    * Clean Feature - prompts to all remove out of date tasks one by one or all at once
    * Logs & Reports

3. Interface Clarity
	* Clean up / make clearer
	* Live Clock Ticker - sort of work, updates anytime the program changes
	* Build Terminal Graphic Library - might not do this and just use standard cli
	* Show Time Left on a task
