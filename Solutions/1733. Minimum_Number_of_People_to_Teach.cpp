class Solution {
public:
//The problem cna be divided into three parts
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    //part i.) Find the users who can't talk to their friends
        unordered_set<int> no_talk_users; // This wil store the users who can't talk
        for(auto &f:friendships){
            //Here we are making the index 0 based as the array of language is 0 based, so we don't want to mismatch our users from the language they know, so we minus 1
            int u = f[0]-1;
            int v = f[1]-1;
        //Now we need to find out if the languages that user "u"  knows is same to any of the languages that user "v" knows
        //First we make a set to store all the known languages of user "u"
        unordered_set<int>u_LangSet (languages[u].begin(),languages[u].end());
        bool cantalk = false;
        for(int l:languages[v]){
            if(u_LangSet.count(l)){
                cantalk = true;
                break;
                //This means that there is a lanagguae that botyh user u an dv know and hence can talk so we don't need to see for them, as they are users who can talk
            }
        }
        //If we don't break out of the above loop it means there is no common known language amon users u and v they cant talk so we add them to the set of users who can't talk 
        if(!cantalk){
            no_talk_users.insert(u);
            no_talk_users.insert(v);

        }
        }

        //Part ii.) find the most Known language amongst the user who can't talk
        unordered_map<int,int> lang;
        int most_known_lang = 0; 
        for(int u: no_talk_users){ // for each user who can't talk
            for(auto &l : languages[u]){ // we find their known language
                lang[l]++; // store the count
                most_known_lang = max(most_known_lang,lang[l]); // update the most known lanaguage
            }
        }
        //When loop ends our variable most_known_lang has the most known languae among them
        // {This is the language that wee need to teach the other in order to minimise the no. of teachings}

        //Part iii.) Here is where we get our answers, We habe the users who can't talk and we have the mosrt know languages amoung the users who can't talk, so we just :

        return no_talk_users.size() - most_known_lang;

    }
};

/*

If i have to explain above code in simple it would go like

let;s say 

(User 1 , User 2)   1 and 2 are friends
 hindi , english    1 knows hindi and 2 knows english


(User 1, User 3)  1 and 3 are friends
 hindi , english  1 knows hindi and 3 knows english

Part i.) find people who can't talk
    no_talk_users = {}

 Can users 1 and 2 talk? ---> Do they have any languages in common --- > No
 They can't talk
 SO update:
 no_talk_users = {1,2}

  Can users 1 and 3 talk? ---> Do they have any languages in common --- > No
 They can't talk
 SO update:
 no_talk_users = {1,2,3}

 // Part ii.) Most Known language among users who cant talk

 no_talk_users = {1,2,3}
      
     lang  count
 map {hindi  1 ,
      english 2 }
 
 most known language = english = count = 2

 no_talk_users.size() = 3  
 most known language count = 2 {This is the language that wee need to teach the other in order to minimise the no. of teachings}

 So the minimum no. of people we need to teach english is = 3-2 = 1
 That is user 1  we need to teach english to , so that all the friends can talk




*/