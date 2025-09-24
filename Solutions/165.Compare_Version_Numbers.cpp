class Solution {
public:
    vector<string> getString(string version){
        stringstream ss (version);
        string token = " ";
        vector<string> Tokens;

        while(getline(ss,token,'.')){
            Tokens.push_back(token);
        }
        return Tokens;

    }

    int compareVersion(string version1, string version2) {
        vector<string> v1 = getString(version1);
        vector<string> v2 = getString(version2);

        int m = v1.size();
        int n = v2.size();

        int i =0;
        while(i<m || i<n){
            int t1 = i<m?stoi(v1[i]):0;
            int t2 = i<n?stoi(v2[i]):0;

            if(t1<t2){
                return -1;
            }
            else if (t1>t2){
                return 1;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};


/*


Scenario 1: Different Lengths

Input: version1 = "1.0", version2 = "1.0.0"
getString(version1)

Creates a stringstream from "1.0".
Splits into tokens: ["1", "0"].
getString(version2)

Creates a stringstream from "1.0.0".
Splits into tokens: ["1", "0", "0"].
compareVersion() Begins

v1 = ["1", "0"], v2 = ["1", "0", "0"].
m = 2, n = 3, i = 0.
First iteration (i = 0)

t1 = stoi(v1[0]) = 1, t2 = stoi(v2[0]) = 1.
Both equal → i++.
Second iteration (i = 1)

t1 = stoi(v1[1]) = 0, t2 = stoi(v2[1]) = 0.
Both equal → i++.
Third iteration (i = 2)

t1 = 0 (missing in v1), t2 = stoi(v2[2]) = 0.
Both equal → i++.
End of loop → Return 0 (versions are equal).

-----------------------------------------------------
Scenario 2: Leading Zeros

Input: version1 = "1.01", version2 = "1.001"
getString(version1)

Splits into tokens: ["1", "01"].
getString(version2)

Splits into tokens: ["1", "001"].
compareVersion() Begins

v1 = ["1", "01"], v2 = ["1", "001"].
m = 2, n = 2, i = 0.
First iteration (i = 0)

t1 = stoi(v1[0]) = 1, t2 = stoi(v2[0]) = 1.
Both equal → i++.
Second iteration (i = 1)

t1 = stoi(v1[1]) = 1, t2 = stoi(v2[1]) = 1.
Both equal → i++.
End of loop → Return 0 (versions are equal).


----------------------------------------------------------

Scenario 3: version1 < version2

Input: version1 = "1.2", version2 = "1.10"
getString(version1)

Splits into tokens: ["1", "2"].
getString(version2)

Splits into tokens: ["1", "10"].
compareVersion() Begins

v1 = ["1", "2"], v2 = ["1", "10"].
m = 2, n = 2, i = 0.
First iteration (i = 0)

t1 = stoi(v1[0]) = 1, t2 = stoi(v2[0]) = 1.
Both equal → i++.
Second iteration (i = 1)

t1 = stoi(v1[1]) = 2, t2 = stoi(v2[1]) = 10.
2 < 10 → Return -1.

-------------------------------------------------------

Scenario 4: version1 > version2

Input: version1 = "1.10", version2 = "1.2"
getString(version1)

Splits into tokens: ["1", "10"].
getString(version2)

Splits into tokens: ["1", "2"].
compareVersion() Begins

v1 = ["1", "10"], v2 = ["1", "2"].
m = 2, n = 2, i = 0.
First iteration (i = 0)

t1 = stoi(v1[0]) = 1, t2 = stoi(v2[0]) = 1.
Both equal → i++.
Second iteration (i = 1)

t1 = stoi(v1[1]) = 10, t2 = stoi(v2[1]) = 2.
10 > 2 → Return 1.



*/