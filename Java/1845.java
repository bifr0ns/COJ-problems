import java.util.Scanner;
public class FSSUM {

    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high]; 
        int i = (low-1); // index of smaller element
        for (int j=low; j<=high-1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;
 
                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
 
        // swap arr[i+1] and arr[high] (or pivot)
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
 
        return i+1;
    }
 
 
    /* The main function that implements QuickSort()
      arr[] --> Array to be sorted,
      low  --> Starting index,
      high  --> Ending index */
    void sort(int arr[], int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[pi] is 
              now at right place */
            int pi = partition(arr, low, high);
 
            // Recursively sort elements before
            // partition and after partition
            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Nl,Ql,N[],Q[],temsum,sumN=0,i,j,k,l,limit;
        boolean res[],arrbin[];
        Nl=sc.nextInt();
        N=new int[Nl];
        for(i=0;i<Nl;i++){
            N[i]=sc.nextInt();
            sumN+=N[i];
        }
        int n = N.length;
 
        FSSUM ob = new FSSUM();
        ob.sort(N, 0, n-1);
        //Ordenar N de memor a mayor;
        Ql=sc.nextInt();
        Q=new int[Ql];
        res=new boolean[Ql];
        for(i=0;i<Ql;i++){
            Q[i]=sc.nextInt();
        }
        //Ordenar Q de menor a mayor
        
        for(i=0;i<Ql;i++){
            if(Q[i]<N[0]||Q[i]>sumN)
                continue;
            if(Q[i]==sumN){
                res[i]=true;
                continue;
            }
            j=0;
            while(j<Nl && N[j]<=Q[i])
                j++;
            limit=(int)Math.pow(2, j);
            for(k=1;k<=limit;k++){
                arrbin=numToBool(k,Nl);
                temsum=0;
                for(l=0;l<Nl;l++){
                    if(arrbin[l])
                        temsum+=N[l];
                }
                if(temsum==Q[i]){
                    res[i]=true;
                    //System.out.println(temsum+": "+printbool(arrbin));
                    break;
                }
            }
        }
        for(i=0;i<Ql;i++){
            if(res[i]){
                System.out.println("YES");
            }else
                System.out.println("NO");
        }
    }
    private static boolean[] numToBool(int N,int lon){
        boolean tempArr[]=new boolean[lon];
        int i=0,base=N;
        while (N>0&&i<lon){
            if(N%2>0){
                tempArr[i]=true;
                N--;
            }
            N/=2;
            i++;
        }
        /*String st="";
        for(i=0;i<lon;i++){
            if(tempArr[i])
                st+="1";
            else
                st+="0";
        }
        System.out.println("numToBool("+base+") = "+st);*/
        return tempArr;
    }
}