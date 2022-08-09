#include<iostream> 

using namespace std; 

// Function to find the waiting time for all 
// processes 
void findWaitingTime(char processes[], int n, 
                        int arrtime[], int wt[],int stime[]) 
{ 

    wt[0] = 0; 
    for (int i = 1; i < n ; i++ ) 
        wt[i] = stime[i] - arrtime[i] ; 
} 
void findctime (char processes[], int n, 
                int bt[],int ctime[], int arrtime[],int stime[]){
                    ctime[0]= arrtime[0]+bt[0];
                    stime[0]=arrtime[0];
                    for(int i=1;i<n;i++)
                    {
                        if(arrtime[i]>ctime[i-1]){
                            ctime[i]=arrtime[i]+bt[i];
                            stime[i]=arrtime[i];
                        }else
                        {
                            stime[i]=ctime[i-1];
                            ctime[i]=ctime[i-1]+bt[i];
                        }
                    }
                }
// Function to calculate turn around time 
void findTurnAroundTime( char processes[], int n, 
                int bt[], int wt[], int tat[],int arrtime[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

//Function to calculate average time 
void findavgTime( char processes[], int n, int bt[], int arrtime[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0,ctime[n],stime[n]; 

    //Function to find turn around time for all processes 
    
    findctime(processes, n, bt,ctime,arrtime,stime);
    findWaitingTime(processes, n, arrtime, wt, stime); 
    findTurnAroundTime(processes, n, bt, wt, tat,arrtime); 
    //Display processes along with all details 
    cout << "Processes "<<" ArrivalTime "<< "Burst time "
        << " Waiting time " << " Turn around time"<< "    Complete Time  " << "    start time \n";

    // Calculate total waiting time and total turn 
    // around time 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << processes[i] << "\t\t" << arrtime[i] <<"\t"<< bt[i] <<"\t\t"
            << wt[i] <<"\t\t " << tat[i] <<"\t\t"<<ctime[i]<<"\t\t"<<stime[i]<<endl; 
    } 
    

    cout << "Average waiting time = "
        << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n; 
        
        cout<<" \n THE GRANTT CHART OF THE PROCESSES IS \n";
    cout<<"\n"; 
            for(int i=0;i<n;i++)
    {
        cout<<processes[i]<<"\t |";
    }
    cout<<"\n";
    cout<<stime[0]<<"\t";
        for(int i=1;i<n;i++)
    {
         cout<<stime[i]<<"\t  ";
    }
    cout<<stime[n-1]+bt[n-1];
} 
int main() 
{ 
    int  n;
    cout<<"Enter the number of processes\n";
    cin>>n;
    cout<<" Enter the each process (eg p_name  arrival_time burst_time) \n\n";
    char processes[n] ; 
    int arrtime[n]; 
    int burst_time[n] ;
    
    for(int i=0 ;i<n;i++)
    {
        cout<<"\n Enter "<< i+1 << "  Process"<<"\n";
        cin>> processes[i];
        cin>> arrtime[i]>>burst_time[i];
     } 

    findavgTime(processes, n, burst_time,arrtime); 

    return 0; 
}