class TaskManager {
public:
// Max-heap to store tasks by priority and taskId
    priority_queue<pair<int,int>> maxHeap;
     // Maps taskId to its latest priority
    unordered_map<int,int>taskPriorMp;
    // Maps taskId to the userId that owns the task
    unordered_map<int,int>userIdMp;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &t: tasks){
            add(t[0],t[1],t[2]);// Add each task to the system
        }
    }
    
    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority,taskId});// Add task to the maxHeap
        taskPriorMp[taskId] = priority;// Update the task's priority in the map
        userIdMp[taskId] = userId; // Map the task to its user
    }
    
    void edit(int taskId, int newPriority) {
        maxHeap.push({newPriority,taskId});// Push the updated task into the heap
        taskPriorMp[taskId] = newPriority;// Update the task's priority in the map
    }
    
    void rmv(int taskId) {
        // Mark the task as invalid
        taskPriorMp[taskId] = -1; //Lazy Deletion
    }
    
    int execTop() {
        while(!maxHeap.empty()){
        // Get the task at the top of the heap since highest is at top
            auto [prior, taskId] = maxHeap.top();
            maxHeap.pop();// Remove it from the heap, as we have excuted it
            // Check if the task is valid
            if(prior == taskPriorMp[taskId]){ //This means its a fresh entry
                taskPriorMp[taskId] =-1; // Mark the task as executed
                return userIdMp[taskId];// Return the userId of the task
            }
        }
        return -1; // If no valid task remains, return -1
    }
};

/**
1. Why we used the data structures in this code?

i.)priority_queue (maxHeap):

    Used to always retrieve the task with the highest priority  efficiently.
    It automatically keeps the tasks sorted by priority, so the top element is always the one with the highest priority.
    Necessary because "execTop()" requires us to find and execute the task with the highest priority.

ii.)unordered_map<int, int> taskPriorMp:

    Maps taskId to its priority.
    Used to quickly check or update the priority of a specific task.
    Needed for lazy deletion (explained later) and to ensure we always work with the latest priority of the task.

iii.)unordered_map<int, int> userIdMp:

    Maps taskId to the userId that owns the task.
    Necessary for execTop() to return the correct userId when a task is executed.

2. How is maxHeap used and why is it necessary?

How it’s used:
    Every task (with priority and taskId) is pushed into the maxHeap whenever a task is added or its priority is updated.
    The maxHeap ensures the task with the highest priority is always at the top.

Why it’s necessary:
    Without the maxHeap, finding the task with the highest priority would require sorting or scanning all tasks every time  we call execTop(). This would be inefficient.
    The maxHeap ensures that execTop() runs in O(log n) time.


3. What does taskPriorMp do and how does it work?
What it does:
    Stores the latest priority of every task (taskId → priority).

How it works:
    When a task is added or its priority is updated, taskPriorMp is updated with the new priority.
    During lazy deletion (in execTop()), it helps verify if a task’s priority in the maxHeap is still valid or outdated.

4. What does userIdMp do and what is its use?

What it does:
    Stores the mapping between a taskId and the userId who owns it (taskId → userId).

Its use:
    When a task is executed (in execTop()), we use userIdMp to find and return the associated userId.


5. What is lazy deletion, why is it helpful, and how does it work?

What is lazy deletion?
    Instead of immediately removing outdated tasks from the maxHeap, we mark them as invalid in taskPriorMp by setting their priority to -1.

Why is it helpful?
    Removing elements directly from the maxHeap is not possible without rebuilding the heap, which is inefficient.
    Lazy deletion avoids this by simply ignoring outdated tasks when they are popped from the heap.

How it works:
    In execTop(), we pop elements from the maxHeap until we find a task whose priority matches its value in taskPriorMp.
    If the task’s priority in the heap doesn’t match, it means the task was updated or removed, so we skip it
    This is where Lazy Deletion helps, once we have been trhough a taskand it's priority we mark it as -1
    Next time we gaincheck the top of the maxHeap for the task with highest prioriy
    If the task whose priority  does matches its value in taskPriorMp, it means it is stale


6. How does execTop() work?

Purpose:
    Executes the task with the highest priority and removes it from the system.
    If multiple tasks have the same priority, the task with the higher taskId is executed.

Step-by-step process:
    While the maxHeap is not empty:
    Get the top task (priority, taskId).
    Remove it from the heap.
    Check if the task’s priority in taskPriorMp matches the priority from the heap:
    If it matches, the task is valid. Mark it as executed (set taskPriorMp[taskId] = -1) and return the userId using userIdMp.
    If it doesn’t match, the task is outdated (due to lazy deletion), so skip it.
    If the heap becomes empty, return -1 (no tasks available).


Basically :
We maintain:
1. maxHeap → stores tasks as (priority, taskId) [max-heap ensures highest priority comes first].
2. taskPriorMp → maps taskId → latest priority (-1 means removed/executed).
3. userIdMp → maps taskId → userId (who owns the task).

 */


// ###############################################################################
/*

DRY RUN:


INPUT SEQUENCE
--------------------------------------------------------
tasks = [[1, 101, 10], [2, 102, 20], [3, 103, 15]]
taskManager.add(4, 104, 5)
taskManager.edit(102, 8)
taskManager.execTop()
taskManager.rmv(101)
taskManager.add(5, 105, 15)
taskManager.execTop()

--------------------------------------------------------
STEP-BY-STEP DRY RUN
--------------------------------------------------------
Step                maxHeap (priority, taskId)       taskPriorMp (taskId → priority)    userIdMp (taskId → userId)    Output
---------------------------------------------------------------------------------------------------------------------------
Initialize tasks    (20,102), (10,101), (15,103)     101→10, 102→20, 103→15            101→1, 102→2, 103→3           -
Add (4,104,5)       (20,102),(10,101),(15,103),(5,104) 104→5                           104→4                         -
Edit (102,8)        (20,102),(10,101),(15,103),(5,104),(8,102) 102→8                  102→2                         -
ExecTop()           Top (20,102) is stale (latest=8). Skip.  
                    Next (15,103) valid → execute.   103→-1                           103→3                         3
Rmv (101)           (10,101) now invalid.            101→-1                           101→1                         -
Add (5,105,15)      (15,105),(15,103),(8,102),(5,104) 105→15                          105→5                         -
ExecTop()           Top (15,105) valid → execute.    105→-1                           105→5                         5


*/