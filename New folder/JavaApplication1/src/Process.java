public class Process extends JavaApplication1
{ 
    public int pid; // Process ID 
    public int bt; // Burst Time 
    public int art; // Arrival Time 
      
    public Process(int pid, int bt, int art) 
    { 
        this.pid = pid; 
        this.bt = bt; 
        this.art = art; 
    } 
} 
