class Solution {
public:
   int rotten = 0;
   class Props{
       public:
       int i;
       int j;
       int t;
       Props(int i, int j, int t){
           this->i = i;
           this->j = j;
           this->t = t;
       }
   };

   void addnbr(vector<vector<int>>&grid,vector<vector<int>>&visited,int i, int j, int t, queue<Props*>&q){

       if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0 || grid[i][j]==2 ||  visited[i][j]==1){
           return;
       }
       q.push(new Props(i,j,t));
   }


    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<Props*>q;
        int foranges=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){

                if(grid[i][j]==2){
                    q.push(new Props(i,j,0));
                }else if(grid[i][j]==1){
                    foranges++;
                }

            }
        }

        int time = 0;
        //cout<<foranges<<endl;

        while(q.size()>0){

            Props * front = q.front();
            q.pop();

            if(visited[front->i][front->j] == 1){
                continue;
            }

            visited[front->i][front->j] = 1; 
            if(grid[front->i][front->j]==1){
                rotten++;
            }

            time = max(time,front->t);
            
            addnbr(grid,visited,front->i+1,front->j,front->t+1,q);
            addnbr(grid,visited,front->i-1,front->j,front->t+1,q);
            addnbr(grid,visited,front->i,front->j+1,front->t+1,q);
            addnbr(grid,visited,front->i,front->j-1,front->t+1,q);

        }
        //cout<<foranges<<" "<<rotten<<endl;
        if(foranges==rotten){
            return time;
        }
        //cout<<time<<endl;


        return -1;

    }
};