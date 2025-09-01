//Optimal Solution

class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; //max-heap  -  Our max heap stores the difference of the PR and the index 
        //In Heap the max diff willbe at the top

        /*First we need to calculate:
         ----> i.) Original_PR of each class
         ----> ii.) Updated PR of each class after Adding 1 Extrastudent
         ----> iii.) Their Differences in PR 
         */
         for(int i=0;i<n;i++){
         double orginal_PR = (double) classes[i][0]/classes[i][1];
         double updated_PR = (double) (classes[i][0]+1)/(classes[i][1]+1);
         double diff = updated_PR-orginal_PR;
// After getting the diff we put the diff of the class and the index of the class for which we are getting the diffrence into heap
         pq.push({diff,i});
        }
        //After the Loop ends our heap will have the max diff and it's index at top of heap
        //Now we just need to use the top of heap to which we will assign the 1 extra student
        
        while(extraStudents--){
            auto curr = pq.top(); // Our max diff is at the top of the heap
            pq.pop(); // We pop the top element as now we have the max element so we need to assign an extrStudnet to it, which will change the number of students in that class, so we will have to find the PR for this class again and so to avoid any errors that may arise if we did not remove it and just added the new Pr for this class it will alos have the same index ,s o may be our max diff will not be updated correctly. In order to aovid that we have to make sure we remove the max diff after we have gottent he index form it

            double diff = curr.first;
            int idx = curr.second;

            classes[idx][0]++; // Increase the count of passing stundent by 1
            classes[idx][1]++; // Increase the count of total student by 1

//Now very important till now we added 1 extrastudent to the class that had max diff and pop the if from the heap, now at this point our heap has the diff of other classes PR , and since we have not updated any of those classes we don't have to reclaculate their difference as it will be the same


//But for the class that we have the max_diff in at the index idx we have updated this class by adding one more student to it so  to keep the our heap updated with the max diff we have to update PR of this class with the updated values of student

//Basically for the class at index idx we will again find the original Pr  the updated Pr and the diff and put it in the heap
//So that when there is another iteration of the loop to find the class to assign our extrastundet it happens correctly



         double orginal_PR = (double) classes[idx][0]/classes[idx][1];
         double updated_PR = (double) (classes[idx][0]+1)/(classes[idx][1]+1);
         diff = updated_PR-orginal_PR;

         pq.push({diff,idx});


        }
        //Now our classes are updated with the correct extrastudents , now we just need to find the Average Pass Ratio

        double res = 0.0;
        for(int i =0;i<n;i++){
            res+=(double) classes[i][0]/classes[i][1];
        }
        return res/n;

    }
};

//T.C : O(extraStudents * log(n))
//S.C : O(n)

/*

The code is essentially a greedy strategy:

    Imagine all classes shouting: “If you give me one student, I’ll improve this much!”
    We always listen to the loudest voice (max diff).
    Give that class the student, update its shout (recalc diff), and put it back in the queue.
    Keep repeating until all extra students are assigned.
    Finally, average out everyone’s pass ratio and return it.



DRY RUN:

    classes = [[1,2], [3,5], [2,2]]
    extraStudents = 2
    Initial diffs:

    Class 0: (2/3 - 1/2) ≈ 0.166

    Class 1: (4/6 - 3/5) ≈ 0.033

    Class 2: (3/3 - 2/2) = 0
    Heap: [0.166 (idx=0), 0.033 (idx=1), 0 (idx=2)]

    First extra student: assign to class 0 (best diff).
    New class0 = [2,3]. Recompute diff = (3/4 - 2/3) ≈ 0.083.
    Heap now [0.083 (idx=0), 0.033 (idx=1), 0 (idx=2)].

    Second extra student: assign again to class 0.
    New class0 = [3,4]. Recompute diff = (4/5 - 3/4) = 0.05.
    Heap [0.05, 0.033, 0].

    Done. Now average PR = (3/4 + 3/5 + 2/2)/3 ≈ 0.783.
*/