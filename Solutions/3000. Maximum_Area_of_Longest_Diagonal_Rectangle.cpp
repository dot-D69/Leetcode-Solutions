class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
     int maxarea=0;
     int maxDiag = 0;

     for (int i=0;i<dimensions.size();i++){
        int length = dimensions[i][0];
        int width = dimensions[i][1];

        int diag = (length*length) +(width*width);
        int area = length * width; 
        
        if(diag>maxDiag){
            maxDiag = diag;
            maxarea = area;
        }
        else if(diag ==maxDiag && area>maxarea){
            maxarea = area;
        }
    }
    return maxarea;
    }
};

/*

We did as it was directed int he questions
we took the length and width as directed and then just imployed a simple check



*/