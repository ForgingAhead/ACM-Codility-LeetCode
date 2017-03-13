class Solution {
    public int solution(int[] A) {

        int peaks[] = new int[A.length];
        int count=0;
        for(int i=1; i<A.length-1; i++){
            if(A[i]>A[i-1] && A[i]>A[i+1]){
                peaks[i] = ++count;
                i++;
            }
        }

        if(count<2) return count;

        int flag = count;
        int prior = 0;
        int distance;
        int toFlag;
        while(flag>0){
            distance = flag;
            toFlag = flag;
            prior=0;
            for(int i=1; i<A.length; i++){
                if(peaks[i]>0){
                    toFlag--; //assume this peak is eligible to flag.
                    if(prior==0) {prior = i;}
                    else {
                        if(i-prior < distance) {//by calculation, this peak not qualified to flag;
                            toFlag++;
                            if(count-peaks[i]<toFlag) {//not enough peaks to flag;
                                flag--;
                                break;
                            }
                        } else {// qualified peak for the flag
                            prior = i;
                        }
                    }
                    i++;
                }
                if(toFlag==0) return flag;
            }
        }
        return flag;
    }
}
