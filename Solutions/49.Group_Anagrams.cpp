class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<strings>& strs){
        unordered_map<string,vector<string>> map;
        for(auto s: strs){
            string key = s;
            sort(key.begin(),key.end());
            map[key].push_back(str);
        }

        vector<vector<string> groupedAnagrams;
        for(auto each:map){
            groupedAnagrams.push_back(each.second);
        }

        return groupeAnagrams;
    }
}


/*
Explanation : THE BRUTE FORCE!!!
The brute force appraoch would have been using aa for nested loop and map 
In the outer loop we would select the first element in the vector and push it into map and count the frequency of each word
Then in thee inner loop we would go through all the other elements that is i+1 and do the same push the element in the map and count frequency of each word
then within the for loop we would check if the freq of both the elements are equal then we would push the  element  into a vector thus creating a group 
and soo on we would do the same for all the elements
*/

/*
Explanation : OPTIMIZED!!!
Input: strs = ["eat","tea","tan","ate","nat","bat"]
1. we have created an unordered map which take the key-value pair of a string and a vector
2.Now using a for each loop we would go through the given vector of striings
3.Create a new variable  Key and store the element in it (key = 'eat')
4.Now we would sort the key (key = 'aet') and so the key becomes 'aet' since anaagrams have the same letters but in different order so sorting them would make them equal i.e. 'eat' and 'tea' would become 'aet' and 'aet' is the key  for both the strings
5.Now we would push the key along with the original string that was selected i.e. 'eat' into the map
6.Now if there is a key present in the map with the same as ours i.e('aet') then the string 'eat' would be pushed into the vector of the key 'aet'
7.If the key is not present then a new key would be created and the string 'eat' would be pushed into the vector of the key 'aet'
8.Now if we come through another word such as 'tea' then the key would be 'aet' and since the key is already present in the map the string 'tea' would be pushed into the vector of the key 'aet'
9.Now we have a map with all the keys and the vector of strings that are anagrams of each other
ex: map = {aet: [eat,tea,ate], ant: [tan,nat], abt: [bat]}

10.Now we would create a vector of vector of strings and name it groupedAnagrams
11.Now we would go through the map and push the vector of strings into the groupedAnagrams
12.Now we have a vector of vector of strings with all the anagrams grouped together
13.Return the groupedAnagrams

*/