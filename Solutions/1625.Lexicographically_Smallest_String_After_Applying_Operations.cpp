    class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string smallest = s;

        q.push(s);
        visited.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();
            smallest = min(smallest,curr);

            //ADD a to odd digits
            string addStr = curr;
            for(int i = 1;i<addStr.size();i+=2){
                addStr[i] = (addStr[i] - '0' + a)%10 +'0';
            }
            if(!visited.count(addStr)){
                visited.insert(addStr);
                q.push(addStr);
            }

            //Rotated String by b
            string Rotated = curr.substr(curr.size()- b) + curr.substr(0,curr.size()-b);
            if(!visited.count(Rotated)){
                visited.insert(Rotated);
                q.push(Rotated);
            }
        }
        return smallest;
    }
};

// Time complexity =O(n×number_of_unique_states)
// Space complexity =O(n×number_of_unique_states)

/*
DRY RUN:

Initial setup
Queue: ["5525"]
Visited: {"5525"}
Smallest: "5525"
-------------------------------------------------------

Step 1: Pop "5525"
Compare with smallest → "5525" == "5525", no change.

Operation 1 – Add a to odd indices (1, 3)
Index 1: '5' → (5 + 9) % 10 = 4 → '4'
Index 3: '5' → (5 + 9) % 10 = 4 → '4'
Result: "5424"
→ Not visited → Add to queue, mark visited.


Operation 2 – Rotate right by b=2
"5525" → "2555"
→ Not visited → Add to queue, mark visited.

State after Step 1:
Queue: ["5424", "2555"]
Visited: {"5525", "5424", "2555"}
Smallest: "5525"
-------------------------------------------------------

Step 2: Pop "5424"
Compare with smallest → "5424" < "5525" → update smallest = "5424".

Add operation:
Index 1: '4' → (4 + 9) % 10 = 3 → '3'
Index 3: '4' → (4 + 9) % 10 = 3 → '3'
Result: "5323"
→ Not visited → Add to queue.

Rotate operation:
"5424" → "2454"
→ Not visited → Add to queue.

State:
Queue: ["2555", "5323", "2454"]
Visited: {..., "5323", "2454"}
Smallest: "5424"
-------------------------------------------------------

Step 3: Pop "2555"
"2555" < "5424" → smallest = "2555".

Add:
Index 1: '5' → 4
Index 3: '5' → 4
Result: "2454" (already visited) → skip.

Rotate:
"2555" → "5525" (already visited) → skip.
-------------------------------------------------------
Step 4: Pop "5323"
"5323" < "2555"? No.

Add:
Index 1: '3' → 2
Index 3: '3' → 2
Result: "5222" → add to queue.

Rotate:
"5323" → "2353" → add to queue.
-------------------------------------------------------
Step 5: Pop "2454"
"2454" < "2555" → smallest = "2454".

Add:
Index 1: '4' → 3
Index 3: '4' → 3
Result: "2353" (already visited) → skip.

Rotate:
"2454" → "5424" (visited) → skip.
-------------------------------------------------------
Step 6: Pop "5222"
"5222" < "2454"? No.

Add:
Index 1: '2' → 1
Index 3: '2' → 1
Result: "5121" → add to queue.

Rotate:
"5222" → "2252" → add to queue.
-------------------------------------------------------
Step 7: Pop "2353"
"2353" < "2454" → smallest = "2353".

Add:
Index 1: '3' → 2
Index 3: '3' → 2
Result: "2252" (visited) → skip.

Rotate:
"2353" → "5323" (visited) → skip.
-------------------------------------------------------
Step 8: Pop "5121"
"5121" < "2353"? No.

Add:
Index 1: '1' → 0
Index 3: '1' → 0
Result: "5020" → add to queue.

Rotate:
"5121" → "2151" → add to queue.
-------------------------------------------------------
Step 9: Pop "2252"
"2252" < "2353" → smallest = "2252".

Add:
Index 1: '2' → 1
Index 3: '2' → 1
Result: "2151" (visited) → skip.

Rotate:
"2252" → "5222" (visited) → skip.
-------------------------------------------------------
Step 10: Pop "5020"
"5020" < "2252"? No.

Add:
Index 1: '0' → 9
Index 3: '0' → 9
Result: "5929" → add to queue.

Rotate:
"5020" → "2050" → add to queue.
-------------------------------------------------------
Step 11: Pop "2151"
"2151" < "2252" → smallest = "2151".

Add:
Index 1: '1' → 0
Index 3: '1' → 0
Result: "2050" (already in queue) → skip.

Rotate:
"2151" → "5121" (visited) → skip.
-------------------------------------------------------
Step 12: Pop "5929"
"5929" < "2151"? No.

Add:
Index 1: '9' → 8
Index 3: '9' → 8
Result: "5828" → add to queue.

Rotate:
"5929" → "2959" → add to queue.
-------------------------------------------------------
Step 13: Pop "2050"
"2050" < "2151" → smallest = "2050" ✅

Add:
Index 1: '0' → 9
Index 3: '0' → 9
Result: "2959" (visited) → skip.

Rotate:
"2050" → "5020" (visited) → skip.
At this point, BFS will continue exploring, but no string will be smaller than "2050".
So final answer = "2050"

*/


/*

        BFS TREE:

                           5525
                     /            \
              5424 --------------> 2555
             /     \               (no new)
       5323       2454
      /   \ 
   5222   2353
   /   \
5121   2252
 /  \ 
5020 2151
 / \
5929 2050 ✅
 /  \
5828 2959



*/