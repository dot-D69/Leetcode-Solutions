class Router {
public:
    int limit; // Max number of packets router can store
    queue<string> packets; // Stores packet keys in FIFO order
    unordered_map<string,vector<int>> packetmp; // Maps packet key -> {source, destination, timestamp}
    unordered_map<int,vector<int>> timemp; // Maps destination -> sorted list of timestamps

    Router(int memoryLimit) {
        limit = memoryLimit; // we need this to check that the size of the packets does not exceed the memory Limit
    }

    string makeKey(int S,int D, int T){
        return to_string(S) + "_" + to_string(D) + "_" + to_string(T); 
        // Combines source, destination, timestamp into a unique string key
        //We use a string as it makes insertion and storign three values in the queue as well as map easier
    //Why do we use the "_" to connect them?
    // lets take 2 packets [10 22 5] and [10 2 25]
    //If we convert them without the "_" then they both will be : 10225  10225 {we can tell which one i which}
    //Hence w enee dthe "_" so: 10_22_5 and 10_2_25 
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp); 

        if(packetmp.find(key) != packetmp.end()){ // Check if packet already exists (duplicate)
            return false; // Duplicate found, do not add
        }
        
        if(packets.size() >= limit){ // If memory limit reached
            forwardPacket(); // Remove oldest packet to make space
        }

        packets.push(key); // Add packet key to FIFO queue
        packetmp[key] = {source, destination, timestamp}; // Store packet details
        timemp[destination].push_back(timestamp); // Store timestamp for destination (kept sorted by input order)
        return true; // Successfully added
    }
    
    vector<int> forwardPacket() {
        if(packets.empty()){ // No packets to forward
            return {};
        }
        string key = packets.front(); // Get oldest packet key
        packets.pop(); // Remove it from queue

        vector<int> P = packetmp[key]; // Retrieve packet details
        packetmp.erase(key); // Remove from packet map

        int dest = P[1]; // Extract destination
        timemp[dest].erase(timemp[dest].begin()); // Remove earliest timestamp for that destination

        return P; // Return packet details
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = timemp.find(destination); // Find timestamps for given destination
        if(it == timemp.end()){ // No packets for this destination
            return 0;
        }

        // Find first timestamp >= startTime
        int s_idx = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);
        // Find first timestamp > endTime
        int e_idx = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second);

        return e_idx - s_idx; // Count of timestamps in range
    }
};



/*
====================================
Detailed Explanation of Router Class
====================================


1. Data Structures Used and Why
--------------------------------
1.1 int limit
    - Stores the maximum number of packets the router can hold.
    - Important because memory is finite, so we must enforce eviction of old packets once the capacity is reached.

1.2 queue<string> packets
    - Stores packet keys in FIFO (First-In-First-Out) order.
    - Why a queue? Because network routers forward packets in the same order they arrived → oldest gets forwarded first.
    - Alternative: could store full packet (source, destination, timestamp) directly,
      but instead we store keys to avoid duplication of data and to allow quick lookups in maps.

1.3 unordered_map<string, vector<int>> packetmp
    - Maps a unique packet key → {source, destination, timestamp}.
    - Why?
        • Allows O(1) average-time lookup by key.
        • Prevents duplicates: before inserting, we check if the key already exists.
        • Storing full packet details here avoids bloating the queue with big data (queue only keeps keys).

1.4 unordered_map<int, vector<int>> timemp
    - Maps destination → sorted list of timestamps.
    - Why store timestamps separately?
        • Needed for fast queries (getCount(destination, startTime, endTime)).
        • With this, we can binary search for how many packets arrived within a time window.
    - Vector chosen because insertions are always at the end (timestamps come in increasing order for each destination).
    - Binary search (lower_bound/upper_bound) works in O(log n).


 #######################################################################################   


2. Functions Explained
----------------------

2.1 string makeKey(int S, int D, int T)
    - Combines (source, destination, timestamp) into a unique string like "10_22_5".
    - Why use "_" between numbers?
        • Without separators, (10, 22, 5) → "10225" and (10, 2, 25) → "10225". Both collide.
        • Adding "_" avoids ambiguity: "10_22_5" vs "10_2_25".
    - Why a string at all?
        • Easier to push into queue and store in maps as a unique identifier.
        • Alternative: could use a tuple (S,D,T) but C++’s unordered_map needs a custom hash → string simplifies design.

2.2 bool addPacket(int source, int destination, int timestamp)
    - Build packet key using makeKey.
    - Duplicate check:
        • If packetmp.find(key) exists → return false.
        • Ensures no two identical packets exist.
    - Memory check:
        • If queue is at limit → forwardPacket() is called to free space.
        • Maintains FIFO eviction.
    - Add packet:
        • Push key into packets queue.
        • Store {source, destination, timestamp} in packetmp.
        • Append timestamp to timemp[destination].
    - Return true = success.

2.3 vector<int> forwardPacket()
    - If queue empty → return {}.
    - Take the front key (oldest packet).
    - Pop it from queue.
    - Retrieve {source, destination, timestamp} from packetmp.
    - Remove from packetmp (since forwarded).
    - Remove earliest timestamp from timemp[destination].
        • Safe because timestamps were inserted in order.
    - Return packet {source, destination, timestamp}.
    - Ensures FIFO forwarding and consistent state across all DS.

2.4 int getCount(int destination, int startTime, int endTime)
    - Find destination in timemp. If none → return 0.
    - Use binary search:
        • lower_bound → first timestamp >= startTime.
        • upper_bound → first timestamp > endTime.
    - Subtract indices → gives number of timestamps within [startTime, endTime].
    - Very efficient: O(log n) per query.


3. Time Complexity Analysis
---------------------------
3.1 makeKey → O(1)

3.2 addPacket:
    - Key creation O(1).
    - Duplicate check O(1).
    - Queue push O(1).
    - Insert into packetmp O(1).
    - Append to timemp[destination] O(1).
    - Total: O(1).

3.3 forwardPacket:
    - Queue pop O(1).
    - Map lookup/erase O(1).
    - Vector erase at front O(n) worst-case!
      • Note: timemp[dest].erase(begin()) shifts elements → costly.
      • If many packets per destination, this could be a bottleneck.
      • Alternative: use deque or multiset.
    - Total: O(n) worst-case for timestamps.

3.4 getCount:
    - Binary search on timestamps vector O(log n).
    - Total: O(log n).



4. Space Complexity
-------------------
    - queue<string> packets → O(N)
    - unordered_map<string, vector<int>> packetmp → O(N)
    - unordered_map<int, vector<int>> timemp → O(N)
    - Overall: O(N)

*/
